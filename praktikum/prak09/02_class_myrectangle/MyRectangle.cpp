//
// Created by dat tran on 18.04.21.
//
#include "MyRectangle.h"

void MyRectangle::set(int x1, int y1, int x2, int y2) {
    MyRectangle::x1 = x1;
    MyRectangle::y1 = y1;
    MyRectangle::x2 = x2;
    MyRectangle::y2 = y2;
}

void MyRectangle::draw(){
    gip_draw_rectangle(this->x1,this->y1,
                       this->x2,this->y2,
                       blue);
}

bool MyRectangle::does_not_collide_with(const MyRectangle& other) const{
    if(this->x2 < other.x1
        || this->x1 > other.x2
        || this->y1 > other.y2
        || this->y2 < other.y1){
        return true;
    }
    return false;
}