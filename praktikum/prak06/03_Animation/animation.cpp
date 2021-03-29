#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"

using namespace std;
// Für das "blaue Spielfeld" ...
const int left_border = 100;
const int right_border = 500;
const int rectangle_size = 50;

bool isValidPostion(int x){
    return (x >= left_border) && (x <= right_border - rectangle_size);
}

int main(){


    // Für Ausdehnung und Position des weißen Quadrats ...
    int x = 200, y = 300;
    int delta = 10;

    gip_white_background();

    bool turnRight = true;

    while(gip_window_not_closed()){

        // Blaues "Spielfeld" neu zeichnen
        // (übermalt dann auch das letzte weiße Quadrat) ...
        gip_draw_rectangle(left_border, 100,    // linke obere Ecke
                           right_border, 500,   // rechte untere Ecke
                           blue);

        // Weißes Quadrat neu zeichnen and der Postion x,y ...
        gip_draw_rectangle(x, y,                    // linke obere Ecke
                           x + rectangle_size,  // rechte untere Ecke
                           y + rectangle_size,
                           white);

        // Nächste Position des weißen Quadrats berechnen.
        // Dabei berücksichtigen, dass das Quadrat von den Rändern des
        // blauen "Spielfelds" abprallen muss ...

        /* Ihr Code zur Berechnung der neuen Werte von x und y hier */
        if(isValidPostion(x + delta)){
            x += delta;
        }else{  // change direction by changes sign of delta
            delta = -delta;
            x += delta;
        }
        gip_wait(100);
    }
    return 0;
}