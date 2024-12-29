#ifndef POINT2_H
#define POINT2_H
#include <iostream>
#include <memory>
using namespace std;

class Point2 {
    float x{};
    float y{};
public:
    Point2() = default;
    Point2(float nx, float ny) : x(nx), y(ny) {}
    float getNx() {return x;}
    float getNy() {return y;}
    void setNx(float nx) {x = nx;}
    void setNy(float ny) {y = ny;}
    float distanceFrom(shared_ptr<Point2>);
    friend ostream& operator<<(ostream& os, const Point2& point);
};

#endif