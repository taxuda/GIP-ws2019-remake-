#include <iostream>
#include <string>
using namespace std;

const unsigned ALPHABET_SIZE = unsigned ('z') - unsigned ('a') + 1; // 26

bool isBuchstabe(char zeichen){

    return (zeichen >= 'a' && zeichen <= 'z') || (zeichen >= 'A' && zeichen <= 'Z');
}

char verschieben(char buchstabe, unsigned anzahlVerschiebenPosition){

    char neuBuchstabe = buchstabe + anzahlVerschiebenPosition;

    if(!isBuchstabe(neuBuchstabe)){
        neuBuchstabe -= ALPHABET_SIZE;
    }

    return neuBuchstabe;
}

int main() {

    string s;
    unsigned key;

    // Eingabe..
    cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
    getline(cin, s);

    cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl): ";
    cin >> key;

    // Anzahl mögliche Verschiebepositionen
    unsigned anzahlVerschiebenPosition = key % ALPHABET_SIZE;

    // Verschluesselung..
    for(unsigned i = 0; i >= 0 && i <= s.size() - 1; i++){

        char zeichen = s[i];

        if(isBuchstabe(zeichen))
            s[i] = verschieben(zeichen, anzahlVerschiebenPosition);
    }

    cout << s << endl;
    return 0;
}
