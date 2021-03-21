//
// Created by dat tran on 19.03.21.
//

#ifndef RECHNUNG_ERSTELLEN_IF_ELSE__RECHNUNG_ERSTELLEN_H
#define RECHNUNG_ERSTELLEN_IF_ELSE__RECHNUNG_ERSTELLEN_H
#include <iostream>
#include <cassert>
using namespace std;

unsigned int rechnungErstellen(unsigned int auftragssumme);
unsigned int rechnungErstellen(unsigned int auftragsummer){
    cout << "Auftragsumme: " << auftragsummer << " Euro" << endl;
    unsigned int verpackungszuschlag = 0, versandkosten = 0;
    if(auftragsummer < 300){
        verpackungszuschlag = 10;
        versandkosten = 15;
        assert((auftragsummer < 300) && (verpackungszuschlag == 10) && (versandkosten == 15));
    }else if(auftragsummer < 1000){
        verpackungszuschlag = 5;
        assert((auftragsummer >= 300) && (auftragsummer < 1000)
                && (verpackungszuschlag == 5) && (versandkosten == 0));
    }else{
        assert((auftragsummer >= 1000) && (verpackungszuschlag == 0) && (versandkosten == 0));
    }
    cout << "Verpackungszuschlag: " << verpackungszuschlag << " Euro" << endl;
    cout << "Versandkosten: " << versandkosten << " Euro" << endl;
    cout << "Gesamtbeitrag: " << auftragsummer + verpackungszuschlag
                                 + versandkosten << " Euro" << endl;
    return (auftragsummer + verpackungszuschlag + versandkosten);
}
#endif //RECHNUNG_ERSTELLEN_IF_ELSE__RECHNUNG_ERSTELLEN_H
