#include <iostream>
using namespace std;

void a02_01(){
    double seitenLaenge = 0.0;
    cout << "Bitte geben Sie die Seitenlaenge ein (in cm): ? ";
    cin >> seitenLaenge;
    cout << "Der Umfang des Quadrats betraegt (in cm): "
            << seitenLaenge * 4 << endl;
    cout << "Die Flaeche des Quadrats betraegt (in cm*cm): "
            << seitenLaenge * seitenLaenge << endl;
}

void a02_02_ringtausch(){
    int v1 = 0, v2 = 0;
    cout << "Bitte geben Sie den ganzzahligen Wert der ersten Variable ein: ? ";
    cin >> v1;
    cout << "Bitte geben Sie den ganzzahligen Wert der zweiten Variable ein: ? ";
    cin >> v2;
    cout << "Nach dem Tausch: " << endl;

    // Ringtausch durch dritte Variable v_tmp
    int v_tmp = v1;
    v1 = v2;
    v2 = v_tmp;
    cout << "Wert der ersten Variable: " << v1 << endl;
    cout << "Wert der zweiten Variable: " << v2 << endl;
}

void a02_03(){
    // Teil A
    int gesamtzahl = 0, erste = 0, zweite = 0;
    do {
        cout << "Bitte geben Sie die Gesamtzahl der abgegebenen gueltigen Stimmen ein: ? ";
        cin >> gesamtzahl;
    } while (gesamtzahl < 0);

    do {
        cout << "Bitte geben Sie die Anzahl Stimmen des ersten Kandidaten ein: ? ";
        cin >> erste;
    } while (erste > gesamtzahl);

    do {
        cout << "Bitte geben Sie die Anzahl Stimmen des zweiten Kandidaten ein: ? ";
        cin >> zweite;
    } while (zweite + erste > gesamtzahl);

    cout << "Auf den dritten Kandidaten sind somit "
            << gesamtzahl - zweite - erste
            << " Stimmen entfallen." << endl;
    // Teil B ...
    cout << "Kandidat 1 erhielt " << double(erste) / gesamtzahl * 100 << "% der Stimmen." << endl;
    cout << "Kandidat 2 erhielt " << double(zweite)/ gesamtzahl * 100 << "% der Stimmen." << endl;
    cout << "Kandidat 3 erhielt " << double(gesamtzahl - erste - zweite)/ gesamtzahl * 100 << "% der Stimmen." << endl;
}

void a02_04(){
    // teil a: eingaben, ganzzahlrechnung
    // der erste Uhr
    int stunde = 0, minute = 0, sekunde = 0;
    do{
        cout << "Bitte geben Sie die Stundenzahl der ersten Uhrzeit ein: ? ";
        cin >> stunde;
    }while(stunde < 0 || stunde > 23);

    do{
        cout << "Bitte geben Sie die Minutenzahl der ersten Uhrzeit ein: ? ";
        cin >> minute;
    }while(minute < 0 || minute > 59);

    do{
        cout << "Bitte geben Sie die Sekundenzahl der ersten Uhrzeit ein: ? ";
        cin >> sekunde;
    } while(sekunde < 0 || sekunde > 59);
    cout << stunde << ":" << minute << " Uhr und " << sekunde
            << " Sekunden sind in Sekunden seit Mitternacht: "
            << stunde * 3600 + minute * 60 + sekunde << endl;
    cout << endl;
    // der zweite Uhr
    int stunde2 = 0, minute2 = 0, sekunde2 = 0;
    do{
        cout << "Bitte geben Sie die Stundenzahl der zweiten Uhrzeit ein: ? ";
        cin >> stunde2;
    }while(stunde2 < 0 || stunde2 > 23);

    do{
        cout << "Bitte geben Sie die Minutenzahl der zweiten Uhrzeit ein: ? ";
        cin >> minute2;
    }while(minute2 < 0 || minute2 > 59);

    do{
        cout << "Bitte geben Sie die Sekundenzahl der zweiten Uhrzeit ein: ? ";
        cin >> sekunde2;
    } while(sekunde2 < 0 || sekunde2 > 59);
    cout << stunde2 << ":" << minute2 << " Uhr und " << sekunde2
         << " Sekunden sind in Sekunden seit Mitternacht: "
         << stunde2 * 3600 + minute2 * 60 + sekunde2 << endl;

    // Teil c: Berechnung und Ausgabe der Zeitdifferenz
    int differenz = (stunde2 * 3600 + minute2 * 60 + sekunde2)
                    - (stunde * 3600 + minute * 60 + sekunde);
    cout << "Die Differenz zwischen den beiden Uhrzeiten betraegt:" << endl;
    cout << differenz / 3600 << " Stunden, "
            << differenz % 60 << " Minuten und "
            << differenz - differenz / 3600 * 3600 - differenz % 60 * 60
            << " Sekunden." << endl;
}

bool isKleinBuchstabe(char zeichen){
    return zeichen >= 'a' && zeichen <= 'z';
}

void a02_05(){
    char zeichen = ' ';
    do{
        cout << "Bitte geben Sie den Kleinbuchstaben ein: ? ";
        cin >> zeichen;
    }while(!isKleinBuchstabe(zeichen));
    const int gap = 'A' - 'a';
    cout << "Der entsprechende Grossbuchstabe lautet: "
            << char(zeichen + gap) << endl;
}

int main() {
    //a02_01();
    //a02_02_ringtausch();
    //a02_03();
    //a02_04();
    a02_05();
    return 0;
}
