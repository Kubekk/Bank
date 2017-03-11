cmake_minimum_required(VERSION 3.6)
project(Bank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BankDeposit.cpp BankDeposit.h)
add_executable(Bank ${SOURCE_FILES})