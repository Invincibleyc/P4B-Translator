# Copyright 2013-present Barefoot Networks, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/translate/version.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/translate/version.h" @ONLY)

set (P4VERIFY_BACKEND_VERIFY_SRCS
  bpl_verify/main.cpp
)
add_cpplint_files (${CMAKE_CURRENT_SOURCE_DIR} "${P4VERIFY_BACKEND_VERIFY_SRCS}")

set (P4VERIFY_BACKEND_TRANSLATE_SRCS
  translate/options.h
  translate/translate.h
  translate/translate.cpp
  translate/analyzer.h
  translate/analyzer.cpp
  translate/boogie_procedure.h
  translate/boogie_procedure.cpp
  translate/boogie_statement.h
  translate/boogie_statement.cpp
  translate/bmv2.h
  translate/bmv2.cpp
)
add_cpplint_files (${CMAKE_CURRENT_SOURCE_DIR} "${P4VERIFY_BACKEND_TRANSLATE_SRCS}")


build_unified(P4VERIFY_BACKEND_TRANSLATE_SRCS)
add_library(verifybackend ${P4VERIFY_BACKEND_TRANSLATE_SRCS})
add_dependencies(verifybackend genIR frontend)

build_unified(P4VERIFY_BACKEND_VERIFY_SRCS)
add_executable(p4c-translator ${P4VERIFY_BACKEND_VERIFY_SRCS})
target_link_libraries (p4c-translator verifybackend ${P4C_LIBRARIES} ${P4C_LIB_DEPS})


install(TARGETS p4c-translator RUNTIME DESTINATION ${P4C_RUNTIME_OUTPUT_DIRECTORY})

file(RELATIVE_PATH
  CURRENT_BINARY_DIR_PATH_REL
  ${P4C_BINARY_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

file(RELATIVE_PATH
  P4C_BINARY_DIR_PATH_REL
  ${CMAKE_CURRENT_BINARY_DIR}
  ${P4C_BINARY_DIR}
)

add_custom_target(linkp4verify
  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CURRENT_BINARY_DIR_PATH_REL}/p4c-translator ${P4C_BINARY_DIR}/p4c-translator
  COMMAND ${CMAKE_COMMAND} -E create_symlink ${P4C_BINARY_DIR_PATH_REL}/p4include ${CMAKE_CURRENT_BINARY_DIR}/p4include
  COMMAND ${CMAKE_COMMAND} -E create_symlink ${P4C_BINARY_DIR_PATH_REL}/p4_14include ${CMAKE_CURRENT_BINARY_DIR}/p4_14include
  )

add_dependencies(p4c_driver linkp4verify)