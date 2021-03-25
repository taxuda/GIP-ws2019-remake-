#include <iostream>
using namespace std;

int main() {
    const unsigned size = 6;
    unsigned zahl[size];
    // Eingabe..
    for(int i = 1; i < size; i++){
        do{
            cout << "Bitte geben Sie die " << i <<". Zahl ein: ? ";
            cin >> zahl[i];
        }while(zahl[i] > 9 || zahl[i] < 1);
    }

    // Ausgabe..
    for(int thLine = 9; thLine > 0; thLine--){
        cout << thLine;
        for(int i = 1; i < size; i++){
            if(zahl[i] < thLine){
                cout << ".";
            }else if(zahl[i] > thLine){
                cout << "+";
            }else if(zahl[i] == thLine){
                cout << "*";
            }
        }
        cout << endl;
    }
    cout << " 12345" << endl;
    return 0;
}
