//
// Created by dat tran on 26.03.21.
//
#include "bildschirm.h"
void ausgabe(string text, int pos){
    cout << text << endl;
    if(pos > 0 && pos < text.size()){
        for(int i = 0; i < pos;i++){
            cout << " ";
        }
        cout << "*" << endl;
    }else if(!pos){ // pos == 0
        cout << "*" << endl;
    }

}
char eingabe(){
    char befehl = ' ';
    do {
        cout << "Befehl (l: links, r: rechts, s: spiegeln, q: Ende) ?- ";
        cin >> befehl;
    }while(befehl != LINKS && befehl != RECHTS && befehl != SPIEGELN && befehl != ENDE);
    return befehl;
}
