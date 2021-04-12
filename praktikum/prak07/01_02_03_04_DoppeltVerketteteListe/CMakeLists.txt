cmake_minimum_required(VERSION 3.17)
project(01_02_03_04_DoppeltVerketteteListe)

set(CMAKE_CXX_STANDARD 14)

add_executable(01_02_03_04_DoppeltVerketteteListe catch.h
        liste_main.cpp
        liste.cpp
        liste.h
        test_hinten_anfuegen.cpp
        test_liste_als_string_rueckwaerts.cpp
        test_in_liste_einfuegen.cpp
        test_aus_liste_loeschen.cpp)