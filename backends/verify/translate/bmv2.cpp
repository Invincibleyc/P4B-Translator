#include "bmv2.h"

BMV2CmdsAnalyzer::BMV2CmdsAnalyzer(std::ifstream* fin){
	std::string s;

	while(getline(*fin, s)){
		cstring label = BMV2Cmd::splitFirst(s);
		if(label == TABLE_ADD){
			std::cout << BMV2Cmd::splitFirst(s) << std::endl;
			BMV2Cmd* cmd = new TableAdd(s);
			cmds.push_back(cmd);
		}
		else if(label == TABLE_DELETE){

		}
		else if(label == TABLE_SET_DEFAULT){

		}
		else if(label == REGISTER_WRITE){
			std::cout << BMV2Cmd::splitFirst(s) << std::endl;
			BMV2Cmd* cmd = new RegisterWrite(s);
			cmds.push_back(cmd);
		}
		else{
			// std::cout << BMV2Cmd::splitFirst(s) << std::endl;
		}
		// std::cout << s << std::endl;
	}

	// char *line = NULL;
	// size_t len = 0;
	// ssize_t read;

	// while ((read = getline(&line, &len, fin)) != -1){
	// 	std::cout << s << std::endl;
	// 	BMV2Cmd* cmd;
	// 	printf("%s", line);
	// }
}

std::vector<cstring> BMV2Cmd::split(cstring str){
	return split(std::string(str.c_str()));
}

std::vector<cstring> BMV2Cmd::split(std::string str){
	std::vector<cstring> res;
	std::string::size_type idx1 = 0, idx2 = str.find(" ");

	// remove space
	while(str[idx1]==' '){
		idx1++;
	}
	idx2 = str.find(" ", idx1);

	while(idx2 != std::string::npos){
		res.push_back(str.substr(idx1, idx2-idx1));
		std::cout << "  push_back:  " << str.substr(idx1, idx2-idx1) << std::endl;
		idx1 = idx2+1;
		while(idx1 != str.length() && str[idx1]==' '){
			idx1++;
		}
		if(idx1 == str.length()){
			idx2 = std::string::npos;
		}
		else{
			idx2 = str.find(" ", idx1);
		}
	}

	if(idx1 != str.length()-1){
		res.push_back(str.substr(idx1));
		std::cout << "  push_back_rest:  " << str.substr(idx1) << std::endl;
	}

	return res;
}

cstring BMV2Cmd::splitFirst(std::string str){
	std::string::size_type idx1 = 0, idx2 = str.find(" ");
	while(str[idx1]==' '){
		idx1++;
	}
	idx2 = str.find(" ", idx1);
	return str.substr(idx1, idx2-idx1);
}

cstring BMV2Cmd::getName(std::string str){
	std::string::size_type idx = str.find(".");
	return str.substr(idx+1);
}

BMV2Cmd::BMV2Cmd(){}

BMV2Cmd::BMV2Cmd(cstring _cont){
	cont = _cont;
	cmdType = NAME_BMV2_CMD;
}

TableAdd::TableAdd(cstring _cont){
	cont = _cont;
	cmdType = NAME_TABLE_ADD;
	std::vector<cstring> vec = split(_cont);
	table = getName(vec[1].c_str());
	action = getName(vec[2].c_str());

	int idx = 3;
	while(idx < cont.size() && vec[idx] != TABLE_MATCH_SYMBOL) idx++;

	if(idx == cont.size()){
		std::cerr << "ERROR_INFO: " << cont << std::endl;
		throw "ERROR: Illegal table_add command!!!\nUsage: table_add <table name> <action name> <match fields> => <action parameters> [priority]";
	}

	// std::cout << "  fields:" << std::endl;
	for(int i = 3; i < idx; i++){
		fields.push_back(vec[i]);
		// std::cout << "    " << vec[i] << std::endl;
	}

	// std::cout << "  parameters:" << std::endl;
	int size = vec.size();
	for(int i = idx+1; i < size; i++){
		parameters.push_back(vec[i]);
		// std::cout << "    " << vec[i] << std::endl;
	}

	// std::cout << table << std::endl;
	// std::cout << action << std::endl;
}

TableDelete::TableDelete(cstring _cont){
	cont = _cont;
	cmdType = NAME_TABLE_DELETE;
	std::vector<cstring> vec = split(_cont);
}

TableSetDefault::TableSetDefault(cstring _cont){
	cont = _cont;
	cmdType = NAME_TABLE_SET_DEFAULT;
	std::vector<cstring> vec = split(_cont);
}

RegisterWrite::RegisterWrite(cstring _cont){
	cont = _cont;
	cmdType = NAME_REGISTER_WRITE;
	std::vector<cstring> vec = split(_cont);
	if(vec.size() != 4){
        std::cerr << "ERROR_INFO: " << cont << std::endl;
		throw "ERROR: Illegal register_write command!!!\nUsage: register_write <name> <index> <value>";
	}
	reg = getName(vec[1].c_str());
	index = vec[2];
	value = vec[3];
}