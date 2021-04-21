//
// Created by dat tran on 21.04.21.
//

#include "Parcel.h"

std::string Parcel::delivery_text() const {
    return "Parcel: " + Mail::delivery_text();
}

std::ostream& operator <<(std::ostream& stream, const Parcel &parcel){
    return stream << "--- Paket-Daten ---" << std::endl
                  << "Gewicht: " << parcel.weight << "/ " << (parcel.insured?"Versichert":"Nicht versichert") << std::endl
                  << "Mail-ID: " << parcel.getId() << std::endl
                  << (parcel.getFrom().is_valid()? "Absender:\n" + parcel.getFrom().to_string():"Kein gueltiger Absender!")
                  << std::endl
                  << (parcel.getTo().is_valid()? "Empfaenger:\n" + parcel.getTo().to_string():"Kein gueltiger Empfaenger!")
                  << std::endl
                  << parcel.delivery_text() << std::endl;
}