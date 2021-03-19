//--------------------------
// Autor: Tran Xuan Dat
// Übung: GIP-INF_Uebung_2020-11-20
//--------------------------
#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
// !ACHTUNG
//#include "rechnung_erstellen.h"
using namespace std;

// !ACHTUNG
extern unsigned int rechnungErstellen(unsigned int auftragssummer);

int main() {
    int result = Catch::Session().run();
    unsigned int auftragsumme = 0;
    do {
        cout << "Bitte geben Sie die Auftragssumme ein: ? ";
        cin >> auftragsumme;
        if(auftragsumme < 1){
            cout << "Auftragssumme groesser als 0!" << endl;
        }
    }while(auftragsumme < 1);
    rechnungErstellen(auftragsumme);
    return 0;
}
