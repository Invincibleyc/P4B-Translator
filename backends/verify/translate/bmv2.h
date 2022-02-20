#ifndef BACKENDS_VERIFY_TRANSLATE_BMV2_H_ 
#define BACKENDS_VERIFY_TRANSLATE_BMV2_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "lib/cstring.h"
#include "utils.h"

/* 
  used to analyze bmv2 commands (CLI style)
  
  cite:
 	https://github.com/p4lang/behavioral-model/blob/main/tools/runtime_CLI.py
  
  supported commands:
    * table_add <table name> <action name> <match fields> => <action parameters> [priority]
    * table_set_default <table name> <action name> <action parameters>
    * register_write <name> <index> <value>
*/

const cstring TABLE_ADD = "table_add";
const cstring TABLE_DELETE = "table_delete";
const cstring TABLE_SET_DEFAULT = "table_set_dfault";
const cstring REGISTER_WRITE = "register_write";

const cstring NAME_BMV2_CMD = "BMV2Cmd";
const cstring NAME_TABLE_ADD = "TableAdd";
const cstring NAME_TABLE_DELETE = "TableDelete";
const cstring NAME_TABLE_SET_DEFAULT = "TableSetDefault";
const cstring NAME_REGISTER_WRITE = "RegisterWrite";

const cstring TABLE_MATCH_SYMBOL = "=>";

class BMV2Cmd{
public:
	BMV2Cmd();
	BMV2Cmd(cstring _cont);
	cstring cont;
	cstring cmdType;
	static std::vector<cstring> split(std::string str);
	static std::vector<cstring> split(cstring str);
	static cstring splitFirst(std::string str);
	static cstring getName(std::string str); // obj.xxx, return xxx
	static cstring getControl(std::string str); // obj.xxx, return obj
};

// table_add
class TableAdd : public BMV2Cmd{
public:
	TableAdd(cstring _cont);
	cstring control;  // may be null
	cstring table;
	cstring action;
	std::vector<cstring> fields;
	std::vector<cstring> parameters;  // the last one may be the priority
};

// table_delete
class TableDelete : public BMV2Cmd{
public:
	TableDelete(cstring _cont);
};

// table_set_default
class TableSetDefault : public BMV2Cmd{
public:
	TableSetDefault(cstring _cont);
	cstring control;  // may be null
	cstring table;
	cstring action;
	std::vector<cstring> parameters;
};

// register_write
class RegisterWrite : public BMV2Cmd{
public:
	RegisterWrite(cstring _cont);
	cstring control;  // may be null
	cstring reg;  // register
	cstring index;
	cstring value;
};

class BMV2CmdsAnalyzer{
public:
	BMV2CmdsAnalyzer(std::ifstream* fin);
	std::vector<BMV2Cmd*> cmds;

	void analyzeBMV2Commands();
	void analyzeSingleCommand();
	std::vector<TableAdd*> getTableAddCmds(cstring table);
	bool hasTableAddCmds(cstring table);
	// std::vector<TableDelete*> getTableDeleteCmds();
};


#endif