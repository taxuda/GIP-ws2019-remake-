//
// Created by dat tran on 19.04.21.
//

#include "CharListenKnoten.h"
// initialize
int CharListenKnoten::next_available_id = 1;
int CharListenKnoten::object_count = 0;


void hinten_anfuegen(CharListenKnoten*& anker, const char wert){
    CharListenKnoten* newKnoten = new CharListenKnoten(wert);
    if(anker == nullptr)
        anker = newKnoten;
    else{
        CharListenKnoten* tmp = anker;

        while(tmp->get_next() != nullptr)
            tmp = tmp->get_next();

        tmp->set_next(newKnoten);
    }
}

void loesche_alle(CharListenKnoten*& anker){
    if(anker == nullptr) return;
    else{
        CharListenKnoten* tmp = anker;
        while(tmp != nullptr){
            CharListenKnoten* tmp_next = tmp->get_next();
            delete tmp;
            tmp = tmp_next;
        }
        anker = nullptr;
    }
}

CharListenKnoten* deep_copy(const CharListenKnoten* orig){
    if(orig == nullptr) return nullptr;

    CharListenKnoten* anker = new CharListenKnoten(orig->get_data());
    CharListenKnoten* tmp = anker;
    while(orig->get_next() != nullptr){
        CharListenKnoten* newKnoten = new CharListenKnoten(orig->get_next()->get_data());
        tmp->set_next(newKnoten);
        tmp = tmp->get_next();
        orig = orig->get_next();
    }
    return anker;
}