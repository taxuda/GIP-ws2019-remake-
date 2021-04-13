#include <iostream>
using namespace std;

void sort_asc_bubble(int* arr, const int len){
    for (int i = 0; i < len; i++) {
        cout << i + 1 << "te time" << endl;
        bool wurde_in_dieser_phase_getauscht = false;
        for (int j = 0; j < len - 1 - i; j++) {
            // why j < len - 1 -i ?
            // ignore last element of previous cycle
            cout << "Vergleiche " << j << " mit " << j + 1 << endl;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                wurde_in_dieser_phase_getauscht = true;
            }
        }
        if(!wurde_in_dieser_phase_getauscht) break;
    }
}

int main() {
    const int len = 7;
    int arr[len] = {3, 8, 2, 10, 1, 12, 8};
            //{7, 6, 5, 4, 3, 2, 1};
            //{0, 1, 0, 1, 0, 1, 0};
    sort_asc_bubble(arr, len);
    for(int i = 0; i < len; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
