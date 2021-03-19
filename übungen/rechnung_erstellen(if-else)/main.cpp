//--------------------------
// Autor: Tran Xuan Dat
// Übung: GIP-INF_Uebung_2020-11-20
//--------------------------
#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "rechnung_erstellen.h"
using namespace std;

int main() {
    int result = Catch::Session().run();
    int auftragsumme = 0;
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
