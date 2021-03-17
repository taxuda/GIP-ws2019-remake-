//
// Created by dat tran on 17.03.21.
//
#include "sort_three_vars.h"
#include <string>
using namespace std;

// definition
template<class T>
void sort_three_vars(T &first, T &second, T &third) {
    // insertion sort
    if(first > second) swap_vars(first, second);
    if(first > third) swap_vars(first, third);
    if(second > third) swap_vars(second, third);
}

// explicit instantiation for int and string
// require explicit instantiation of swap_vars() for int and string
// see swap_vars.cpp
template void sort_three_vars<int>(int& first, int& second, int& third);
template void sort_three_vars<string>(string& first, string& second, string& third);