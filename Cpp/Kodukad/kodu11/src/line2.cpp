#include "line2.h"
#include <cmath>
#include <iostream>
using namespace std;

float Line2::length() {
    return (*p1).distanceFrom(p2);
}
ostream& operator<<(ostream& os, const Line2& line) {
    os << "(" << (*line.p1) << " - " << (*line.p2) << ")\n"; 
    return os;
}