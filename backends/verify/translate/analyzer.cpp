#include "analyzer.h"

Analyzer::Analyzer(){
	
}

void Analyzer::analyzeP4Program(const IR::P4Program *program){
	for(auto obj:program->objects){
		if(auto parser = obj->to<IR::P4Parser>()){
			analyzeP4Parser(parser);			
		}
	}
}

void Analyzer::analyzeP4Parser(const IR::P4Parser *p4Parser){
	std::cout << "parser" << std::endl;
	// The name & instance of each state
	std::map<cstring, const IR::ParserState*> parserStates;
	// The predcessors of each state
	std::map<cstring, std::vector<cstring>> preStates;
	// Headers that are extracted from *start* to the current state
	std::map<cstring, std::vector<std::vector<cstring>>> parserStatesHeaders;
	// Headers that are extracted locally in a state
	std::map<cstring, std::vector<cstring>> parserStatesLocalHeaders;
	// Record if a state is in the queue currently
	std::map<cstring, bool> inQueue;
	// Record if a state has enqueued once
	std::map<cstring, bool> visited;

	preStates["start"] = std::vector<cstring>(0);
	for(auto parserState:p4Parser->states){
		// initialization
		cstring stateName = parserState->name.toString();
		parserStates[stateName] = parserState;
		parserStatesHeaders[stateName] = std::vector<std::vector<cstring>>(0);
		
		// update the local headers added
		parserStatesLocalHeaders[stateName] = std::vector<cstring>(0);
		

		inQueue[stateName] = false;
		visited[stateName] = false;

		// update state's predcessors
		if (auto pathExpression = parserState->selectExpression->to<IR::PathExpression>()){
			cstring nextState = pathExpression->path->name.name;
			if(preStates.count(nextState) == 0) preStates[nextState] = std::vector<cstring>(0);
			preStates[nextState].push_back(stateName);
		}
		else if(auto selectExpression = parserState->selectExpression->to<IR::SelectExpression>()){
			for(auto selectCase:selectExpression->selectCases){
				cstring nextState = selectCase->state->path->name.name;
				if(preStates.count(nextState) == 0) preStates[nextState] = std::vector<cstring>(0);
				preStates[nextState].push_back(stateName);
			}
		}
		// std::cout << "state " << stateName << std::endl;
	}

	std::queue<const IR::ParserState*> queue;
	queue.push(parserStates["start"]);
	inQueue["start"] = true;
	visited["start"] = true;
	while(!queue.empty()){
		// show Queue
		int size = queue.size();
		std::cout << "Queue: ";
		while(size != 0){
			size--;
			const IR::ParserState* parserState = queue.front();
			cstring stateName = parserState->name.toString();
			std::cout << stateName << " ";
			queue.pop();
			queue.push(parserState);
		}
		std::cout << std::endl;


		const IR::ParserState* parserState = queue.front();
		cstring stateName = parserState->name.toString();
		queue.pop();
		inQueue[stateName] = false;

		/* 
			update the current state
			add successors to the queue only when the current state is updated
		*/
		int vecCountBefore = 0, vecLenBefore = 0;
		int vecCountAfter = 0, vecLenAfter = 0;
		vecCountBefore = parserStatesHeaders[stateName].size();
		for(std::vector<cstring> vec : parserStatesHeaders[stateName]){
			vecLenBefore += vec.size();
		}
		parserStatesHeaders[stateName] = std::vector<std::vector<cstring>>(0);
		for(cstring pred : preStates[stateName]){
			parserStatesHeaders[stateName].insert(parserStatesHeaders[stateName].end(),
				parserStatesHeaders[pred].begin(), parserStatesHeaders[pred].end());
		}
		vecCountAfter = parserStatesHeaders[stateName].size();
		for(std::vector<cstring> vec : parserStatesHeaders[stateName]){
			vecLenAfter += vec.size();
		}

		// if no update, continue
		bool noChange = (vecCountBefore==vecCountAfter && vecLenBefore==vecLenAfter);

		// Add next state (transition statement)
		if (auto pathExpression = parserState->selectExpression->to<IR::PathExpression>()){
			cstring nextState = pathExpression->path->name.name;
			if(!inQueue[nextState] && !(noChange && visited[nextState])){
				queue.push(parserStates[nextState]);
				inQueue[nextState] = true;
				visited[nextState] = true;
			}
		}
		else if(auto selectExpression = parserState->selectExpression->to<IR::SelectExpression>()){
			for(auto selectCase:selectExpression->selectCases){
				cstring nextState = selectCase->state->path->name.name;
				if(!inQueue[nextState] && !(noChange && visited[nextState])){
					queue.push(parserStates[nextState]);
					inQueue[nextState] = true;
					visited[nextState] = true;
				}
			}
		}
	}
}