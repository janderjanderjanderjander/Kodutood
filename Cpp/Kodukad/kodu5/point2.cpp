#include "point2.h"
#include <cmath>
#include <iostream>
using namespace std;

float Point2::distanceFrom(Point2* P) {
    float dx = this->x - P->x; 
    float dy = this->y - P->y;
    float distance = sqrt(dx * dx + dy * dy);
    return distance;
}
ostream& operator<<(ostream& os, const Point2& point) {
    os << "x: " << point.x << ", y: " << point.y; 
    return os;
}