#include <iostream>
using namespace std;
const unsigned UPPER_LIMIT = 100;
const unsigned LOWER_LIMIT = 1;
const char JA = 'j';
const char KLEINER = 'k';
const char GROESSER = 'g';

int main() {
    cout << "Merken Sie sich eine Zahl zwischen 1 (inklusive) und 100 (exklusive) \n\n";
    unsigned zahlenRaten = 0, min = LOWER_LIMIT, max = UPPER_LIMIT;
    char userChoice = ' ';
    while(userChoice != JA){
        cout << "Aktueller Ratebereich: " << min << " bis " << max << endl;
        zahlenRaten = (min + max)/2;
        cout << "Ist " << zahlenRaten << " ihre Zahl?" << endl;
        cout << "(j) ja: gleich," << endl
             << "(k) nein: meine Zahl ist kleiner," << endl
             << "(g) nein: meine Zahl ist groesser." << endl << "? ";
        cin >> userChoice;
        switch (userChoice) {
            case KLEINER:
                max = zahlenRaten;
                break;
            case GROESSER:
                min = zahlenRaten;
                break;
        }
    }
    return 0;
}
