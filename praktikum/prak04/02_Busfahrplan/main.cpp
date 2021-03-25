#include <iostream>
using namespace std;

const unsigned MAX_TIME_IN_MINUTE = 23 * 60 + 59; // 23:59 Uhr ist letzte mögliche Zeit

int main() {
    // Eingabe..
    unsigned startHour = 0, startMinute = 0, cycleTime;

    do{
        cout <<"Bitte geben Sie die Stunden der Startuhrzeit ein: ";
        cin >> startHour;
    }while(startHour > 23);

    do{
        cout <<"Bitte geben Sie die Minuten der Startuhrzeit ein: ";
        cin >> startMinute;
    }while(startMinute > 59);

    cout << "Der erste Bus faehrt also um " << startHour << ":" << startMinute << " Uhr." << endl;

    do{
        cout << "Bitte geben Sie die Taktzeit in Minuten ein: ";
        cin >> cycleTime;
    }while(cycleTime > 180);

    // Ausgabe..
    unsigned startTime = startHour * 60 + startMinute;
    while(startTime < MAX_TIME_IN_MINUTE){
        unsigned oldHour = startTime/60;
        cout << oldHour << ":" << startTime%60 << " ";

        startTime += cycleTime;

        if(oldHour < startTime/60){ // oldHour smaller than new Hour
            cout << endl;
        }
    }
    return 0;
}
