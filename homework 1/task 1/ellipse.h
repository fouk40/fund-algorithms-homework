#pragma once

class Ellipse {
    public:
        double h, k, a, b;
        bool x_directed;
    
    public:
        // Конструкторы
        Ellipse(double h = 0, double k = 0, double a = 0, double b = 0, bool x_directed = true);
        Ellipse(const Ellipse &e);
        ~Ellipse();
        // Остальное
        void normalize_axis(double &a, double &b);
        double hyperparam();
        void print_vertexes();
        void print_focuses();
        double focal_chord();
        double eccentricity();
        void set_all(double h, double k, double a, double b, bool x_directed);
        void get_all(double &h, double &k, double &a, double &b, bool &x_directed);
        void print();
        void check_point(double x, double y);
        double perimeter();
        double area();
        double calculate_coord(double a, bool calc_x = false);
};