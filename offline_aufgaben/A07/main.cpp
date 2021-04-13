#include <iostream>
#include <string>

using namespace std;

void a07_01(){
    ///*
    const int size = 4;
    string line[size] = {""};
    int used_size = 0;
    int max_len = 0;
    for(int i = 0; i < size; i++){
        cout << "Textzeile = ? ";
        char first_char = cin.get();
        if(first_char == '\n'){
            break;
        }else{
            line[i] += first_char;
            string tmp;
            getline(cin, tmp);
            line[i] += tmp;
            max_len = max_len < line[i].size() ? line[i].size() : max_len;
            used_size ++;
        }
    }
    for(int i = 0; i < used_size; i++){
        for(int fill = 0; fill < max_len - line[i].size(); fill++){
            cout << "#";
        }
        cout << line[i];
        if( i != used_size - 1)
            cout << endl;
    }
    //*/
    /*
    std::string strings[4];
    unsigned long max_length = 0;
    for (auto & str : strings) {
        std::cout << "Textzeile = ? ";
        std::getline(std::cin, str);
        max_length = (max_length > str.length()) ? max_length : str.length();
        if (str.length() == 0) break;
    }

    for (auto & str : strings) {
        if (str == "") continue;

        if (str.length() < max_length) {
            unsigned long hashes_needed = max_length - str.length();
            for (unsigned long j = 0; j < hashes_needed; j ++) std::cout << "#";
        }

        std::cout << str << "\n";
    }
    */
}

bool is_alphabet(char c) {
    return ((c >= 'a') && (c <= 'z')) ||
           ((c >= 'A') && (c <= 'Z'));
}

void a07_02(){
    const int size = 5;
    string line[size] = {""};
    int used = 0;
    for(int i = 0; i < size; i++){
        cout << "Eingabezeile = ? ";
        getline(cin, line[i]);
        used++;
        if(!line[i].size())
            break;
    }
    for(int i = 0; i < used - 1; i++){
        for(int pos = 0; pos < line[i].size(); pos++){
            if(is_alphabet(line[i][pos])){
                cout << line[i][pos];
            }else{
                cout << "\n";
            }
        }
        cout << "\n";
    }
}

/*
 * Wortliste eines Texts, mit Häufigkeiten
 */
struct w_haeufigkeit {
    string wort;
    int haeufigkeit;
};

string naechstes_wort(string zeile, int& pos);
void zaehle_wort(string wort,
                 w_haeufigkeit haeufigkeiten[],
                 int& w_count);

bool valid_character(char c){
    return c != ' ' && c != '.' && c != ',';
}

string naechstes_wort(string zeile, int& pos){
    string wort = "";
    for(; pos < zeile.size(); pos++){
        // reading word
        if(valid_character(zeile[pos])){
            wort += zeile[pos];
            // end of zeile or,
            // end of word, because of next character is invalid
            if(pos + 1 == zeile.size() || !valid_character(zeile[pos+1])){
                pos++;
                break;
            }// else: continue to read word via next iterate
        }
    }
    return wort;
}

void zaehle_wort(string wort,
                 w_haeufigkeit haeufigkeiten[],
                 int& w_count){
    if(!w_count){
        // empty, not contain any words
        w_haeufigkeit neu{wort, 1};
        haeufigkeiten[0] = neu;
        w_count++;
    }else{
        for(int i = 0; i < w_count; i++){
            if(wort == haeufigkeiten[i].wort){
                haeufigkeiten[i].haeufigkeit++;
                break;
            }else if(i == w_count - 1){
                // end list,
                // wort is not found,
                // add new wort to list
                w_haeufigkeit neu{wort, 1};
                haeufigkeiten[++i] = neu;
                w_count++;
                break;
            }
        }
    }
}
void a07_03(){
    int z_count = 0, w_count = 0;
    string wort = "";
    string eingabe[5];

    /* Eingabe hier, setzt auch z_count auf die Anzahl nicht-leerer Zeilen */
    for(int i = 0; i < 5; i++){
        cout << "Eingabezeile = ? ";
        getline(cin, eingabe[i]);
        z_count++;

        if(eingabe[i].size() == 0){
            z_count--;
            break;
        }
    }

///*
    w_haeufigkeit haeufigkeiten[1000];

    for (int k = 0; k < z_count; k++)
    {
        int pos = 0;
        while (true)
        {
            wort = naechstes_wort(eingabe[k], pos);
            if (wort == "")
                break;
            zaehle_wort(wort, haeufigkeiten, w_count);
        }

    }

    for (int k = 0; k < w_count; k++)
        cout << haeufigkeiten[k].wort << ": "
             << haeufigkeiten[k].haeufigkeit << endl;
//*/
}

/*
 * Funktion filter()
 */
struct Person
{
    string nachname, vorname;
    int alter;
    char geschlecht;
};

void filter(Person* personen, const int size, const int choice){
    char geschlecht = '\0';
    const int alter_grenze = 18;
    if(choice == 1 || choice == 3){
            geschlecht = 'w';
    }else
        geschlecht = 'm';

    int sum = 0;

    for(int i = 0; i < size; i++){
        if(personen[i].geschlecht == geschlecht){
            if((choice == 1 || choice == 2) && personen[i].alter >= alter_grenze){
                cout << personen[i].nachname
                    <<", " << personen[i].vorname
                    <<", " << personen[i].geschlecht
                    <<", " << personen[i].alter << endl;
                sum++;
            }else if((choice == 3 || choice == 4) && personen[i].alter < alter_grenze){
                cout << personen[i].nachname
                     <<", " << personen[i].vorname
                     <<", " << personen[i].geschlecht
                     <<", " << personen[i].alter << endl;
                sum++;
            }
        }
    }
    cout << "Summe: " << sum << endl;
}
void a07_04(){
/*
    const int len = 100;
    Person personen[len];
    int anzahl_personen = 0;
*/

    Person personen[100] = {
            { "Musterfrau1", "Petra1", 18, 'w' },
            { "Mustermann1", "Klaus1", 18, 'm' },
            { "Mustermaedchen1", "Lisa1", 1, 'w' },
            { "Musterjunge1", "Jan1", 1, 'm' },
            { "Musterfrau2", "Petra2", 19, 'w' },
            { "Mustermann2", "Klaus2", 19, 'm' },
            { "Mustermaedchen2", "Lisa2", 2, 'w' },
            { "Musterjunge2", "Jan2", 2, 'm' },
            { "Musterfrau3", "Petra3", 20, 'w' },
            { "Mustermann3", "Klaus3", 20, 'm' },
            { "Mustermaedchen3", "Lisa3", 3, 'w' },
            { "Musterjunge3", "Jan3", 3, 'm' },
            { "Musterfrau4", "Petra4", 21, 'w' },
            { "Mustermann4", "Klaus4", 21, 'm' },
            { "Mustermaedchen4", "Lisa4", 4, 'w' },
            { "Musterjunge4", "Jan4", 4, 'm' },
            { "Musterfrau5", "Petra5", 22, 'w' },
            { "Mustermann5", "Klaus5", 22, 'm' },
            { "Mustermaedchen5", "Lisa5", 5, 'w' },
            { "Musterjunge5", "Jan5", 5, 'm' },
            { "Musterfrau6", "Petra6", 23, 'w' },
            { "Mustermann6", "Klaus6", 23, 'm' },
            { "Mustermaedchen6", "Lisa6", 6, 'w' },
            { "Musterjunge6", "Jan6", 6, 'm' },
            { "Musterfrau7", "Petra7", 24, 'w' },
            { "Mustermann7", "Klaus7", 24, 'm' },
            { "Mustermaedchen7", "Lisa7", 7, 'w' },
            { "Musterjunge7", "Jan7", 7, 'm' },
            { "Musterfrau8", "Petra8", 25, 'w' },
            { "Mustermann8", "Klaus8", 25, 'm' },
            { "Mustermaedchen8", "Lisa8", 8, 'w' },
            { "Musterjunge8", "Jan8", 8, 'm' }
    };
    int anzahl_personen = 32;

    // Input..
    char choice = '\0';

    while(true){
        cout <<"Eine weitere Person eingeben (j/n)? ";
        while(!(cin >> choice) || (choice != 'j' && choice != 'n')){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<"Eine weitere Person eingeben (j/n)? ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        if (choice == 'j') {
            cout << "Bitte den Nachnamen der "
                 << anzahl_personen + 1
                 << ". Person eingeben: ? ";
            getline(cin, personen[anzahl_personen].nachname);

            cout << "Bitte den Vornamen der "
                 << anzahl_personen + 1
                 << ". Person eingeben: ? ";
            getline(cin, personen[anzahl_personen].vorname);

            cout << "Bitte das Alter der "
                 << anzahl_personen + 1
                 << ". Person eingeben: ? ";
            cin >> personen[anzahl_personen].alter;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Bitte das Geschlecht der "
                 << anzahl_personen + 1
                 << ". Person eingeben: ? ";
            cin >> personen[anzahl_personen].geschlecht;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            anzahl_personen++;
        }else
            break;
    }

    // filter choice
    int filter_choice = 0;
    cout << "Ihre Auswahl:\n1 - Weibliche Erwachsene\n2 - Maennliche Erwachsene\n"
        <<"3 - Weibliche Kinder\n4 - Maennliche Kinder\n? ";
    cin >> filter_choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // function
    filter(personen, anzahl_personen, filter_choice);
}


/*
 *  Morse Alphabet
 */
struct T_Morse_Data {
    char letter;
    std::string morse_code; };

const T_Morse_Data morse_data[] = { { 'a', ".-" },
                                    { 'b', "-..." },
                                    { 'c', "-.-." },
                                    { 'd', "-.." },
                                    { 'e', "." },
                                    { 'f', "..-." },
                                    { 'g', "--." },
                                    { 'h', "...." },
                                    { 'i', ".." },
                                    { 'j', ".---" },
                                    { 'k', "-.-" },
                                    { 'l', ".-.." },
                                    { 'm', "--" },
                                    { 'n', "-." },
                                    { 'o', "---" },
                                    { 'p', ".--." },
                                    { 'q', "--.-" },
                                    { 'r', ".-." },
                                    { 's', "..." },
                                    { 't', "-" },
                                    { 'u', "..-" },
                                    { 'v', "...-" },
                                    { 'w', ".--" },
                                    { 'x', "-..-" },
                                    { 'y', "-.--" },
                                    { 'z', "--.." },
                                    { '0', "-----" },
                                    { '1', ".----" },
                                    { '2', "..---" },
                                    { '3', "...--" },
                                    { '4', "....-" },
                                    { '5', "....." },
                                    { '6', "-...." },
                                    { '7', "--..." },
                                    { '8', "---.." },
                                    { '9', "----." },
                                    // Leerzeichen zur Worttrennung werden im Morsecode
                                    // durch einen Slash '/' umgeben von Leerzeichen
                                    // dargestellt ...
                                    // (Alternative: Trennung durch 3 Leerzeichen)
                                    // Hier bei uns, um die Testläufe eindeutiger zu
                                    // machen: Trennung mittels drei Slashes
                                    { ' ', "///" },
                                    { '.', ".-.-.-" },
                                    { ',', "--..--" },
                                    { ':', "---..." },
                                    { '?', "..--.." },
                                    { '-', "-....-" },
                                    { '/', "-..-." },
                                    { '@', ".--.-." },
                                    { '=', "-...-" }
};

const int morse_data_len = 45;

char toLowerCase(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch - 'A' + 'a';
    }
}
void a07_05(){
    string line;
    cout << "Bitte Text eingeben (ggf. mit Leerzeichen): ? ";
    getline(cin, line);

    // codierung...
    string result;
    for(int i = 0; i < line.size(); i++){
        if(line[i] >= 'A' && line[i] <= 'Z'){
            line[i] = toLowerCase(line[i]);
        }
        for(int j = 0; j < morse_data_len; j++){
            if(line[i] == morse_data[j].letter){
                result += morse_data[j].morse_code;
                result += '#';
                break;
            }
        }
    }
    cout << result << endl;
}
int main() {
    //a07_01();
    //a07_02();
    //a07_03();
    //a07_04();
    a07_05();
    return 0;
}
