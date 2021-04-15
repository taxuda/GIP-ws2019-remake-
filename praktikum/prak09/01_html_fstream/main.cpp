#include <iostream>
#include <fstream>
#include "person.h"
using namespace std;

int main() {
    string input_line;
    fstream person_data("/Users/dattran/Desktop/projects/gip(ws2019)/praktikum/prak09/01_html_fstream/personendaten.txt", ios::in);
    if(person_data.fail())
        cout << "Fail to open file 'personendaten.txt'!" << endl;

    string short_text, long_text;
    while(getline(person_data,input_line)){
        Person p{extract_person(input_line)};
        // short_text ...
        short_text += br(b(p.last_name) + ", " + p.first_name) + "\n";

        // long_line ...
        long_text += br(b(p.first_name + " " + p.last_name)
                            + ", " + p.birthday) + "\n";
    }

    if(person_data.eof()){
        cout << "End of file 'personendaten.txt'!" << endl;
        person_data.close();
    }

    string old_html_page, new_html_page;
    fstream old_page("/Users/dattran/Desktop/projects/gip(ws2019)/praktikum/prak09/01_html_fstream/webseite.html.tmpl", ios::in);
    fstream new_page("webseite.html", ios::out);
    string line;
    while(getline(old_page, line)){
        old_html_page += line;
    };
    cout << old_html_page;
    return 0;
}
