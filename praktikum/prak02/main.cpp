#include <iostream>
using namespace std;
const int CELSIUS_IN_FAHRENHEIT = 1;
const int METER_IN_FUSS = 2;
const int EURO_IN_US_DOLLAR = 3;
int main() {
    double eingabe = 0;
    int auswahl = 0;

    // Eingabe..
    cout << "Ihre Eingabe: ? ";
    cin >> eingabe;
    cout << "Ihre Auswahl der Umwandlung:" << endl;
    cout << " 1 - Celsius in Fahrenheit" << endl;
    cout << " 2 - Meter in Fuss" << endl;
    cout << " 3 - Euro in Us Dollar" << endl;
    do {
        cin >> auswahl;
    } while (auswahl > 3 || auswahl < 1);

    // Auswahl und Umrechnung..
    switch (auswahl) {
        case 0:
            cout << "Das Ergebnis lautet: ";
        case CELSIUS_IN_FAHRENHEIT:
            cout << eingabe*1.8 + 32 << endl;
            break;
        case METER_IN_FUSS:
            cout << eingabe*3.2808 << endl;
            break;
        case EURO_IN_US_DOLLAR:
            cout << eingabe*1.2957 << endl;
    }

    char buchtabe = ' ';
    do {
        cout << "Bitte geben Sie den Buchstaben ein: ? ";
        cin >> buchtabe;
    } while (buchtabe < 'a' || buchtabe > 'z');
    cout << "Der Buchstabe " << buchtabe
         << " hat die Position "<< int(buchtabe - 'a') + 1
         << " im Alphabet." << endl;
    return 0;
}
