//
// Created by dat tran on 19.04.21.
//

#ifndef INC_01_MYFILLEDRECTANGLE_MYFILLEDRECTANGLE_H
#define INC_01_MYFILLEDRECTANGLE_MYFILLEDRECTANGLE_H
#include "MyRectangle.h"

class MyFilledRectangle: public MyRectangle{
public:
    MyFilledRectangle(int x1 = 0, int y1 = 0, int x2 = 20, int y2 = 20): MyRectangle{x1,y1,x2,y2}{}
    void draw();
};


#endif //INC_01_MYFILLEDRECTANGLE_MYFILLEDRECTANGLE_H
