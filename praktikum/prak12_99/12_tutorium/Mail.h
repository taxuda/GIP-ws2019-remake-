//
// Created by dat tran on 20.04.21.
//

#ifndef INC_12_TUTORIUM_MAIL_H
#define INC_12_TUTORIUM_MAIL_H
#include "Adress.h"

class Mail {
protected:
    int id;
    Adress from, to;
    bool delivered;
public:
    Mail(const int &id):id{id}{}

    Mail(const int &id, const Adress &from, const Adress &to):id{id},from{from},to{to}{
        // class Adress not defined copy-constructor
    }

    int getId() const;

    void setId(int id);

    const Adress &getFrom() const;

    void setFrom(const Adress &from);

    const Adress &getTo() const;

    void setTo(const Adress &to);

    bool isDelivered() const;

    void setDelivered(bool delivered);

    bool deliver();

    bool scan_from();

    bool scan_to();

    virtual std::string delivery_text() const;
};

std::ostream& operator << (std::ostream& stream, const Mail &mail);
#endif //INC_12_TUTORIUM_MAIL_H
