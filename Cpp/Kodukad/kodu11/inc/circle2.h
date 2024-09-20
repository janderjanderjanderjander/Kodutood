#ifndef CIRCLE2_H
#define CIRCLE2_H
#include <iostream>
#include "point2.h"
#include "line2.h"
using namespace std;

class Circle2 {
    shared_ptr<Point2> p1{};
    float r{};
    const float pi{3.14159275f};
public:
    Circle2() : p1(make_shared<Point2>(Point2())), r{} {}
    Circle2(shared_ptr<Point2> np1, float nr);
    Circle2(const Circle2& cr) : p1{cr.p1}, r{cr.r} {}
    Circle2(Circle2&& cr) : p1{cr.p1}, r{cr.r} {
        cr.p1 = nullptr;
        cr.r = 0;
    }
    float circumference();
    float area();
    bool contains (shared_ptr<Point2>);
    bool contains (shared_ptr<Line2>);
    void scale (float);
    shared_ptr<Point2> getNp1() const {return p1;} 
    float getNr() {return r;} 
    void setNp1(shared_ptr<Point2>);
    void setNr(float nr) {r = nr;} 
    friend ostream& operator<<(ostream& os, const Circle2& circle);
};

#endif