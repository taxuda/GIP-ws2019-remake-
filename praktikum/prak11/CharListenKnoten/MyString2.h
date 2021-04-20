//
// Created by dat tran on 19.04.21.
//

#ifndef CHARLISTENKNOTEN_MYSTRING2_H
#define CHARLISTENKNOTEN_MYSTRING2_H
#include "CharListenKnoten.h"
#include <string>

class MyString2 {
private:
    CharListenKnoten* anker;
public:
    MyString2():anker{nullptr}{}
    MyString2(std::string s);
    MyString2(const MyString2& orig);
    MyString2& operator = (const MyString2& orig);
    MyString2 operator + (const char c) const;
    ~MyString2(){ loesche_alle(anker);}
    CharListenKnoten* get_anker() const{return anker;}
    void set_anker(CharListenKnoten* ptr){anker = ptr;}
    unsigned int length() const;
    char at(unsigned int pos) const;
    std::string to_string() const;
};


#endif //CHARLISTENKNOTEN_MYSTRING2_H
