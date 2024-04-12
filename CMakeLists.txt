cmake_minimum_required(VERSION 3.8.0)
project(kgm-unblock-lib VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_library(kgm-unblock-lib SHARED src/kgm.cpp)

add_executable(decrypt src/kgm.cpp test/decrypt.cpp)
# target_link_libraries(decrypt kgm-unblock-lib)

add_test(NAME decrypt COMMAND decrypt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
