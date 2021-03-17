#include <iostream>
#include "swap_vars.h"

//  nicht nötig
//  extern template void swap_vars<int>(int& x1, int& x2);
//  extern template void swap_vars<std::string>(std::string& x1, std::string& x2);

using namespace std;
int main() {
    int firstInt, secondInt;
    string firstString, secondString;
    cout << "Bitte geben Sie die erste int Zahl ein: ? ";
    cin >> firstInt;
    cin.ignore();
    cout << "Bitte geben Sie die zweite int Zahl ein: ? ";
    cin >> secondInt;
    cin.ignore();
    swap_vars(firstInt, secondInt);
    cout << "Erste Zahl nachher: " << firstInt << endl;
    cout << "Zweite Zahl nachher: " << secondInt << endl;
    cout << "Bitte geben Sie den ersten String ein: ? ";
    getline(cin, firstString);
    // cin.ignore();
    // NEED CIN.IGNORE() ?
    cout << "Bitte geben Sie den zweiten String ein: ? ";
    getline(cin, secondString);
    swap_vars(firstString,secondString);
    cout << "Erster String nachher: " << firstString << endl;
    cout << "Zweiter String nachher: " << secondString << endl;
    return 0;
}
