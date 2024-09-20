#include <iostream>

using namespace std;

//#include "arvutused.h"
#include "point2.h"
#include "line2.h"
#include "circle2.h"

int main() {
    shared_ptr punkt1_ptr = make_shared<Point2> (Point2(0, 4.5));
    shared_ptr punkt2_ptr = make_shared<Point2> (Point2(0, 1));
    shared_ptr joonel_punkt_ptr = make_shared<Point2> (Point2(20, 19));   
    shared_ptr joonel_punkt_veel_ptr = make_shared<Point2> (Point2(20, 18));
    shared_ptr ringipunkt_ptr = make_shared<Point2> (Point2(20, 20));
    shared_ptr joon_ptr = make_shared<Line2> (Line2(punkt1_ptr, punkt2_ptr));
    shared_ptr joon_pool_ptr = make_shared<Line2> (Line2(joonel_punkt_ptr, punkt2_ptr));
    shared_ptr joon_sees_ptr = make_shared<Line2> (Line2(joonel_punkt_ptr, joonel_punkt_veel_ptr));
    shared_ptr ring_ptr = make_shared<Circle2> (Circle2(ringipunkt_ptr, 5));
    
    cout << "Ringi ümbermõõt (31.4159): " << (*ring_ptr).circumference() << "\n";
    cout << "Ringi pindala (78.5398): " << (*ring_ptr).area() << "\n";
    cout << "Kas punkt on selle ringi sees? (Ei): " << (*ring_ptr).contains(punkt1_ptr) << "\n";
    cout << "Kas punkt on selle ringi sees? (jah): " << (*ring_ptr).contains(joonel_punkt_ptr) << "\n";
    cout << "Kas joon on selle ringi sees? (Ei): " << (*ring_ptr).contains(joon_ptr) << "\n";
    cout << "Kas joon (ühe punktiga sees) on selle ringi sees? (Ei): " << (*ring_ptr).contains(joon_pool_ptr) << "\n";
    cout << "Kas joon on selle ringi sees? (jah): " << (*ring_ptr).contains(joon_sees_ptr) << "\n";
    
    return 0;
}