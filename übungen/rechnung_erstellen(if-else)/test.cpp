//
// Created by dat tran on 19.03.21.
//
#include "catch.hpp"
#include "rechnung_erstellen.h"

TEST_CASE("Gesamtbeitrag von rechnungErstellen"){
    REQUIRE(rechnungErstellen(222) == 247);
    REQUIRE(rechnungErstellen(299) == 324);
    REQUIRE(rechnungErstellen(300) == 305);
    REQUIRE(rechnungErstellen(301) == 306);
    REQUIRE(rechnungErstellen(333) == 338);
    REQUIRE(rechnungErstellen(500) == 505);
    REQUIRE(rechnungErstellen(555) == 560);
    REQUIRE(rechnungErstellen(777) == 782);
    REQUIRE(rechnungErstellen(999) == 1004);
    REQUIRE(rechnungErstellen(1000) == 1000);
    REQUIRE(rechnungErstellen(1001) == 1001);
    REQUIRE(rechnungErstellen(2500) == 2500);
}
