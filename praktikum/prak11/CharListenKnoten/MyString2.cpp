//
// Created by dat tran on 19.04.21.
//

#include "MyString2.h"

MyString2::MyString2(std::string s) {
    this->anker = nullptr;
    if(s.empty()){

    }else{
        for(int i = 0; i < s.size(); i++){
            hinten_anfuegen(this->anker,s[i]);
        }
    }
}

MyString2::MyString2(const MyString2& orig) {
    this->anker = deep_copy(orig.get_anker());
}

MyString2& MyString2::operator=(const MyString2& orig){
    loesche_alle(MyString2::anker);
    MyString2::anker = deep_copy(orig.get_anker());
    return *this;
}

unsigned int MyString2::length() const{
    int len = 0;
    CharListenKnoten* tmp = anker;
    while(tmp != nullptr){
        len++;
        tmp = tmp->get_next();
    }
    return len;
}

char MyString2::at(unsigned int pos)const{
    if(pos >= this->length() || this->anker == nullptr)
        return '\0';
    else{
        CharListenKnoten* tmp = this->anker;
        while((tmp->get_my_id()-anker->get_my_id()) < pos){
            tmp = tmp->get_next();
        }
        return tmp->get_data();
    }
}

std::string MyString2::to_string() const {
    std::string result = "";
    CharListenKnoten* tmp = anker;
    while(tmp != nullptr){
        result += tmp->get_data();
        tmp = tmp->get_next();
    }
    return result;
}

MyString2 MyString2::operator+(const char c) const {
    MyString2 result = *this;
    hinten_anfuegen(result.anker, c);
    return result;
}