cmake_minimum_required(VERSION 3.6)

project(megahal)

set(SOURCE_FILES
	src/main.cpp
	src/megahal.h src/megahal.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})


if(MSVC)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g")
	set(CMAKE_CXX_FLAGS_DEBUG "-O0")
	set(CMAKE_CXX_FLAGS_RELEASE "-Os")
endif()
