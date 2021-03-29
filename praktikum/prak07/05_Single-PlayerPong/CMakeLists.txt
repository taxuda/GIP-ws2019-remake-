cmake_minimum_required(VERSION 3.17)
project(05_Single_PlayerPong)

set(CMAKE_CXX_STANDARD 14)

include_directories(AFTER "/usr/X11R6/include")

add_link_options(-lm -lpthread -L/usr/X11R6/lib -lX11)

add_executable(05_Single_PlayerPong main.cpp CImgGIP05.h)