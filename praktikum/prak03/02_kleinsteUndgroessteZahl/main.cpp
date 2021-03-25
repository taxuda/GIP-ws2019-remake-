#include <iostream>
using namespace std;

int main() {
    int num1, neuNr;
    cout << "Bitte geben Sie die 1. Zahl ein: ? ";
    cin >> num1;
    int min = num1, max = num1;
    int posMin = 1, posMax = 1;

    for(int i = 2; i < 6; i++){
        cout << "Bitte geben Sie die " << i <<". Zahl ein: ? ";
        cin >> neuNr;
        if(min > neuNr){
            min = neuNr;
            posMin = i;
        }
        if(max < neuNr){
            max = neuNr;
            posMax = i;
        }
    }

    cout << "Die " << posMin << ". Zahl war die kleinste der eingegebenen Zahlen und lautet: " << min << endl;
    cout << "Die " << posMax << ". Zahl war die groesste der eingegebenen Zahlen und lautet: " << max << endl;
}
