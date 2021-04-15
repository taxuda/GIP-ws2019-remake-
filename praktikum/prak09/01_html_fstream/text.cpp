//
// Created by dat tran on 15.04.21.
//

#include "text.h"

bool invalidChar(char ch){
    return ch == ' ' || ch == ',' || ch == '.' || ch == '\r';
}

std::string trimm(std::string s){
    std::string result ="";
    int begin = 0;
    while(invalidChar(s[begin])){
        begin++;
    }
    int end = s.size() - 1;
    while(invalidChar(s[end])){
        end--;
    }

    if( begin < s.size() && end >= 0){  // valid pos of begin-pos and end-pos
        for(int i = begin; i <= end; i++){
            result += s[i];
        }
    }
    return result;
}

std::string br(std::string s){
    s += "<br/>";
    return s;
}

std::string b(std::string s){
    std::string result = "";
    result += "<b>";
    result += s;
    result += "</b>";
    return result;
}

std::string replace(std::string text, char dim, std::string replacement){
    std::string result;
    bool is_done = false;
    for(int i = 0; i < text.size(); i++){
        if(!is_done && text[i] == dim){
            result += replacement;
            is_done = true;
        }else{
            result += text[i];
        }
    }
    return result;
}