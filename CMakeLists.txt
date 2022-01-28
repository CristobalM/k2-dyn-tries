cmake_minimum_required(VERSION 3.14)
project(k2tree-dyn)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


set(SOURCES_REQUIRED
treeBlock.cpp
treeBlock.h
K2TreeDarroyAdapter.cpp
K2TreeDarroyAdapter.h
MortonCode.cpp
MortonCode.h
)


set(SOURCES 
${SOURCES_REQUIRED}
)

add_executable(testUsage1 testUsage1.cpp ${SOURCES})
add_executable(benchmark1 benchmark1.cpp ${SOURCES})
add_executable(benchmark1-as benchmark1.cpp ${SOURCES})
target_compile_options(benchmark1-as PRIVATE -save-temps=obj)