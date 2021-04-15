//
// Created by dat tran on 15.04.21.
//
#include "person.h"
void split_from_first_character(std::string line, char ch, std::string &head, std::string &tail){
    int index = 0;
    while(index < line.length()){
        if(line[index] == ch){
            break;
        }else{
            head += line[index];
            index++;
        }
    }
    // index += 2; // bo qua: ", "
    // Musterfrau, Petra, 1.1.1981: "Musterfrau" ", " "Petra, 1.1.1981"
    // "Petra, 1.1.1981": "Petra" ", " "1.1.1981"

    while(index < line.size()){
        tail += line[index];
        index++;
    }
}
struct Person extract_person(std::string input_line){
    Person p{"","",""};
    std::string rest;
    split_from_first_character(input_line,',',p.last_name, rest);
    rest = trimm(rest);
    split_from_first_character(rest,',',p.first_name,p.birthday);
    p.birthday = trimm(p.birthday);
    return p;
}
