#include <iostream>
using namespace std;
int buchstabeInEinstelligGanzahlWert(char buchstabe);
int buchstabeInEinstelligGanzahlWert(char buchstabe){
    return int(buchstabe - '0');
}
int main(){
    char ersteBuchtabe = ' ', zweiteBuchtabe = ' ';

    cout << "Bitte geben Sie die erste Ziffer ein: ? ";
    cin >> ersteBuchtabe;
    cout << "Bitte geben Sie die zweite Ziffer ein: ? ";
    cin >> zweiteBuchtabe;
    /*
    cout << "Der erste eingegebene Buchstabe lautet: " << ersteBuchtabe << endl;
    cout << "Der zweite eingegebene Buchtabe lautet: " << zweiteBuchtabe << endl;
    */
    /*
    if(ersteBuchtabe >= '0' && ersteBuchtabe <= '9'){
        cout << "Der Buchstabe " << ersteBuchtabe
             << " wurder jetzt in den Ganzzahl-Wert "
             << buchstabeInEinstelligGanzahlWert(ersteBuchtabe)
             << " umgerechnet." << endl;
    }

    if (zweiteBuchtabe >= '0' && zweiteBuchtabe <= '9') {
        cout << "Der Buchstabe " << zweiteBuchtabe
             << " wurder jetzt in den Ganzzahl-Wert "
             << buchstabeInEinstelligGanzahlWert(zweiteBuchtabe)
             << " umgerechnet." << endl;
    }
    */
    if(ersteBuchtabe >= '0' && ersteBuchtabe <= '9'
        && zweiteBuchtabe >= '0' && zweiteBuchtabe <= '9'){
        int ersteZahl = buchstabeInEinstelligGanzahlWert(ersteBuchtabe);
        int zweiteZahl = buchstabeInEinstelligGanzahlWert(zweiteBuchtabe);
        cout << ersteZahl << " + " << zweiteZahl << " = " << ersteZahl + zweiteZahl << endl;
    }
    if(ersteBuchtabe == 'q' || zweiteBuchtabe == 'q'){
        cout << "Das Programm wurde durch Eingabe von q beendet." << endl;
        return 1;
    }
    return 0;
}
