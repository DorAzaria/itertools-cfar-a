#include <iostream>
using namespace std;
#include "doctest.h"
TEST_CASE("one") {
    int i = 0;
    while( i < 100) {
        CHECK(true);
        i++;
    }
}