#include <iostream>
using namespace std;

int main() {
    // Eingabe..
    int zahl = 0;
    cout << "Bitte geben Sie die zu zerlegende Zahl ein: ? ";
    cin >> zahl;
    // Dividend ÷ Divisor = Quotient
    // Dividend % Divisor = Remainder
    /*
    unsigned divisor = zahl - 1;
    while(zahl > 1){
        if(zahl % divisor == 0) { // without remainder
            cout << zahl/divisor << " ";
            zahl = divisor;
            divisor = zahl - 1;
        }else{
            divisor--;
        }
    }
    */
    while(zahl != 1){
        for(int kandidat = 2; kandidat <= zahl; kandidat++){
            if(zahl % kandidat == 0){
                cout << kandidat << " ";
                zahl = zahl/kandidat;
                break;
            }
        }
    }
    return 0;
}
