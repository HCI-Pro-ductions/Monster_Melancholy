cmake_minimum_required(VERSION 3.19)
project(MonsterMelancholy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(mongoc-1.0_DIR "C:/Program Files (x86)/Project/lib/cmake/mongoc-1.0")

find_package (mongoc-1.0 1.7 REQUIRED)
add_executable(MonsterMelancholy main.cpp MHGcombat.h MHGtextDisplay.h MHGsounds.h MHGdataHandle.h sha256.h sha256.cpp)
target_link_libraries (MonsterMelancholy PRIVATE mongo::mongoc_static)