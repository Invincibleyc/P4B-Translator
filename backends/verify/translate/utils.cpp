#include "utils.h"

bool isNumber(std::string str){
	int size = str.size();
	for(int i = 0; i < size; i++){
		if(!('0' <= str[i] && str[i] <= '9')){
			return false;
		}
	}
	return true;
}

bool isNumber(cstring str){
	return isNumber(std::string(str.c_str()));
}

bool isSame(std::string s1, std::string s2){
	if(s1.size() < s2.size()){
		cstring tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	if(s1 == s2){
		return true;
	}
	else if(s1.find(s2) != std::string::npos){
		std::string::size_type idx = s1.find(s2+"_") + s2.size() + 1;
		if(isNumber(s1.substr(idx)))
			return true;
	}
	return false;
}

bool isSame(cstring s1, cstring s2){
	if(s1.size() < s2.size()){
		cstring tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	if(s1 == s2){
		return true;
	}
	else if(s1.find(s2) != nullptr){
		std::string s = s1.c_str();
    	std::string::size_type idx = s.find((s2+"_").c_str()) + 
    		    						s2.size()+1;
		if(isNumber(s.substr(idx))){
			return true;
		}
	}
	return false;
}

int TempVariable::cnt = 0;

int TempVariable::getCnt(){
	return cnt++;
}

cstring TempVariable::getPrefix(){
	std::stringstream ss;
    ss << getCnt();
    return TEMP_PREFIX+ss.str();
}