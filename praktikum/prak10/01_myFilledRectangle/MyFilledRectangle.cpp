//
// Created by dat tran on 19.04.21.
//

#include "MyFilledRectangle.h"
void MyFilledRectangle::draw(){
    MyRectangle::draw();
    if(this->x1 + 2 <= this->x2 - 2){
        for(int y = this->y1 + 2; y <= this->y2 - 2; y += 2){
            gip_draw_line(this->x1 + 2, y, this->x2 - 2, y, red);
        }
    }
}