#include <iostream>
using namespace std;

bool isNumberFrom1To9(char zeichen){
    return (zeichen >= '1' && zeichen <= '9');
}

unsigned charToNumberFrom1To9(char zeichen){
    return (zeichen - '0');
}

int main() {
    const int y_max = 9, x_max = 9;
    int sudoku[y_max][x_max] = {0};
    const int strSize = 11;
    string line[strSize] = {""};

    // Eingabe vom Tastatur..
    for(int y = 0, i = 0; i < strSize && y < y_max; i++){
        getline(cin, line[i]);

        // Eingabe zu sudoku array..
        if(i != 3 && i != 7){
            // ignore 3.line and 7.line, doesnt contains any numbers
            for(int x = 0, j = 0; j < line[i].size() && x < x_max; j++){    // traversal line[i]
                if(isNumberFrom1To9(line[i][j])){
                    sudoku[y][x] = charToNumberFrom1To9(line[i][j]);
                    x++;
                }
            }
            y++;
        }
    }


    // Ausgabe..
    for(int y = 0; y < y_max; y++){
        if(y == 3 || y == 6){
            cout << "=======//=======//=======" << endl;
        }
        for(int x = 0; x < x_max; x++){
            if(x == 3 || x == 6){
                cout << ";//";
            }
            cout << ";" << sudoku[y][x];
        }
        cout << endl;
    }


    /*
    char labyrinth[y_max][x_max] = {
    { '#', '#', '#', '#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };
    for(int y = 0; y< y_max; y++){
        for(int x = 0; x < x_max; x++){
            cout << labyrinth[y][x];
        }
        cout << endl;
    }
    */

    return 0;
}
