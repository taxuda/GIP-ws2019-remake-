cmake_minimum_required(VERSION 3.19)
project(02_conways_game_of_life)

set(CMAKE_CXX_STANDARD 14)

include_directories(AFTER "/usr/X11R6/include")

add_link_options(-lm -lpthread -L/usr/X11R6/lib -lX11)

add_executable(02_conways_game_of_life main.cpp CImgGIP05.h)