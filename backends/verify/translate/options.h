#include <getopt.h>
#include "frontends/common/options.h"

class P4VerifyOptions : public CompilerOptions {
 public:
    bool translateOnly = false;
    bool addassertion = false;
    bool loadIRFromJson = false;
    cstring outputBplFile = nullptr;
    P4VerifyOptions() {
        registerOption("--translate-only", nullptr,
                       [this](const char*) {
                           translateOnly = true;
                           return true; },
                       "only translate the P4 input into Boogie program");
        registerOption("-o", "outfile",
                      [this](const char* arg) { outputBplFile = arg; return true; },
                      "Write translation result to outfile");
        registerOption("--fromJSON", "file",
                       [this](const char* arg) {
                           loadIRFromJson = true;
                           file = arg;
                           return true;
                       },
                       "read previously dumped json instead of P4 source code");
        registerOption("--assert", nullptr,
                       [this](const char*) {
                           addassertion = true;
                           return true; },
                       "add assertions for header accessing");
    }
};

using P4VerifyContext = P4CContextWithOptions<P4VerifyOptions>;