#ifndef BACKENDS_VERIFY_TRANSLATE_UTILS_H_ 
#define BACKENDS_VERIFY_TRANSLATE_UTILS_H_

#include "lib/cstring.h"

bool isNumber(std::string str);

bool isNumber(cstring str);

// xxx is same as (xxx_ + number), i.e., renaming
bool isSame(std::string s1, std::string s2);

bool isSame(cstring s1, cstring s2);

const cstring TEMP_PREFIX = "$tmp$";

const cstring SPLIT = "$";

const int EGRESS_SPEC_SIZE = 9;

class TempVariable{
public:
	static int cnt;
	static int getCnt();
	static cstring getPrefix();
	static cstring getPrefix(cstring prefix);
};

#endif