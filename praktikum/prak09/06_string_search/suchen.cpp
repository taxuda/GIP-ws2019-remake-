//
// Created by dat tran on 19.04.21.
//

#include "suchen.h"
#include "myCstrings.h"

int zeichenkette_suchen(const char* text, const char* zkette){
    int text_len = myStrlen(text);
    int zkette_len = myStrlen(zkette);

    if(text_len == 0) // empty text
        return -1;

    for(int i = 0; i < text_len; i++){
        if(text[i] == *zkette){// first character matched
            if(zkette_len == 1) return i;

            // matching from second character
            for(int it = i + 1, iz = 1; it < text_len && iz < zkette_len; it++, iz++){
                if(text[it] != zkette[iz])
                    break;
                if(iz == zkette_len - 1)
                    return i;
            }
        }
    }
    return -1;
}