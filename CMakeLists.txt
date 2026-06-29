cmake_minimum_required(VERSION 3.15)
project(llm_engine CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Sorgenti
add_executable(llm_engine 
    src/main.cpp 
    src/dequant.cpp
)