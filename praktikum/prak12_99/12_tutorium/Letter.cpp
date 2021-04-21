//
// Created by dat tran on 20.04.21.
//

#include "Letter.h"

std::string Letter::delivery_text() const {
    return "Bief: " + Mail::delivery_text();
}

std::ostream& operator << (std::ostream& stream, const Letter &letter){
    return stream << "--- Brief-Daten ---" << std::endl
                    << "Kategorie: " << (letter.get_ctg() == ShippingMethod::EXPRESS ? "Express":"Standard") << std::endl
                    << "Mail-ID: " << letter.getId() << std::endl
                    << (letter.getFrom().is_valid()? "Absender:\n" + letter.getFrom().to_string():"Kein gueltiger Absender!")
                    << std::endl
                    << (letter.getTo().is_valid()? "Empfaenger:\n" + letter.getTo().to_string():"Kein gueltiger Empfaenger!")
                    << std::endl
                    << letter.delivery_text() << std::endl;
}

void print(Mail &mail){
    std::cout << mail.delivery_text() << std::endl;
}