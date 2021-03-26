cmake_minimum_required(VERSION 3.17)
project(01_WorteSpiegeln)

set(CMAKE_CXX_STANDARD 14)

add_executable(01_WorteSpiegeln wortspiegel_main.cpp catch.h test_wortfunktionen.cpp wortfunktionen.h wortfunktionen.cpp bildschirm.h bildschirm.cpp)