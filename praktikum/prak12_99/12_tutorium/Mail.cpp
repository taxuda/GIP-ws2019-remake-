//
// Created by dat tran on 20.04.21.
//

#include "Mail.h"

int Mail::getId() const {
    return id;
}

void Mail::setId(int id) {
    Mail::id = id;
}

const Adress &Mail::getFrom() const {
    return from;
}

void Mail::setFrom(const Adress &from) {
    if(from.is_valid())
        Mail::from = from;
    else
        return;
}

const Adress &Mail::getTo() const {
    return to;
}

void Mail::setTo(const Adress &to) {
    if(to.is_valid())
        Mail::to = to;
    else
        return;
}

bool Mail::isDelivered() const {
    return delivered;
}

void Mail::setDelivered(bool delivered) {
    Mail::delivered = delivered;
}

bool Mail::deliver() {
    if(this->to.is_valid()){
        delivered = true;
        return true;
    }else{
        delivered = false;
        return false;
    }
}

bool Mail::scan_from() {
    return from.scan();
}

bool Mail::scan_to() {
    return to.scan();
}

std::ostream& operator << (std::ostream& stream, const Mail &mail){
    std::string status;
    if(mail.isDelivered()){
        status = "Post wurde ausgeliefert!";
    }else
        status = "Post wurde noch nicht ausgeliefert!";

    return stream << "Mail-ID: " << mail.getId() << std::endl
                    << "Absender: " << std::endl << mail.getFrom() << std::endl
                    << "Empfaenger:" << std::endl <<  mail.getTo() << std::endl
                    << status;
}

std::string Mail::delivery_text() const{
    if(delivered)
        return "Ausgeliefert an " + to.getName() + ".";
    else
        return "Noch nicht ausgeliefert!";
}