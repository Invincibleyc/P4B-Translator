#include <getopt.h>
#include "frontends/common/options.h"

class P4VerifyOptions : public CompilerOptions {
 public:
    bool translateOnly = false;
    bool loadIRFromJson = false;
    P4VerifyOptions() {
        registerOption("--translate-only", nullptr,
                       [this](const char*) {
                           translateOnly = true;
                           return true; },
                       "only translate the P4 input into Boogie program");
        registerOption("--fromJSON", "file",
                       [this](const char* arg) {
                           loadIRFromJson = true;
                           file = arg;
                           return true;
                       },
                       "read previously dumped json instead of P4 source code");
    }
};

using P4VerifyContext = P4CContextWithOptions<P4VerifyOptions>;