# Install script for directory: /media/yec/WORK/Programs/P4-verification/P4B-Translator

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RELEASE")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/p4c" TYPE DIRECTORY FILES "/media/yec/WORK/Programs/P4-verification/P4B-Translator/p4include" FILES_MATCHING REGEX "/[^/]*\\.p4$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/driver/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/lib/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/tools/ir-generator/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/ir/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/backends/dpdk/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/frontends/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/midend/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/control-plane/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/backends/bmv2/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/backends/ebpf/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/backends/ubpf/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/backends/p4test/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/backends/verify/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/backends/graphs/cmake_install.cmake")
  include("/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/media/yec/WORK/Programs/P4-verification/P4B-Translator/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
