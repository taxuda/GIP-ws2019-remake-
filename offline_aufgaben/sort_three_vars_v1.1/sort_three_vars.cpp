//
// Created by dat tran on 17.03.21.
//
#include "sort_three_vars.h"
#include <string>
using namespace std;

// definition
template <typename T>
void swap_vars (T& x1, T& x2){
    // T& help = x1;
    T help = x1;
    x1 = x2;
    x2 = help;
}

template<class T>
void sort_three_vars(T &first, T &second, T &third) {
    // insertion sort
    if(first > second) swap_vars<T>(first, second); // explicit instantiation when first called
    if(first > third) swap_vars<T>(first, third);
    if(second > third) swap_vars<T>(second, third);
}

// explicit instantiation for int and string
// require explicit instantiation of swap_vars() for int and string
// see swap_vars.cpp
template void sort_three_vars<int>(int& first, int& second, int& third);
template void sort_three_vars<string>(string& first, string& second, string& third);