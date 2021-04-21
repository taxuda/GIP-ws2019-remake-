//
// Created by dat tran on 20.04.21.
//

#ifndef INC_12_TUTORIUM_LETTER_H
#define INC_12_TUTORIUM_LETTER_H
#include "Mail.h"

enum class ShippingMethod{
    STANDARD, EXPRESS
};

class Letter: public Mail{
private:
    ShippingMethod ctg;
public:
    Letter(const int &id, const ShippingMethod &ctg):Mail{id}, ctg{ctg}{}

    Letter(const int &id, const Adress &from, const Adress &to,  const ShippingMethod &ctg):
    Mail{id, from, to}, ctg{ctg}{}

    ShippingMethod get_ctg()const {return ctg;}

    void set_ctg(const ShippingMethod& method){ctg = method;}

    virtual std::string delivery_text() const override;
};

std::ostream& operator << (std::ostream& stream, const Letter &letter);

void print(Mail& mail);
#endif //INC_12_TUTORIUM_LETTER_H
