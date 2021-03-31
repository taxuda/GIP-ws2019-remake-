#include <iostream>
#include <string>
using namespace std;

/*
 * A03_01
 */
bool isKleinBuchstabe(char zeichen){
    return zeichen >= 'a' && zeichen <= 'z';
}
void a03_01(){
    char zeichen = ' ';
    cout << "Bitte geben Sie das Zeichen ein: ? ";
    cin >> zeichen;
    if(isKleinBuchstabe(zeichen)){
        cout << "Es wurde ein Kleinbuchstabe (a-z) eingegeben." << endl;
    }else{
        cout << "KEIN Kleinbuchstabe (a-z)." << endl;
    }
}

/*
 * A03_07
 */
const int vergleichzahl = 99;
void a03_07(){
    int count_ungleich = 0, count_gleich = 0;
    // Eingabe...
    for(int i = 1; i < 5; i++){
        int zahl = 0;
        cout << "Bitte geben Sie die " << i << ". Zahl ein: ? ";
        cin >> zahl;
        if(zahl == vergleichzahl){
            count_gleich++;
        }else{
            count_ungleich++;
        }
    }
    // Ausgabe...
    cout << count_gleich << " Eingabezahlen waren gleich der Vergleichszahl 99." << endl;
    cout << count_ungleich << " Eingabezahlen waren ungleich der Vergleichszahl 99." << endl;
}

/*
 * A03_02
 */
bool isJa(char zeichen){
    return zeichen == 'j' || zeichen == 'J';
}

bool isNein(char zeichen){
    return zeichen == 'n' || zeichen == 'N';
}

void a03_02(){
    char zeichen = ' ';
    cout << "Bitte geben Sie das Zeichen ein: ? ";
    cin >> zeichen;
    if(isJa(zeichen)){
        cout << "Es handelt sich um eine Ja Eingabe." << endl;
    }else if(isNein(zeichen)){
        cout << "Es handelt sich um eine Nein Eingabe." << endl;
    }else{
        cout << "Es handelt sich um eine sonstige Eingabe." << endl;
    }
}

/*
 * A03_03
 */
bool isZahlziffer(char zeichen){
    // Ziffer sind einstellig: vom 0 bis 9
    return zeichen >= '0' && zeichen <= '9';
}

int charZifferZuIntZiffer(char zeichen){
    return zeichen - '0';
}

void a03_03(){
    char zeichen = ' ';
    cout << "Bitte geben Sie das Zeichen ein: ? ";
    cin >> zeichen;
    if(zeichen == 'e'){
        cout << "Das Programm beendet sich jetzt." << endl;
    }else if(isZahlziffer(zeichen)){
        int zahl = charZifferZuIntZiffer(zeichen);
        cout << zahl << " + " << 5 << " = " << zahl + 5 << endl;
    }else{
        cout << "Weder 'e' noch Ziffer" << endl;
    }
}

/*
 * A03_04
 */
void a03_04(){
    int uhrZeit = 0;
    cout << "Bitte geben Sie die Stunde der aktuellen Uhrzeit ein: ? ";
    cin >> uhrZeit;
    if( uhrZeit >= 0 && uhrZeit <= 5 || uhrZeit == 23){
        cout << "Gute Nacht." << endl;
    }else if( uhrZeit >= 6 && uhrZeit <= 10){
        cout << "Guten Morgen." << endl;
    }else if ( uhrZeit >= 11 && uhrZeit <= 13){
        cout << "Mahlzeit." << endl;
    }else if( uhrZeit >= 14 && uhrZeit <= 17){
        cout << "Guten Tag." << endl;
    }else if( uhrZeit >= 18 && uhrZeit <= 22){
        cout << "Guten Abend." << endl;
    }else{
        cout << "Keine erlaubte Stundenangabe." << endl;
    }
}

/*
 * A03_05
 */
string reverse(string s){
    string reversed;
    for(int i = s.size() - 1; i >= 0; i--){
        reversed += s[i];
    }
    return reversed;
}

bool isPalindrom(string s){
    string sReversed = reverse(s);
    return sReversed == s;
}

bool isPalindrom_method2(string s){
    for(int begin = 0, end = s.size() - 1; begin < s.size()/2 && end >= s.size()/2; begin++, end--){
        if(s[begin] != s[end]){
            return false;
        }
    }
    return true;
}

void a03_05(){
    string eingabe;
    cout << "Bitte geben Sie die Zeichenkette (6 Zeichen) ein: ? ";
    cin >> eingabe;
    if(isPalindrom_method2(eingabe)){
        cout << "Das eingegebene Wort ist ein Palindrom." << endl;
    }else{
        cout << "Das eingegebene Wort ist KEIN Palindrom." << endl;
    }
}

/*
 * A03_06
 */
void a03_06(){
    int min = 0, max = 0;
    for(int i = 1; i <= 3; i++){
        int zahl = 0;
        cout << "Bitte geben Sie die " << i << ". Zahl ein: ? ";
        cin >> zahl;
        if(i == 1){
            min = zahl;
            max = zahl;
        }else{
            min = (min > zahl) ? zahl : min;
            max = (max < zahl) ? zahl : max;
        }
    }
    cout << "Die kleinste eingegebene Zahl lautet: " << min << endl;
    cout << "Die groesste eingegebene Zahl lautet: " << max << endl;
}
int main() {
    //a03_01();
    //a03_02();
    //a03_03();
    //a03_04();
    //a03_05();
    a03_06();
    return 0;
}
