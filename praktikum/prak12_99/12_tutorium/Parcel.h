//
// Created by dat tran on 21.04.21.
//

#ifndef INC_12_TUTORIUM_PARCEL_H
#define INC_12_TUTORIUM_PARCEL_H
#include "Mail.h"

class Parcel: public Mail{
private:
    double weight;
    bool insured;
public:
    Parcel(const int &id, const double &weight, const bool &insured = false):
    Mail{id},weight{weight},insured{insured}{}

    Parcel(const int &id, const Adress &from, const Adress &to, const double &weight, const bool &insured = false):
    Mail{id, from, to}, weight{weight}, insured{insured}{}

    double getWeight()const{return weight;}

    void setWeight(const double& weight){Parcel::weight = weight;}

    bool getInsured()const{return insured;}

    void setInsured(const bool &insured){Parcel::insured = insured;}

    virtual std::string delivery_text() const override;

    friend std::ostream& operator <<(std::ostream& stream, const Parcel &parcel);
};

std::ostream& operator <<(std::ostream& stream, const Parcel &parcel);

#endif //INC_12_TUTORIUM_PARCEL_H
