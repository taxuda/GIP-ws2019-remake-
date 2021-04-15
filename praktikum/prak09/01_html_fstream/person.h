//
// Created by dat tran on 15.04.21.
//

#ifndef INC_01_HTML_FSTREAM_PERSON_H
#define INC_01_HTML_FSTREAM_PERSON_H
#include <string>
#include "text.h"

struct Person{
    std::string last_name, first_name, birthday;
};
struct Person extract_person(std::string input_line);
void split_from_first_character(std::string line,
                                char character,
                                std::string& head, std::string &tail);

#endif //INC_01_HTML_FSTREAM_PERSON_H
