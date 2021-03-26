//
// Created by dat tran on 26.03.21.
//
#include "wortfunktionen.h"
void wortspiegel(string &text, int pos){
    // only process when it's a letter
    if(!isBuchstabe(text[pos])) return;

    // word end at
    int end = pos;
    while(end + 1 < text.size() && isBuchstabe(text[end + 1])){
        end++;
    }

    int start = pos;
    // word begin at
    while(start - 1 >= 0 && isBuchstabe(text[start - 1])){
        start--;
    }

    int middleOfWord = (end - start) / 2 + start;
    for(int i = start, j = end; i <= middleOfWord && j > middleOfWord; i++, j--){
        char tmp = text[i];
        text[i] = text[j];
        text[j] = tmp;
    }
}

bool isValidPos(string text, int pos){
    return (pos >= 0 && pos < text.size());
}

bool isBuchstabe(char zeichen){
    return (zeichen >= 'a' && zeichen <= 'z') || (zeichen >= 'A' && zeichen <= 'Z');
}