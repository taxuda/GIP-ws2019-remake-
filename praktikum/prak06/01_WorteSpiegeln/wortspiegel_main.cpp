// Datei: wortspiegel_main.cpp

#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include <string>
using namespace std;

#include "wortfunktionen.h"
#include "bildschirm.h"


int main()
{
	// Aufruf der Unit Tests ...
	Catch::Session().run();

	// Ab hier ihr Code ...
	//
	//  1. Eingabe der Textzeile
	string text;
	int pos = 0;

	cout << "Bitte geben Sie den Text ein: ? ";
	getline(cin, text);

	//  2. Endlosschleife:
    while(true){
        //     2a. Ausgabe der Textzeile und der Zeile mit dem Sternchen
        ausgabe(text,pos);

        //     2b. Abfrage der Kommandoeingabe
        char befehl = eingabe();

        //     2c. Auswertung des eingegebenen Kommandos
        //         Insbes. Aufruf der wortspiegel() Funktion beim Kommando 's'
        if(befehl == LINKS){
            if(isValidPos(text,pos - 1)){
                pos--;
            }
        }else if(befehl == RECHTS){
            if(isValidPos(text, pos + 1)){
                pos++;
            }
        }else if(befehl == SPIEGELN){
            wortspiegel(text,pos);
        }else if(befehl == ENDE){
            break;
        }
    }

	return 0;
}
