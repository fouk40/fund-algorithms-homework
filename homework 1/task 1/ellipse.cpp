#include <iostream>
#include <cmath>
#include "ellipse.h"
using namespace std;

Ellipse::Ellipse(double h, double k, double a, double b, bool x_directed) {
    normalize_axis(a, b);
    this->h = h;
    this->k = k;
    this->a = a;
    this->b = b;
    this->x_directed = x_directed;
}

Ellipse::Ellipse(const Ellipse &e) {
    normalize_axis(e.a, e.b);
    h = e.h;
    k = e.k;
    a = e.a;
    b = e.b;
    x_directed = e.x_directed;
}

Ellipse::~Ellipse() {};

void Ellipse::normalize_axis(double &a, double &b){
    double aux;

    if(b > a){
        aux = b;
        b = a;
        a = aux;
    }
}

double Ellipse::hyperparam() {
    return sqrt(pow(a, 2) - pow(b, 2));
}

void Ellipse::print_vertexes() {
    cout << "Vertexes: ";
    if (x_directed) {
        cout << "V1 (" << h-a << ", " << k << ") & V2 (" << h+a << ", " << k << ")" << endl;
    } else {
        cout << "V1 (" << h << ", " << k-a << ") & V2 (" << h << ", " << k+a << ")" << endl;
    }
}

void Ellipse::print_focuses() {
    double c = hyperparam();
    cout << "Focuses: ";
    if (x_directed) {
        cout << "F1 (" << h-c << ", " << k << ") & F2 (" << h+c << ", " << k << ")" << endl;
    } else {
        cout << "F1 (" << h << ", " << k-c << ") & F2 (" << h << ", " << k+c << ")" << endl;
    }
}

double Ellipse::focal_chord() {
    return 2*pow(b, 2)/a;
}

double Ellipse::eccentricity() {
    return hyperparam()/a;
}

void Ellipse::set_all(double h, double k, double a, double b, bool x_directed) {
    normalize_axis(a, b);
    this->h = h;
    this->k = k;
    this->a = a;
    this->b = b;
    this->x_directed = x_directed;
}

void Ellipse::get_all(double &h, double &k, double &a, double &b, bool &x_directed) {
    h = this->h;
    k = this->k;
    a = this->a;
    b = this->b;
    x_directed = this->x_directed;
}

void Ellipse::print() {
    cout << "Ellipse equation: ";
    if (x_directed) {
        cout << "(x - " << h << ")**2 / " << pow(a, 2) << " + (y - " << k << ")**2 / " << pow(b, 2) << " = 1" << endl;
    } else {
        cout << "(x - " << h << ")**2 / " << pow(b, 2) << " + (y - " << k << ")**2 / " << pow(a, 2) << " = 1" << endl;
    }
    cout << "Center: C (" << h << ", " << k << ")" << endl;
    print_vertexes();
    print_focuses();
}

void Ellipse::check_point(double x, double y) {
    double res;
    if (x_directed) {
        res = pow(x-h, 2)/pow(a, 2) + pow(y-k, 2)/pow(b, 2);
    } else {
        res = pow(x-h, 2)/pow(b, 2) + pow(y-k, 2)/pow(a, 2);
    }

    if (res < 1) {
        cout << "The point is inside the ellipse" << endl;
    } else if (res > 1) {
        cout << "The point is outside the ellipse" << endl;
    } else {
        cout << "The point belongs to the ellipse" << endl;
    }
}

double Ellipse::perimeter() {
    return M_PI*(3*(a+b)-sqrt((3*a+b)*(a+3*b)));
}

double Ellipse::area() {
    return M_PI * a*b;
}

double Ellipse::calculate_coord(double a, bool calc_x) {
    if (!calc_x) {
        if (x_directed) {
            return sqrt(pow(b, 2)*(1-pow(a-h, 2)/pow(this->a, 2))) + k;
        } else {
            return sqrt(pow(this->a, 2)*(1-pow(a-h, 2)/pow(b, 2))) + k;
        }
    } else {
        if (x_directed) {
            return sqrt(pow(this->a, 2)*(1-pow(a-k, 2)/pow(b, 2))) + h;
        } else {
            return sqrt(pow(b, 2)*(1-pow(a-k, 2)/pow(this->a, 2))) + h;
        }
    }
}
