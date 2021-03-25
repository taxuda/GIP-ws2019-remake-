#include <iostream>
#include <string>
using namespace std;

const unsigned ANZAHL_BUCHSTABE = unsigned ('z') - unsigned ('a') + 1;


bool isKleineBuchstabe(char zeichen);
bool isGroesseBuchstabe(char zeichen);
unsigned positionInAlphabet(char buchstabe);
unsigned moeglicheAnzahlVerschiebepostionen(unsigned anzahlVerschiebeposition);
unsigned neuePositionInALphabetNachVerschieben(char buchstabe, unsigned anzahlVerschiebeposition);
char verschieben(char buchstabe, unsigned anZahlVerschiebeposition);

/*
 * 'a','A' <=> 0.position
 * ...
 * 'z','Z' <=> 25.position
 */
unsigned positionInAlphabet(char buchstabe){
    if(isKleineBuchstabe(buchstabe))
        return unsigned(buchstabe - 'a');
    else if(isGroesseBuchstabe(buchstabe))
        return unsigned(buchstabe - 'A');
}

unsigned moeglicheAnzahlVerschiebepostionen(unsigned anzahlVerschiebeposition){
    // Es gibt moeglich ingesamts 26 Postionen zum Verschieben
    return anzahlVerschiebeposition % ANZAHL_BUCHSTABE;
}

unsigned neuePositionInALphabetNachVerschieben(char buchstabe, unsigned anzahlVerschiebeposition){
    return (positionInAlphabet(buchstabe) + moeglicheAnzahlVerschiebepostionen(anzahlVerschiebeposition)) % ANZAHL_BUCHSTABE;
}

char verschieben(char buchstabe, unsigned anzahlVerschiebeposition){
    unsigned neuePos = neuePositionInALphabetNachVerschieben(buchstabe, anzahlVerschiebeposition);
    if(isKleineBuchstabe(buchstabe))
        return ('a' + neuePos);
    else if(isGroesseBuchstabe(buchstabe))
        return ('A' + neuePos);
}

bool isKleineBuchstabe(char zeichen){
    if(zeichen >= 'a' && zeichen <= 'z'){
        return true;
    }
    return false;
}
bool isGroesseBuchstabe(char zeichen){
    if((zeichen >= 'A' && zeichen <= 'Z')){
        return true;
    }
    return false;
}



int main() {
    string s;
    unsigned verschiebenKey;

    // Eingabe..
    cout << "Bitte geben Sie den zu verschluesselnden Text ein: ";
    getline(cin, s);
    cout << "Bitte geben Sie die Anzahl Verschiebepositionen ein (als positive ganze Zahl): ";
    cin >> verschiebenKey;

    // Verschluesselung..
    for(unsigned i = 0; i >= 0 && i <= s.length() - 1; i++){
        if(isKleineBuchstabe(s.at(i))){
            s.at(i) = verschieben(s.at(i), verschiebenKey);
        }else if(isGroesseBuchstabe(s.at(i))){
            s.at(i) = verschieben(s.at(i), verschiebenKey);
        }
    }

    cout << s << endl;
    return 0;
}
