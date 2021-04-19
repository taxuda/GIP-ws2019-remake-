// Datei: main.cpp

#define CATCH_CONFIG_RUNNER
#include "catch.h"

#include <iostream>
using namespace std;

#include "suchen.h"
#include "myCstrings.h"

int main()
{
    if (Catch::Session().run()) {
        return 1;
    }

    // Ihr Code ab hier ...
    // ...

    return 0;
}
