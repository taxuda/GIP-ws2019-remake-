#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    bst::Node * root = nullptr;
    cout << "Leere Baum" << endl;
    int data;
    do{
        cout << "Naechster Wert (99 beendet): ? ";
        if(cin >> data && data != 99){
            bst::insert(root, data);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(data != 99);

    if(root == nullptr) cout << "Leere Baum" << endl;
    bst::printOut_rightLeft_Inorder(root);
    return 0;
}
