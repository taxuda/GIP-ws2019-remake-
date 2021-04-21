#include <iostream>
#include "Adress.h"
using namespace std;

#include "Adress.h"
#include "Letter.h"
#include "Parcel.h"

int main() {
    Mail aMail(16051998);
    // --- Briefe ---
    Adress to("Boss, Anton", "Antonstr. 11", "23456 Hamburg");
    // Zwei Briefe ...
    Letter letter1(102030, ShippingMethod::EXPRESS),
            letter2(203040, Adress{}, to, ShippingMethod::STANDARD);
    cout << "Die Briefe:" << endl << letter1 << letter2 << endl;

    cout << "Bitte Absender fuer Brief " << letter1.getId() << " eingeben:" << endl;
    if (!letter1.scan_from())
        cout << "Ungueltige Eingabe!" << endl;

    cout << "und der Empfaenger:" << endl;
    if (!letter1.scan_to())
        cout << "Ungueltige Eingabe!" << endl;

    cout << "Die neuen Daten des Briefs: \n" << letter1 << endl;

    cout << "Ein Versuch, den Brief auszuliefern:" << endl;
    if (letter1.deliver())
        cout << "Brief mit der ID " << letter1.getId() << " wurde ausgeliefert!\n" << endl;
    else
        cout << "Kein gueltiger Empfaenger!" << endl;

    // --- Pakete ---
    Parcel parcel1(500001, 2.5, true),
            parcel2(500002, Adress("Bauer, Hans", "Feldweg 2", "88888 Einoed"), to, 10.7);
    cout << "Die Pakete:" << endl << parcel1 << parcel2 << endl;
    cout << "Bitte Empfaenger fuer Paket " << parcel1.getId() << " eingeben:" << endl;
    if (!parcel1.scan_to())
        cout << "Ungueltige Eingabe!" << endl;
    if (parcel2.deliver())
        cout << "\nPaket mit der ID " << parcel2.getId() << " und dem Gewicht " << parcel2.getWeight() << " wurde ausgeliefert!" << endl;
    return 0;
}
