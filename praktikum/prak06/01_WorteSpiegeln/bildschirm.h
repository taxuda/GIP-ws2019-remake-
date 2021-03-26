//
// Created by dat tran on 26.03.21.
//

#ifndef INC_03_WUERFELN_BILDSCHIRM_H
#define INC_03_WUERFELN_BILDSCHIRM_H
#include <string>
#include <iostream>
using namespace std;

const char LINKS = 'l';
const char RECHTS = 'r';
const char SPIEGELN = 's';
const char ENDE = 'q';

void ausgabe(string text, int pos);
char eingabe();

#endif //INC_03_WUERFELN_BILDSCHIRM_H
