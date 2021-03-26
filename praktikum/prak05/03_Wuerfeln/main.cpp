#include <iostream>
#include <ctime>   /* time */
#include <cstdlib> /* srand, rand */

using namespace std;

int main() {
    /* initialize random seed: */
    srand(time(NULL));

    const int mals = 6000;
    int wuerfe[7] = {0};

    for(int i = 0; i < mals; i++){
        int zufallszahl = rand() % 6 +1 ;
        wuerfe[zufallszahl]++;
    }

    for(int i = 1; i < 7; i++){
        cout << "Anzahl " << i << "-er Wuerfe: " << wuerfe[i] << endl;
    }
    return 0;
}