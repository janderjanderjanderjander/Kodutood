#include <iostream>

using namespace std;

#include "arvutused.h"
#include "point2.h"
#include "line2.h"
#include "circle2.h"

int main() {
    Point2 punkt1(0, 4.5);
    Point2 punkt2(0, 1);
    Point2 joonel_punkt(20, 19);
    Point2 joonel_punkt_veel(20, 18);
    Point2 ringipunkt(20, 20);
    Line2 joon(&punkt1, &punkt2);
    Line2 joon_pool(&joonel_punkt, &punkt2);
    Line2 joon_sees(&joonel_punkt, &joonel_punkt_veel);
    Circle2 ring(&ringipunkt, 5);
    cout << "Ringi ümbermõõt (31.4159): " << ring.circumference() << "\n";
    cout << "Ringi pindala (78.5398): " << ring.area() << "\n";
    cout << "Kas punkt on selle ringi sees? (Ei): " << ring.contains(&punkt1) << "\n";
    cout << "Kas punkt on selle ringi sees? (jah): " << ring.contains(&joonel_punkt) << "\n";
    cout << "Kas joon on selle ringi sees? (Ei): " << ring.contains(&joon) << "\n";
    cout << "Kas joon (ühe punktiga sees) on selle ringi sees? (Ei): " << ring.contains(&joon_pool) << "\n";
    cout << "Kas joon on selle ringi sees? (jah): " << ring.contains(&joon_sees) << "\n";
    return 0;
}