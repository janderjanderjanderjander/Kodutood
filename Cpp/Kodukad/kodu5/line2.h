#ifndef LINE2_H
#define LINE2_H
#include <iostream>
#include "point2.h"
using namespace std;

class Line2 {
public:
    Point2* p1{};
    Point2* p2{};
    Line2(Point2* np1, Point2* np2) : p1(np1), p2(np2) {}
    float length();
    friend ostream& operator<<(ostream& os, const Line2& line);
};




#endif