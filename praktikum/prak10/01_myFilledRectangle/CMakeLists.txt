cmake_minimum_required(VERSION 3.19)
project(01_myFilledRectangle)

set(CMAKE_CXX_STANDARD 14)

include_directories(AFTER "/usr/X11R6/include")

add_link_options(-lm -lpthread -L/usr/X11R6/lib -lX11)

add_executable(01_myFilledRectangle main.cpp CImgGIP05.h MyRectangle.h MyRectangle.cpp MyFilledRectangle.cpp MyFilledRectangle.h)