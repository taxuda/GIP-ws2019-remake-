#include <iostream>
using namespace std;

void spalte_ab_erstem(char zeichen, string eingabe,
                      string& erster_teil, string& zweiter_teil){
    bool overCross = false;
    for(int i = 0; i < eingabe.size();i++){
        if(!overCross && eingabe[i] == zeichen){
            overCross = true;
            continue;
        }
        if(!overCross){
            erster_teil += eingabe[i];
        }else{
            zweiter_teil += eingabe[i];
        }
    }
}
void a06_01(){
    string line = "", erster_teil="", zweiter_teil ="";
    char zeichen;
    cout << "Bitte geben Sie die einzeilige Zeichenkette ein: ? ";
    getline(cin, line);
    cout << "Bitte geben Sie das Zeichen ein: ? ";
    cin >> zeichen;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    spalte_ab_erstem(zeichen, line, erster_teil, zweiter_teil);
    cout << "Der erste Teil der Zeichenkette lautet: " << erster_teil << endl;
    cout << "Der zweite Teil der Zeichenkette lautet: " << zweiter_teil << endl;
}

int addition_rekursiv(int i, int k){
    if(!k)
        return i;
    return addition_rekursiv(i+1,k-1);
}

int subtraktion_rekursiv(int i, int k){
    if(!k)
        return i;
    return subtraktion_rekursiv(i-1,k-1);
}
void a06_02(){
    int i = 0, k = 0;
    cout << "Bitte geben Sie die erste Zahl ein: ? ";
    cin >> i;
    cout << "Bitte geben Sie die zweite Zahl ein: ? ";
    cin >> k;
    cout << i << " + " << k << " = "
         << addition_rekursiv(i, k) << endl;
    cout << i << " - " << k << " = "
         << subtraktion_rekursiv(i, k) << endl;
}


const char empty_pixel = '.';
const char filled_pixel = '#';

const int canvas_size = 40;

void init_canvas(char canvas[][canvas_size]){
    for(int x = 0; x < canvas_size; x++)
        for(int y = 0; y < canvas_size; y++)
            canvas[x][y] = empty_pixel;
}

void print_canvas(char canvas[][canvas_size]) {
    for(int y = 0; y < canvas_size; y++){
        for(int x = 0; x < canvas_size; x++){
            cout << canvas[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

bool is_adjacent(int x1, int y1, int x2, int y2){
    int distance = ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(distance == 1 || distance == 2)
        return true;
    return false;
}
void linie(int x1, int y1, int x2, int y2, char canvas[][canvas_size]){
    if(is_adjacent(x1,y1,x2,y2)){
        canvas[x1][y1] = filled_pixel;
        canvas[x2][y2] = filled_pixel;
    }else{
        int x_mitte = (x1 + x2)/2;
        int y_mitte = (y1 + y2)/2;
        linie(x1,y1,x_mitte,y_mitte, canvas);
        linie(x2,y2,x_mitte,y_mitte, canvas);
    }
}

void a06_03(){
    char canvas[canvas_size][canvas_size];
    init_canvas(canvas);
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    do {
        cout << "Bitte geben Sie den ersten Punkt ein: ? ";
        cin >> x1 >> y1;
    } while (x1 < 0 || x1 >= canvas_size || y1 < 0 || y1 >= canvas_size);
    do {
        cout << "Bitte geben Sie den zweiten Punkt ein: ? ";
        cin >> x2 >> y2;
    } while (x2 < 0 || x2 >= canvas_size || y2 < 0 || y2 >= canvas_size);
    linie(x1, y1, x2, y2, canvas);
    print_canvas(canvas);
}
int main() {
    //a06_01();
    //a06_02();
    a06_03();
    return 0;
}
