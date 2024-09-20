#ifndef POINT2_H
#define POINT2_H
#include <iostream>
using namespace std;

class Point2 {
public:
    float x{};
    float y{};
    Point2() : x(0), y(0) {}
    Point2(float nx, float ny) : x(nx), y(ny) {}
    float distanceFrom(Point2* P);
    friend ostream& operator<<(ostream& os, const Point2& point);
};

#endif