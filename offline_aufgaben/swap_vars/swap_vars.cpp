#include <__bit_reference>
//
// Created by dat tran on 16.03.21.
//

#include "swap_vars.h"
#include <string>

using namespace std;

template <typename T>
void swap_vars (T& x1, T& x2){
    // T& help = x1;
    T help = x1;
    x1 = x2;
    x2 = help;
}

// explicit Instantiation

// c++ complete guide
// template void swap_vars(int& x1, int& x2);

// lecture gip
template void swap_vars<int>(int& x1, int& x2);

template void swap_vars<string>(string& x1, string& x2);