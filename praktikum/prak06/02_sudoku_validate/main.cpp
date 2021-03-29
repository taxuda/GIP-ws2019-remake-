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

    bool sudokuIsValid = true;

    // Spalte überprüfen
    for(int spalte = 0; spalte < x_max; spalte ++){
        int vorkommt[10] = {0};
        for(int zeile = 0; zeile < y_max; zeile++){
            int number = sudoku[zeile][spalte];
            vorkommt[number]++;
        }
        for(int i = 1; i < 10; i++){
            if(vorkommt[i] > 1){
                sudokuIsValid = false;
                cout << "Spalte " << spalte << ": Zahl " << i << " kommt mehrfach vor." << endl;
            }else if(!vorkommt[i]){
                sudokuIsValid = false;
                cout << "Spalte " << spalte << ": Zahl " << i << " kommt nicht vor." << endl;
            }
        }
    }

    // Zeile überprüfen
    for(int zeile = 0; zeile < x_max; zeile ++){
        int vorkommt[10] = {0};
        for(int spalte = 0; spalte < y_max; spalte++){
            int number = sudoku[zeile][spalte];
            vorkommt[number]++;
        }
        for(int i = 1; i < 10; i++){
            if(vorkommt[i] > 1){
                sudokuIsValid = false;
                cout << "Zeile " << zeile << ": Zahl " << i << " kommt mehrfach vor." << endl;
            }else if(!vorkommt[i]){
                sudokuIsValid = false;
                cout << "Zeile " << zeile << ": Zahl " << i << " kommt nicht vor." << endl;
            }
        }
    }
    // Block überprüfen
    for(int block = 0; block < 9; block++){
        int vorkommt[10] = {0};
        for(int zeile = block/3*3; zeile <= block/3*3 +2; zeile++){
            for(int spalte = block%3*3; spalte <= block%3*3+2; spalte++){
                int number = sudoku[zeile][spalte];
                vorkommt[number]++;
            }
        }
        for(int i = 1; i < 10; i++){
            if(vorkommt[i] > 1){
                sudokuIsValid = false;
                cout << "Block " << block << ": Zahl " << i << " kommt mehrfach vor." << endl;
            }else if(!vorkommt[i]){
                sudokuIsValid = false;
                cout << "Block " << block << ": Zahl " << i << " kommt nicht vor." << endl;
            }
        }
    }

    if(sudokuIsValid){
        cout << "Das Sudoku is gueltig." << endl;
    }
    return 0;
}
