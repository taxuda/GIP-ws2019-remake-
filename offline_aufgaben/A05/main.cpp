#include <iostream>
using namespace std;

bool ziffern_1_bis_6(int zahl){
    return zahl >= 1 && zahl <= 6;
}
void a05_01(){
    int arr[10] = {0};
    for(int i = 1; i <= 9; i++){
        do{
            cout << "Bitte geben Sie die "
                << i << ". Zahl ein: ? ";
            cin >> arr[i];
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        }while(!ziffern_1_bis_6(arr[i]));
    }
    for(int i = 1; i <= 9; i++){
        cout << "Die " << i << ". eingegebenen Zahl lautete: " << arr[i] << endl;
    }
}
void a05_02(){
    int arr[7] = {0};
    for(int i = 1; i < 7; i++){
        do{
            cout << "Bitte geben Sie die "
                 << i << ". Zahl ein: ? ";
            cin >> arr[i];
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        }while(!ziffern_1_bis_6(arr[i]));
    }
    int suchZahl = 0;
    cout << "Bitte geben Sie die Suchzahl ein: ? ";
    cin >> suchZahl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!ziffern_1_bis_6(suchZahl)){
        cout << "Die Suchzahl kam NICHT unter den Eingaben vor." << endl;
    }else{
        // found in array
        for(int i = 1; i < 7; i++){
            if(suchZahl == arr[i]){
                cout << "Die Suchzahl kam unter den Eingaben vor." << endl;
                break;
            }
        }
    }
}

void a05_03(){
    const int size = 5;
    int arr[size] = {0};
    for(int i = 1; i < size; i++){
        cout << "Bitte geben Sie die "
             << i << ". Zahl ein: ? ";
        while(!(cin>>arr[i])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bitte geben Sie die "
                 << i << ". Zahl ein: ? ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int vergleich = 0;
    cout << "Bitte geben Sie die vergleichszahl ein: ? ";
    while(!(cin>>vergleich)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Bitte geben Sie die vergleichszahl ein: ? ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int count = 0;
    for(int i = 1; i < size; i++){
        if(arr[i] == vergleich){
            count++;
        }
    }
    cout << count << " Eingabezahlen waren gleich der Vergleichszahl." << endl;
    cout << 4 - count << " Eingabezahlen waren ungleich der Vergleichszahl." << endl;
}


void a05_04(){
    const int size = 10;
    int arr[size] = {0};
    const int cSize = 7;
    int count[cSize] = {0};
    for(int i = 1; i < size; i++){
        do{
            cout << "Bitte geben Sie die "
                 << i << ". Zahl ein: ? ";
            cin >> arr[i];
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        }while(!ziffern_1_bis_6(arr[i]));
    }
    for(int i = 1; i < size; i++){
        count[arr[i]]++;
        cout << "Die " << i << ". eingegebenen Zahl lautete: " << arr[i] << endl;
    }
    for(int i = 1; i < cSize; i++){
        cout << "Die Zahl " << i << " wurde " << count[i] << " mal eingegeben." << endl;
    }
}


void a05_05(){
    const int size = 10;
    int arr[size] = {0};
    const int cSize = 7;
    int count[cSize] = {0};
    for(int i = 1; i < size; i++){
        do{
            cout << "Bitte geben Sie die "
                 << i << ". Zahl ein: ? ";
            cin >> arr[i];
            count[arr[i]]++;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        }while(!ziffern_1_bis_6(arr[i]));
    }
    int count_differ = 0;
    for(int i = 1; i < cSize; i++){
        if(count[i])
            count_differ++;
    }
    cout << "In der Eingabe kammen "<< count_differ << " unterschiedliche Zahlen vor." << endl;
}

void a05_06(){
    const int size = 6;
    int arr[size] = {0};
    for(int i = 1; i < size; i++){
        cout << "Bitte geben Sie die "
             << i << ". Zahl ein: ? ";
        while(!(cin>>arr[i])){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bitte geben Sie die "
                 << i << ". Zahl ein: ? ";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int min = arr[1];
    int max = arr[1];
    for(int i = 1; i < size; i++){
        min = min < arr[i] ? min:arr[i];
        max = max < arr[i] ? arr[i]:max;
        cout << "Die " << i << ". eingegebenen Zahl lautete: " << arr[i] << endl;
    }
    cout << "Die kleinste eingegebene Zahl lautete: " << min << endl;
    cout << "Die groesste eingegebene Zahl lautete: " << max << endl;
}

int charToInt(char ziffer){
    return ziffer - '0';
}
int stringToInt(string eingabe){
    int result;
    for(int power = 1, i = eingabe.size() - 1; i >= 0; i--, power *= 10){
        result += charToInt(eingabe[i])*power;
    }
    return result;
}
void a05_07(){
    string eingabe;
    cout << "Bitte die Zahl oder das Wort 'ende' eingeben: ? ";
    cin >> eingabe;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(eingabe == "ende"){
        cout << "Das Programm beendet sich jetzt." << endl;
        return;
    }else{
        cout << stringToInt(eingabe)*2 << endl;
    }
}


string ersetze(string zeile, char zu_ersetzendes_zeichen, string ersatztext){
    string result;
    for(int i = 0; i < zeile.size(); i++){
        if(zeile[i] == zu_ersetzendes_zeichen){
            result += ersatztext;
        }else{
            result += zeile[i];
        }
    }
    return result;
}

void a05_08(){
    string s1="", s2="";
    char c;
    cout << "Bitte geben Sie die Textzeile ein: ? ";
    getline(cin,s1);
    cout << "Bitte geben Sie das zu ersetzende Zeichen ein: ? ";
    cin >> c;
    cin.ignore();
    cout << "Bitte geben Sie den einzusetzenden Text ein: ? ";
    getline(cin,s2);

    cout << "Ergebenis: " << ersetze(s1,c,s2) << endl;

    return;
}

string trimme(string s){
    string result ="";
    int begin = 0;
    while(s[begin] == '+'){
        begin++;
    }
    int end = s.size() - 1;
    while(s[end] == '+'){
        end--;
    }

    if( begin < s.size() && end >= 0){  // valid pos of begin-pos and end-pos
        for(int i = begin; i <= end; i++){
            result += s[i];
        }
    }
    return result;
}

void a05_09(){
    string s= "";
    cout <<"Bitte geben Sie die Textzeile ein: ? ";
    getline(cin, s);

    cout << "Vorher: "<< s << endl;
    cout << "Nachher: "<< trimme(s) << endl;

    return;
}
int main() {
    //a05_01();
    //a05_02();
    //a05_03();
    //a05_04();
    //a05_05();
    //a05_06();
    //a05_07();
    //a05_08();
    //a05_09();
    return 0;
}
