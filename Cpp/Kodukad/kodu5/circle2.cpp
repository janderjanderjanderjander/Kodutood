#include "circle2.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle2::Circle2(Point2* np1, float nr) {
    if (nr < 0) {
        nr = 0;
    }
    p1 = np1;
    r = nr;
}
float Circle2::circumference() {
    return 2 * pi * r;
}
float Circle2::area(){
    return pi * (r * r);
}
bool Circle2::contains (Point2* p) {
    if ((*p1).distanceFrom(p) <= r) {
        return true;
    } else {
        return false;
    }
}
bool Circle2::contains (Line2* l) {
    if ( (*p1).distanceFrom((*l).p1) <= r and (*p1).distanceFrom((*l).p2) <= r ) {
        return true;
    } else {
        return false;
    }
}
void Circle2::scale (float factor) {
    if (factor < 0) {}
    else {
        r *= factor;
    }
}
ostream& operator<<(ostream& os, const Circle2& circle) {
    os << "((" << (*circle.p1) << "), " << circle.r << ")\n";
    return os;
}