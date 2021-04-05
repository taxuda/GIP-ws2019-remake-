#include <iostream>
#include <string>

using namespace std;

/*
 * Freiwillige Offline-Aufgabe O 04-01 (INF & WI & MCD): Aufzählung rückwärts
 */
void a04_01(){
    for(int i = 50; i >= 0; i -= 5){
        cout << i << endl;
    }
}

/*
 * Freiwillige Offline-Aufgabe O 04-02 (INF & WI & MCD): Mehrere Aufzählungen
 */
void a04_02(){
    for(int z = 1, wert2 = 10, wert3 = 10; z <= 10; z++, wert2 *= 2, wert3 *= 3){
        cout << "Zeile: " << z
                << " Verdoppler: " << wert2
                << " Verdreifacher: " << wert3
                << endl;
    }
}

/*
 * Freiwillige Offline-Aufgabe O 04-03 (INF & WI & MCD): Rechteck zeichnen
 */
void a04_03(){
    // Eingabe...
    int breite = 0, hoehe = 0;
    do{
        cout << "Bitte geben Sie die Breite des Rechtecks ein: ? ";
        cin >> breite;
    }while(breite < 2);

    do{
        cout << "Bitte geben Sie die Hoehe des Rechtecks ein: ? ";
        cin >> hoehe;
    }while(hoehe < 2);

    const int firstLine = 0;
    const int lastLine = hoehe - 1;
    const int firstRow = 0;
    const int lastRow = breite -1;

    // Ausgabe...
    for(int line = firstLine; line <= lastLine; line++){
        for(int row = firstRow; row <= lastRow; row++){
            if( line > firstLine && line < lastLine && row > firstRow && row < lastRow){
                cout << "+";
            }else{
                cout << "*";
            }
        }
        cout << endl;
    }
}

/*
 * Pflicht-Offline-Aufgabe O 04-04 (INF & WI & MCD): Parallelogramm zeichnen
 */
void a04_04(){
    // Eingabe...
    int breite = 0, hoehe = 0;
    do{
        cout << "Bitte geben Sie die Breite des Parallelogramms ein: ? ";
        cin >> breite;
    }while(breite < 2);

    do{
        cout << "Bitte geben Sie die Hoehe des Parallelogramms ein: ? ";
        cin >> hoehe;
    }while(hoehe < 2);

    const int firstLine = 0;
    const int lastLine = hoehe - 1;
    const int firstRow = 0;
    const int lastRow = breite -1;

    // Ausgabe...
    for(int line = firstLine; line <= lastLine; line++){
        /*
         * ufeinanderfolgende Zeilen des Parallelogramms sind jeweils
         * „um ein Sternchen nach rechts versetzt“, was man auch an den Punkten sieht,
         * die links vom Parallelogramm ausgegeben werden sollen.
         */
        for(int punkte = line; punkte > 0; punkte--){
            cout << ".";
        }

        // cout * and +
        for(int row = firstRow; row <= lastRow; row++){
            if( line > firstLine && line < lastLine && row > firstRow && row < lastRow){
                cout << "+";
            }else{
                cout << "*";
            }
        }
        cout << endl;
    }
}

/*
 * Freiwillige Offline-Aufgabe O 04-05 (INF & WI & MCD): Buchstaben eines Strings
 */
void a04_05(){
    string text;
    cout << "Bitte einzeiligen Text eingeben (ohne Leerzeichen): ? ";
    text = cin.get();               // get only one char character
    if(text[0] == '\n'){            // detecting ENTER / RETURN key is pressed
        return;
    }else{
        string leftOverText;        // extracting the left over text in buffer of istream
        cin >> leftOverText;
        text.append(leftOverText);

        // ignore the rest data in istream buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    for(int i = 0; i < text.size(); i++){
        cout << "Position: " << i << " Buchstabe: " << text[i] << endl;
    }
}

/*
 * Freiwillige Offline-Aufgabe O 04-06 (INF &
 * WI & MCD): String umgekehrt ausgeben
 */
void a04_06(){
    string text;
    cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
    getline(cin, text);
    cout << "Eingabetext: " << text << endl;
    // trick
    reverse(text.begin(), text.end());
    cout << "Ergebnis: " << text << endl;
}

/*
 * Pflicht-Offline-Aufgabe O 04-07 (INF &
 * WI & MCD): Palindrom-Erkennung mit flexibler Wortlänge
 */
bool isKleinBuchstabe(char zeichen){
    return zeichen >= 'a' && zeichen <= 'z';
}

bool isValid(string text){
    for(int i = 0; i < text.size(); i++){
        if(!isKleinBuchstabe(text[i]))
            return false;
    }
    return true;
}

bool isPalindromHelper(string& text, int first, int last){
    if(first >= last){
        return true;
    }
    if(text[first] != text[last]){
        return false;
    }
    return isPalindromHelper(text, ++first, --last);
}

bool isPalindrom(string &text){
    return isPalindromHelper(text, 0, text.size() - 1);
}

void a04_07(){
    string text;
    // Eingabe...
    do{
        cout << "Text: ? ";
        getline(cin, text);
    }while(!isValid(text));

    // Palindrom test
    if(isPalindrom(text)){
        cout << "Das eingegebene Wort ist ein Palindrom." << endl;
    }else{
        cout << "Das eingegebene Wort ist KEIN Palindrom." << endl;
    }
}

/*
 * Freiwillige Offline-Aufgabe O 04-08 (INF &
 * WI & MCD): String umgekehrt ausgeben, leere Eingabe erlaubt
 */
void a04_08(){
    // leere Eingabe (Benutzer drückt sofort Enter/Return)
    string text;
    cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ?";
    getline(cin, text);
    cout << "Eingabetext: " << text << endl;
    string reversedText;
    for(int i = text.size() - 1; i >= 0; i--){  // text.size() unsigned int ? text.size() = 0
                                                // what is result from int i = unsigned(0) - 1?
        reversedText += text[i];
    }
    cout << "Ergebnis: " << reversedText << endl;
    /*
    int i = unsigned(0) - 1;
    cout << i << endl; // i = -1
     */
}

/*
 * Freiwillige Offline-Aufgabe O 04-09 (INF &
 * WI & MCD): Buchstaben in String finden
 */
void a04_09(){
    string text;
    char zeichen;
    // input...
    cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
    getline(cin, text);
    cout << "Bitte Buchstaben eingeben: ? ";
    zeichen = cin.get();    // why cin.get? because whitespace allowed

    // find the last position in the string, where the character is found
    int foundedPosition = -1;
    for(int i = text.size(); i >= 0; i--){
        if(text[i] == zeichen){
            foundedPosition = i;
            break;
        }
    }

    if(foundedPosition != -1){
        cout << "Der Buchstabe " << zeichen << " kommt im Text vor, an Position " << foundedPosition << "." << endl;
    }else{
        cout << "Der Buchstabe " << zeichen << " kommt nicht im Text vor." << endl;
    }
}

/*
 * Freiwillige Offline-Aufgabe O 04-10 (INF
 * & WI & MCD): Buchstaben in String zählen
 */
bool isBuchstabe(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isValid(char ch){
    return isBuchstabe(ch) || ch == ' ';
}

void a04_10(){
    // Input..
    string text;
    char seachedChar = ' ';
    cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
    getline(cin, text);
    do{
        cout << "Bitte Buchstaben eingeben: ? ";
        seachedChar = cin.get();
    } while (!isValid(seachedChar));

    // find and count how often the letter occurs in the text line
    int count = 0;
    for(int i = 0; i < text.size(); i++){
        if(text[i] == seachedChar){
            count++;
        }
    }

    // output..
    cout << "Der Buchstabe " << seachedChar << " kommt " << count << " mal im Text vor." << endl;
}

/*
 * Freiwillige Offline-Aufgabe O 04-11 (INF &
 * WI & MCD): Buchstaben in String ersetzen
 * take care of false input of cin
 */

void a04_11(){
    // input..
    string text;
    cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
    getline(cin, text);
    char toReplace, replacement;
    do{
        cout << "Bitte den zu ersetzenden Buchstaben eingeben: ? ";
        cin >> toReplace;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(!isBuchstabe(toReplace));
    do{
        cout << "Bitte den Ersatz-Buchstaben eingeben: ? ";
        cin >> replacement;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(!isBuchstabe(replacement));
    // replace
    for(int i = 0; i < text.size(); i++){
        if(text[i] == toReplace){
            text[i] = replacement;
        }
    }
    cout << "Der Text nach der Ersetzung: " << text << endl;
}

/*
 * Pflicht-Offline-Aufgabe O 04-12 (INF &
 * WI & MCD): Buchstaben im String umwandeln
 */
bool isGroesseBuchstabe(char ch){
    return ch >= 'A' && ch <= 'Z';
}
bool isZahlziffern(char ch){
    return ch >= '0' && ch <= '9';
}
string umwandlung(string & s){
    string result;
    for(int i = 0; i < s.size(); i++){
        if(isKleinBuchstabe(s[i])){
            result = result + s[i] +s[i];
        }else if(isGroesseBuchstabe(s[i])){
            result = result + s[i] + s[i] + s[i];
        }else if(isZahlziffern(s[i])){
            result += '.';
        }else if(s[i] == '!' || s[i] == '?'){
            //result += "";
            continue;
        }else if(s[i] == ' '){
            result += '_';
        }else{
            result += s[i];
        }
    }
    return result;
}
void a04_12(){
    string text;
    cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
    getline(cin,text);
    string result;
    result = umwandlung(text);
    cout << "Der Text nach der Umwandlung: " << result << endl;
}
int main() {
    //a04_01();
    //a04_02();
    //a04_03();
    //a04_04();
    //a04_05();
    //a04_06();
    //a04_07();
    //a04_08();
    //a04_09();
    //a04_10();
    //a04_11();
    a04_12();
    return 0;
}
