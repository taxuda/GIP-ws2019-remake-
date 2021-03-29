// Datei: spiel.cpp

#define CIMGGIP_MAIN
#include "CImgGIP05.h"
using namespace std;

// Für das "blaue Spielfeld" ...
const int left_border = 100;
const int right_border = 500;

// Für Position und Ausdehnung des weißen Balls ...
const int ball_size = 10;

// Ausdehnung und Position des Schlaegers ...
const int schlaeger_size_x = 50, schlaeger_size_y = 20;

bool ball_not_collisions_left_right_edge(int xb){
    return (xb >= left_border) && (xb <= right_border - ball_size);
}

bool ball_not_collisions_top_edge(int yb){
    return yb >= left_border;
}

bool ball_collisions_racket(int xb, int yb, int xs, int ys){
    return (xb + ball_size >= xs) && (xb <= xs + schlaeger_size_x)
            && ((yb + ball_size) >= ys) && ((yb + ball_size) <= (ys + 5));
    // why not yb + ball_size == ys ?
    // why not (yb + ball_size) <= (ys + delta_y) ?
}

int main()
{
    // Für das "blaue Spielfeld" ...
    const unsigned int x0 = 100, y0 = 100;
    const unsigned int x1 = 500, y1 = 500;
    // Für Position und Ausdehnung des weißen Balls ...
    int xb = 200, yb = 300;        // linke obere Ecke des Balles
    //const int ball_size = 10;
    // Geschwindigkeit des Balls ...
    int delta_x = -3, delta_y = -3;
    // Ausdehnung und Position des Schlaegers ...
    //const int schlaeger_size_x = 50, schlaeger_size_y = 20;
    int xs = 300, ys = y1 - schlaeger_size_y;   // linke obere Ecke des Schlaegers

    gip_white_background();
    while (gip_window_not_closed())
    {
        // Später nötig, damit die Graphik "schneller" wird …
        gip_stop_updates();

        // Blaues "Spielfeld" neu zeichnen ...
        gip_draw_rectangle(left_border, 100,    // linke obere Ecke
                           right_border, 500,   // rechte untere Ecke
                           blue);
        // Ball zeichnen ...
        gip_draw_rectangle(xb, yb,              // linke obere Ecke
                           xb + ball_size,      // rechte untere Ecke
                           yb + ball_size,
                           white);
        // Schlaeger zeichnen ...
        gip_draw_rectangle(xs, ys,                  // linke obere Ecke
                           xs + schlaeger_size_x,   // rechte untere Ecke
                           ys + schlaeger_size_y,
                           white);

        // Schlaeger verschieben ...
        // Falls der Schläger außerhalb des Spielfelds => zurücksetzen ...
        if(gip_mouse_x() > right_border - schlaeger_size_x){    // äußerer rechter Rand
            xs = right_border - schlaeger_size_x;
        }else if(gip_mouse_x() < left_border){                  // äußerer linker Rand
            xs = left_border;
        }else{
            xs = gip_mouse_x();
        }

        // Ball-Kollisionen mit dem Rand ...
        if(ball_not_collisions_left_right_edge(xb + delta_x)){
            xb += delta_x;
        }else{
            delta_x = -delta_x;
            xb += delta_x;
        }

        if(ball_not_collisions_top_edge(yb + delta_y)){
            yb += delta_y;
        }else{
            delta_y = -delta_y;
            yb += delta_y;
        }

        // Kollision mit Schlaeger ...
        if(ball_collisions_racket(xb, yb, xs, ys)){
            delta_y = -delta_y;
            yb += delta_y;
        }

        // Unterer Rand erreicht => Abbruch
        if(yb + ball_size >= right_border){
            break;
        }

        // Bewege Ball ...
        xb += delta_x;
        yb += delta_y;

        // Später nötig, damit die Graphik "schneller" wird …
        gip_start_updates();

        // Später nötig, wenn die Graphik "schneller gestellt" ist …
        // Etwas Pause, damit das Spiel nicht zu schnell läuft ...
        gip_wait(70);
    }
    return 0;
}
