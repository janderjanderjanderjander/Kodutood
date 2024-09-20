#ifndef LINE2_H
#define LINE2_H
#include <iostream>
#include "point2.h"
using namespace std;

class Line2 {
    shared_ptr<Point2> p1;
    shared_ptr<Point2> p2;
public:
    Line2() : p1(make_shared<Point2>(Point2())), p2(make_shared<Point2> (Point2())) {}
    Line2(shared_ptr<Point2>& np1, shared_ptr<Point2>& np2) : p1(np1), p2(np2) {}
    Line2(const Line2& lr) : p1{lr.p1}, p2{lr.p2} {}
    Line2(Line2&& ra) : p1{ra.p1}, p2{ra.p2} {
        ra.p1 = nullptr;
        ra.p2 = nullptr;
    }
    shared_ptr<Point2> getNp1() {return p1;}
    shared_ptr<Point2> getNp2() {return p2;}
    void setNp1(std::shared_ptr<Point2> np1) {p1 = np1;}
    void setNp2(std::shared_ptr<Point2> np2) {p2 = np2;}  
    float length();
    friend ostream& operator<<(ostream& os, const Line2& line);
};




#endif