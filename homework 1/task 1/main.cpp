#include <iostream>
#include <cmath>
#include "ellipse.h"
using namespace std;

int main() {
    Ellipse e = Ellipse(0, 0, 4, 10, false);
    Ellipse el = e;

    cout << el.hyperparam() << endl;

    el.print_vertexes();
    el.print_focuses();

    cout << el.focal_chord() << endl;
    cout << el.eccentricity() << endl;

    el.set_all(4, 7, 13, 2, true);
    double h, k, a, b;
    bool x_directed;
    el.get_all(h, k, a, b, x_directed);
    cout << h << endl;
    cout << k << endl;
    cout << a << endl;
    cout << b << endl;
    cout << x_directed << endl;

    el.print();

    el.check_point(5, 6);

    cout << el.perimeter() << endl;
    cout << el.area() << endl;

    cout << el.calculate_coord(10);
}