cmake_minimum_required(VERSION 3.19)
project(CharListenKnoten)

set(CMAKE_CXX_STANDARD 14)

add_executable(CharListenKnoten main.cpp catch.h
        CharListenKnoten.cpp CharListenKnoten.h test_charlistenknoten.cpp
        test_charlistenknoten_id.cpp test_charlistenknoten_count.cpp test_hinten_anfuegen.cpp
        test_loesche_alle.cpp test_deep_copy.cpp MyString2.cpp MyString2.h
        test_mystring2_step_1.cpp test_mystring2_destruktor.cpp
        test_mystring2_from_string.cpp
        test_mystring2_copy_assignment.cpp test_mystring2_length.cpp
        test_mystring2_at.cpp test_mystring2_to_string.cpp
        test_mystring2_operator_plus.cpp)