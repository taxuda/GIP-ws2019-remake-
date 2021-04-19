#include <iostream>

#define CIMGGIP_MAIN
#include "CImgGIP05.h"

using namespace std;
using namespace cimg_library;

const int grid_size = 10; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size = 30;  // size der einzelnen Kaestchen (in Pixel)
const int border = 20;    // Rand links und oben bis zu den ersten Kaestchen (in Pixel)

// Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(bool grid[][grid_size]);

int main()
{
    bool grid[grid_size][grid_size] = { 0 };
    bool next_grid[grid_size][grid_size] = { 0 };
    bool tmp_grid[grid_size + 2][grid_size + 2] = {0};
    // Erstes Grid vorbelegen ...
    grid_init(grid);

    while (gip_window_not_closed())
    {
        // Spielfeld anzeigen ...
        gip_stop_updates(); // ... schaltet das Neuzeichnen nach jeder Bildschirmänderung aus

        // TO DO
        gip_draw_rectangle(0,0,
                           grid_size * box_size + 2 * border,
                           grid_size * box_size + 2 * border,
                           white);

        // draw cell
        for(int y = 0; y < grid_size; y++){
            for(int x = 0; x < grid_size; x++){
                if(grid[x][y]){
                    gip_draw_rectangle(border + x * box_size,
                                       border + y * box_size,
                                       border + (x+1) * box_size,
                                       border + (y+1) * box_size,
                                       green);
                }

                tmp_grid[y+1][x+1] = grid[y][x];
            }
        }
        gip_start_updates(); // ... alle Bildschirmänderungen (auch die nach dem gip_stop_updates() ) wieder anzeigen
        gip_sleep(1);

        // Berechne das naechste Spielfeld ...
        // Achtung; Für die Zelle (x,y) darf die Position (x,y) selbst *nicht*
        // mit in die Betrachtungen einbezogen werden.
        // Ausserdem darf bei zellen am rand nicht über den Rand hinausgegriffen
        // werden (diese Zellen haben entsprechend weniger Nachbarn) ...

        // TO DO
        // count neighbors
        for(int y = 1; y <= 10; y++){
            for(int x = 1; x <= 10; x++){
                int count = tmp_grid[y-1][x-1] + tmp_grid[y-1][x] + tmp_grid[y-1][x+1]
                            + tmp_grid[y][x-1]           +           tmp_grid[y][x+1]
                            + tmp_grid[y+1][x-1] + tmp_grid[y+1][x] + tmp_grid[y+1][x+1];
                if(!tmp_grid[y][x] && count == 3){  // give birth for one cell
                    grid[y - 1][x - 1] = true;
                }else if(tmp_grid[y][x] && (count == 2 || count == 3)){ // cell keeps living
                    grid[y - 1][x - 1] = true;
                }else{  // cell died
                    grid[y - 1][x - 1] = false;
                }
            }
        }

        // Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...
        // TO DO

    }
    return 0;
}

void grid_init(bool grid[][grid_size])
{
    int eingabe = -1;
    do {
        cout << "Bitte waehlen Sie die Vorbelegung des Grids aus:" << endl
             << "0 - Zufall" << endl
             << "1 - Statisch" << endl
             << "2 - Blinker" << endl
             << "3 - Oktagon" << endl
             << "4 - Gleiter" << endl
             << "5 - Segler 1 (Light-Weight Spaceship)" << endl
             << "6 - Segler 2 (Middle-Weight Spaceship)" << endl
             << "? ";
        cin >> eingabe;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (eingabe < 0 || eingabe > 6);

    if (eingabe == 0)
    {
        // Erstes Grid vorbelegen (per Zufallszahlen) ...

        // TO DO
        for(int y = 0; y < grid_size; y++){
            for(int x = 0; x < grid_size; x++){
                grid[x][y] = gip_random(0,1);
            }
        }
    }
    else if (eingabe == 1)
    {
        const int pattern_size = 3;
        char pattern[pattern_size][pattern_size] =
                {
                        { '.', '*', '.' },
                        { '*', '.', '*' },
                        { '.', '*', '.' },
                };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y+3] = true;
    }
    else if (eingabe == 2)
    {
        const int pattern_size = 3;
        char pattern[pattern_size][pattern_size] =
                {
                        { '.', '*', '.' },
                        { '.', '*', '.' },
                        { '.', '*', '.' },
                };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y+3] = true;
    }
    else if (eingabe == 3)
    {
        const int pattern_size = 8;
        char pattern[pattern_size][pattern_size] =
                {
                        { '.', '.', '.', '*', '*', '.', '.', '.' },
                        { '.', '.', '*', '.', '.', '*', '.', '.' },
                        { '.', '*', '.', '.', '.', '.', '*', '.' },
                        { '*', '.', '.', '.', '.', '.', '.', '*' },
                        { '*', '.', '.', '.', '.', '.', '.', '*' },
                        { '.', '*', '.', '.', '.', '.', '*', '.' },
                        { '.', '.', '*', '.', '.', '*', '.', '.' },
                        { '.', '.', '.', '*', '*', '.', '.', '.' },
                };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y+1] = true;
    }
    else if (eingabe == 4)
    {
        const int pattern_size = 3;
        char pattern[pattern_size][pattern_size] =
                {
                        { '.', '*', '.' },
                        { '.', '.', '*' },
                        { '*', '*', '*' },
                };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y+3] = true;
    }
    else if (eingabe == 5)
    {
        const int pattern_size = 5;
        char pattern[pattern_size][pattern_size] =
                {
                        { '*', '.', '.', '*', '.' },
                        { '.', '.', '.', '.', '*' },
                        { '*', '.', '.', '.', '*' },
                        { '.', '*', '*', '*', '*' },
                        { '.', '.', '.', '.', '.' },
                };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y+3] = true;
    }
    else if (eingabe == 6)
    {
        const int pattern_size = 6;
        char pattern[pattern_size][pattern_size] =
                {
                        { '.', '*', '*', '*', '*', '*' },
                        { '*', '.', '.', '.', '.', '*' },
                        { '.', '.', '.', '.', '.', '*' },
                        { '*', '.', '.', '.', '*', '.' },
                        { '.', '.', '*', '.', '.', '.' },
                        { '.', '.', '.', '.', '.', '.' },
                };
        for (int y = 0; y < pattern_size; y++)
            for (int x = 0; x < pattern_size; x++)
                if (pattern[y][x] == '*')
                    grid[x][y+3] = true;
    }
}
