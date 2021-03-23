#include <iostream>
using namespace std;

int main() {
    // Eingabe...
    int gesamtZahlVonAefel;
    cout << "Bitte geben Sie die Gesamtzahl Aefel ein: ? ";
    cin >> gesamtZahlVonAefel;

    // Tabelleüberschrigft
    cout << "Runde   Willi   Hans   Rest" << endl;

    const int willi_hunger = 5;
    const int hans_hunger = 4;

    unsigned int willi_gegessen = 0, hans_gegessen = 0;
    unsigned int essRunden = 1;

    while(gesamtZahlVonAefel > 0){
        willi_gegessen += willi_hunger;
        hans_gegessen += hans_hunger;
        gesamtZahlVonAefel -= (willi_hunger+hans_hunger);
        cout << essRunden++ << "\t\t" << willi_gegessen << "\t\t" << hans_gegessen << "\t\t" << gesamtZahlVonAefel << endl;
    }
    return 0;
}
