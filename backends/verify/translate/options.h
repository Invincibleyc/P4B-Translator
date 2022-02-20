#ifndef BACKENDS_VERIFY_TRANSLATE_OPTIONS_H_
#define BACKENDS_VERIFY_TRANSLATE_OPTIONS_H_

#include <getopt.h>
#include "frontends/common/options.h"

class P4VerifyOptions : public CompilerOptions {
 public:
    bool translateOnly = false;
    bool addValidityAssertion = false;
    bool addForwardingAssertion = false;
    bool addBoundAssertion = false;
    bool loadIRFromJson = false;
    bool whileLoop = false;
    bool havocStatefulElements = false;
    bool addInvariant = false;
    cstring outputBplFile = nullptr;
    bool bmv2cmds = false;
    cstring cmdFile = nullptr;

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
        registerOption("--bmv2cmds", "file",
                       [this](const char* arg) {
                           bmv2cmds = true;
                           cmdFile = arg;
                           return true;
                       },
                       "read static bmv2 CLI commands together with the P4 program");
        registerOption("--assert-validity", nullptr,
                       [this](const char*) {
                           addValidityAssertion = true;
                           return true; },
                       "add assertions for header accessing");
        registerOption("--assert-forward", nullptr,
                       [this](const char*) {
                           addForwardingAssertion = true;
                           return true; },
                       "add assertions for egress_spec assignment");
        registerOption("--assert-bound", nullptr,
                       [this](const char*) {
                           addBoundAssertion = true;
                           return true; },
                       "add assertions for header stack out-of-bounds");
        
        /*
          Options for invariant generation
        */
        registerOption("--whileloop", nullptr,
                       [this](const char*) {
                           whileLoop = true;
                           return true; },
                       "consider the P4 program as a while loop with condition TRUE");
        registerOption("--add-invariant", nullptr,
                       [this](const char*) {
                           addInvariant = true;
                           return true; },
                       "add invariant for the while loop");
        registerOption("--infer-inv", nullptr,
                       [this](const char*) {
                           whileLoop = true;
                           addInvariant = true;
                           return true; },
                       "add required components for infering invariants");
        
        /*
          Add havoc statements at the enter of the while loop
          Used to show the method of traditional tools
          The stateful elements have to be random (without invariants)
        */
        registerOption("--havoc-se", nullptr,
                       [this](const char*) {
                           havocStatefulElements = true;
                           return true; },
                       "havoc stateful elements (counter, register, meter)");
    }
};

using P4VerifyContext = P4CContextWithOptions<P4VerifyOptions>;

#endif