//
// Created by dat tran on 19.04.21.
//

#ifndef CHARLISTENKNOTEN_CHARLISTENKNOTEN_H
#define CHARLISTENKNOTEN_CHARLISTENKNOTEN_H


class CharListenKnoten {
private:
    char data;
    CharListenKnoten* next;
    int my_id;
public:
    CharListenKnoten(char d, CharListenKnoten* n = nullptr):data{d}, next{n}, my_id{next_available_id++}{
        object_count++;
    }
    ~CharListenKnoten(){
        object_count--;
    }
    char get_data()const{return data;}
    CharListenKnoten* get_next()const{return next;}
    void set_data(char d){data = d;}
    void set_next(CharListenKnoten* n){next = n;}
    // static attribute
    static int next_available_id;
    static int object_count;
    int get_my_id()const{return my_id;}
};


void hinten_anfuegen(CharListenKnoten*& anker, const char wert);
void loesche_alle(CharListenKnoten*& anker);
CharListenKnoten* deep_copy(const CharListenKnoten* orig);
#endif //CHARLISTENKNOTEN_CHARLISTENKNOTEN_H
