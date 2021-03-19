//
// Created by dat tran on 19.03.21.
//

#include "rechnung_erstellen.h"
int rechnungErstellen(int auftragsummer){
    cout << "Auftragsumme: " << auftragsummer << " Euro" << endl;
    int verpackungszuschlag = 0, versandkosten = 0;
    if(auftragsummer < 300){
        verpackungszuschlag = 10;
        versandkosten = 15;
    }else if(auftragsummer < 1000){
        verpackungszuschlag = 5;
    }
    cout << "Verpackungszuschlag: " << verpackungszuschlag << " Euro" << endl;
    cout << "Versandkosten: " << versandkosten << " Euro" << endl;
    cout << "Gesamtbeitrag: " << auftragsummer + verpackungszuschlag
                                 + versandkosten << " Euro" << endl;
    return (auftragsummer + verpackungszuschlag + versandkosten);
}