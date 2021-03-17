#include <iostream>
#include "sort_three_vars.h"
#include "string"

using namespace std;
// ? compare values of string in lexical order

int main() {
    int firstInt, secondInt, thirdInt;
    string firstString, secondString, thirdString;
    cout << "Bitte geben Sie die erste int Zahl ein: ? ";
    cin >> firstInt; cin.ignore();
    cout << "Bitte geben Sie die zweite int Zahl ein: ? ";
    cin >> secondInt; cin.ignore();
    cout << "Bitte geben Sie die dritte int Zahl ein: ? ";
    cin >> thirdInt; cin.ignore();
    sort_three_vars(firstInt, secondInt, thirdInt);
    cout << "Erste Zahl nachher: " << firstInt << endl;
    cout << "Zweite Zahl nachher: " << secondInt << endl;
    cout << "Dritte Zahl nachher: " << thirdInt << endl;
    cout << "Bitte geben Sie den ersten String ein: ? ";
    getline(cin, firstString);
    cout << "Bitte geben Sie den zweiten String ein: ? ";
    getline(cin, secondString);
    cout << "Bitte geben Sie den dritten String ein: ? ";
    getline(cin, thirdString);
    sort_three_vars(firstString, secondString, thirdString);
    cout << "Erster String nachher: " << firstString << endl;
    cout << "Zweiter String nachher: " << secondString << endl;
    cout << "Dritter String nachher: " << thirdString << endl;
}
