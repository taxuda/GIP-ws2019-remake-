//
// Created by dat tran on 19.04.21.
//

#include "myCstrings.h"
unsigned int myStrlen(const char* s){
    unsigned len = 0;
    while(*s != '\0'){
        len++;
        s++;
    }
    return len;
}