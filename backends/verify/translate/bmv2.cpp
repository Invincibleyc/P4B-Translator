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
	while(idx2 != std::string::npos){
		res.push_back(str.substr(idx1, idx2-idx1));
		idx1 = idx2+1;
		idx2 = str.find(" ", idx1);
	}
	if(idx1 != str.length()){
		res.push_back(str.substr(idx1));
	}
	return res;
}

cstring BMV2Cmd::splitFirst(std::string str){
	std::string::size_type idx = str.find(" ");
	return str.substr(0, idx);
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
}