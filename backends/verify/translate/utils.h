#ifndef BACKENDS_VERIFY_TRANSLATE_UTILS_H_ 
#define BACKENDS_VERIFY_TRANSLATE_UTILS_H_

#include "lib/cstring.h"

bool isNumber(std::string str);

bool isNumber(cstring str);

// xxx is same as (xxx_ + number), i.e., renaming
bool isSame(std::string s1, std::string s2);

bool isSame(cstring s1, cstring s2);

#endif