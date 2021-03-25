#include <iostream>
using namespace std;

int main() {
    unsigned int firstDay, firstMonth, firstYear, secondDay, secondMonth, secondYear;
    cout << "Bitte geben Sie den Tag des ersten Datums ein: ";
    cin >> firstDay;
    cout << "Bitte geben Sie den Monat des ersten Datums ein: ";
    cin >> firstMonth;
    cout << "Bitte geben Sie das Jahr des ersten Datums ein: ";
    cin >> firstYear;
    cout << "Bitte geben Sie den Tag des zweiten Datums ein: ";
    cin >> secondDay;
    cout << "Bitte geben Sie den Monat des zweiten Datums ein: ";
    cin >> secondMonth;
    cout << "Bitte geben Sie das Jahr des zweiten Datums ein: ";
    cin >> secondYear;

    if(secondYear > firstYear){
        cout << "Das erste Datum liegt vor dem zweiten Datum." << endl;
    }else if(secondYear < firstYear){
        cout << "Das zweite Datum liegt vor dem ersten Datum." << endl;
    }else if(secondYear == firstYear){
        if(secondMonth > firstMonth){
            cout << "Das erste Datum liegt vor dem zweiten Datum." << endl;
        }else if(secondMonth < firstMonth){
            cout << "Das zweite Datum liegt vor dem ersten Datum." << endl;
        }else if(secondMonth == firstMonth){
            if(secondDay > firstDay){
                cout << "Das erste Datum liegt vor dem zweiten Datum." << endl;
            }else if(secondDay < firstDay){
                cout << "Das zweite Datum liegt vor dem ersten Datum." << endl;
            }else if(secondDay == firstDay){
                cout << "Beide Datumsangaben sind gleich." << endl;
            }
        }
    }
    return 0;
}
