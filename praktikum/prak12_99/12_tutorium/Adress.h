//
// Created by dat tran on 20.04.21.
//

#ifndef INC_12_TUTORIUM_ADRESS_H
#define INC_12_TUTORIUM_ADRESS_H
#include <string>
#include <iostream>
#include <utility>

class Adress {
private:
    std::string name, street, city, land;
public:
    Adress()= default;

    Adress(std::string name, std::string street,
           std::string city, std::string land = "Deutschland"):name{std::move(name)}, street{std::move(street)}, city{std::move(city)}, land{std::move(land)}{}

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getStreet() const;

    void setStreet(const std::string &street);

    const std::string &getCity() const;

    void setCity(const std::string &city);

    const std::string &getLand() const;

    void setLand(const std::string &land);

    bool is_valid() const{
        return !name.empty() && !street.empty() && !city.empty();
    }

    bool scan();

    std::string to_string()const;

    friend std::ostream& operator<<(std::ostream& stream, const Adress &adr);
};


#endif //INC_12_TUTORIUM_ADRESS_H
