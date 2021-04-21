//
// Created by dat tran on 20.04.21.
//

#include "Adress.h"

const std::string &Adress::getName() const {
    return name;
}

void Adress::setName(const std::string &name) {
    Adress::name = name;
}

const std::string &Adress::getStreet() const {
    return street;
}

void Adress::setStreet(const std::string &street) {
    Adress::street = street;
}

const std::string &Adress::getCity() const {
    return city;
}

void Adress::setCity(const std::string &city) {
    Adress::city = city;
}

const std::string &Adress::getLand() const {
    return land;
}

void Adress::setLand(const std::string &land) {
    Adress::land = land;
}

bool Adress::scan(){
    std::cout << "Nachname, Vorname: ";
    std::getline(std::cin, this->name);
    if(this->name.empty())
        return false;

    std::cout << "Strasse mit Hausnr.: ";
    std::getline(std::cin, this->street);
    if(this->street.empty())
        return false;

    std::cout << "Postleizahl Stadt: ";
    std::getline(std::cin, this->city);
    if(this->city.empty())
        return false;

    std::cout << "Land: ";
    std::getline(std::cin, this->land);
    if(this->land.empty())
        this->land = "Deutschland";
    return true;
}

std::ostream& operator<<(std::ostream& stream, const Adress& adr){
    return stream << adr.name << std::endl << adr.street << std::endl << adr.city << std::endl << adr.land;
    //return stream;
}

std::string Adress::to_string()const{
    return name + "\n" + street + "\n" + city + "\n" + land;
}