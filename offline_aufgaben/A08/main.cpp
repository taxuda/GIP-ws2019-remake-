#include <iostream>
using namespace std;

unsigned int my_strlen(const char* const ptr){
    unsigned len_count = 0;
    int i = 0;
    while(ptr[i] != '\0'){
        len_count++;
        i++;
    }
    return len_count;
}

void a08_01(){
    const int len = 20;
    char cstring[len];
    cout << "Bitte Text eingeben (ggfs. mit Leerzeichen): ? ";
    for(int i = 0; i < len; i++){
        char tmp = cin.get();
        if(tmp == '\0' || tmp == '\n'){
            break;
        }else{
            cstring[i] = tmp;
        }
    }
    cout << "Ergebnis my_strlen(): "<<my_strlen(cstring) << endl;
}

/*
 * A08_02
 */
void getCstring(char * cstring, const int len){
    int actual_len = 0;
    for(; actual_len < len; actual_len++){
        char tmp = cin.get();
        if(tmp == '\n'){
            break;
        }else{
            cstring[actual_len] = tmp;
        }
    }
    // user input more than allow
    if(actual_len == len){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    /*
     * TrangtrangTrangtrangTrangtrangTrangtrangTrangtrangTrangtrangTrangtrangTrangtrang
     */



}

/*
 * return 0, equal
 * return 1, ptr1 > ptr2 : lexical
 * return -1, ptr1 < ptr2: lexical
 */
int my_strcmp (const char * ptr1, const char * ptr2){
    int len_ptr1 = my_strlen(ptr1);
    int len_ptr2 = my_strlen(ptr2);

    // ptr1 or ptr2 or both empty
    if(!len_ptr2){ // ptr2 is empty
        return len_ptr1 > len_ptr2; // and ptr1 is empty (return 0)
                                    // or ptr1 is not empty (return 1)
    }else if(!len_ptr1) // ptr2 is not empty and ptr1 is empty
        return -1;

    // both cstring not empty
    int max_len = len_ptr1 > len_ptr2 ? len_ptr1:len_ptr2;
    // compare with shorter length of both cstring
    for(int i = 0; i < max_len; i++){
        if(ptr1[i] == ptr2[i]){
            continue;
        }else if(ptr1[i] > ptr2[i]){
            return 1;
        }else
            return -1;
    }
    return 0;
}

void a08_02(){
    const int len = 20;
    char cstr1[len] = {'\0'}, cstr2[len] = {'\0'};
    cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
    getCstring(cstr1, len);
    cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
    getCstring(cstr2, len);
    switch (my_strcmp(cstr1,cstr2)) {
        case 0:
            cout << "Die Texte sind identisch. Ergebnis my_strcmp(): 0" << endl;
            break;
        case 1:
            cout << "Ergebnis my_strcmp(): 1" << endl;
            break;
        case -1:
            cout << "Ergebnis my_strcmp(): -1"<< endl;
            break;
    }
}

/*
 * A08_03
 */
char* my_strconcat(const char* ptr1, const char *ptr2){
    const int len_concat = 40;
    char * concat  = new char[len_concat]{'\0'};
    int index = 0;
    while(*ptr1 != '\0'){
        concat[index] = *ptr1;
        index++;
        ptr1++;
    }
    while(*ptr2 != '\0'){
        concat[index] = *ptr2;
        index++;
        ptr2++;
    }
    return concat;
}

void a08_03(){
    const int len = 20;
    char cstr1[len] = {'\0'}, cstr2[len] = {'\0'};
    cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
    getCstring(cstr1, len);
    cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
    getCstring(cstr2, len);
    cout << "Ergebnis my_strconcat(): " << my_strconcat(cstr1, cstr2) << endl;
}

/*
 * A08_04
 */
char * my_strconcat2(const char * sptr1, const char * sptr2,
                     unsigned int count){
    const int len_concat = 40;
    char * concat  = new char[len_concat]{'\0'};
    int actual_len = count < len_concat? count: len_concat;

    int index = 0;
    while(index < actual_len && *sptr1 != '\0'){
        concat[index] = *sptr1;
        index++;
        sptr1++;
    }
    while(index < actual_len && *sptr2 != '\0'){
        concat[index] = *sptr2;
        index++;
        sptr2++;
    }
    return concat;
}
void a08_04(){
    const int len = 20;
    char cstr1[len] = {'\0'}, cstr2[len] = {'\0'};
    cout << "Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
    getCstring(cstr1, len);
    cout << "Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
    getCstring(cstr2, len);
    cout << "Anzahl Zeichen: ? ";
    int count = 0;
    cin >> count;
    cout << "Ergebnis my_strconcat2(): " << my_strconcat2(cstr1, cstr2,count) << endl;
}

struct w_haeufigkeit {
    char* wort;
    unsigned int haeufigkeit;
};

/*
 * Wortliste eines Texts, mit Häufigkeiten, mittels C-Strings
 */
const unsigned int eingabezeilen_max = 5;
const unsigned int wort_max = 1000;
const unsigned int max_line_length = 80; // inklusive des Nullterminators
char* naechstes_wort(const char* const zeile,
                     unsigned int& pos);
void zaehle_wort(char* wort,
                 struct w_haeufigkeit w_haeufigkeiten[],
                 unsigned int& w_count);
bool isAlphabet(char ch);
bool isAlphabet(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
char* naechstes_wort(const char* const zeile,
                     unsigned int& pos){
    char* wort = new char;
    int w_index = 0;
    for(; pos < max_line_length; pos++){
        if(isAlphabet(zeile[pos])){           // reading word
            wort[w_index] = zeile[pos];
            w_index++;
            if(!isAlphabet(zeile[pos + 1])){ // next character isn't alphabet
                pos = pos + 1;                   // complete reading word
                return wort;                     // return next position after end of word
            }
        }
    }
    return nullptr;
}

void zaehle_wort(char* wort,
                 struct w_haeufigkeit w_haeufigkeiten[],
                 unsigned int& w_count){
    int i = 0;
    for(; i < w_count; i++){
        if(my_strcmp(w_haeufigkeiten[i].wort, wort) == 0){
            w_haeufigkeiten[i].haeufigkeit++;
            break;
        }
    }

    // word isn't found
    if(i == w_count){
        // add new word
        w_haeufigkeiten[i].wort = wort;
        w_haeufigkeiten[i].haeufigkeit = 1;
        w_count++;
    }
}

void a08_05(){
    //string line[5][80];
    // input lines...
    char container_of_lines[eingabezeilen_max][max_line_length] = {'\0'};
    int actual_numbs_of_lines = 0;
    for(int i = 0; i < eingabezeilen_max; i++){
        cout << "Eingabezeile = ?: ";
        getCstring(container_of_lines[i], max_line_length - 1);
        if(my_strlen(container_of_lines[i]) == 0){ // stop prematurely when empty input
            break;
        }else{
            actual_numbs_of_lines++;
        }
    }

    // Container Of Words
    w_haeufigkeit container_of_word[wort_max]{nullptr, 0};
    unsigned int w_count = 0;

    // find word and update frequency
    char* tmp = nullptr;

    // get word from each line
    for(int i = 0; i < actual_numbs_of_lines; i++){
        unsigned int pos_in_line = 0;
        while(true){
            // get word from line
            tmp = naechstes_wort(container_of_lines[i], pos_in_line);
            if(tmp != nullptr){
                // search word in container_of_words
                // update if word has existed in list
                // if not, input new word to container_of_words
                zaehle_wort(tmp, container_of_word, w_count);
            }else{
                break;
            }
        }
    }

    // output...
    for(int i = 0; i < w_count; i++){
        cout << container_of_word[i].wort << ": " << container_of_word[i].haeufigkeit << endl;
    }

}
int main() {
    //a08_01();
    //a08_02();
    //a08_03();
    //a08_04();
    //a08_05();
    return 0;
}
