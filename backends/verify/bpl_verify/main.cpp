/*
Copyright 2013-present Barefoot Networks, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>
#include <string>
#include <iostream>

#include "lib/gc.h"
#include "lib/crash.h"
#include "backends/verify/translate/option.h"
#include "backends/verify/translate/version.h"

int main(int argc, char *const argv[]) {
    setup_gc_logging();
    setup_signals();

    AutoCompileContext autoP4VerifyContext(new P4VerifyContext);
    auto& options = P4VerifyContext::get().options();
    options.langVersion = CompilerOptions::FrontendVersion::P4_16;
    options.compilerVersion = P4VERIFY_VERSION_STRING;

    if (options.process(argc, argv) != nullptr) {
            if (options.loadIRFromJson == false)
                    options.setInputFile();
    }
    if (::errorCount() > 0)
        return 1;

    std::cout << "translate()" << std::endl;
    std::cout << "verify()" << std::endl;
    return 0;
}