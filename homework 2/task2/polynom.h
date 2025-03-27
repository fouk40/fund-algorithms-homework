#pragma once
class poly{
public:
int* A;
int n;
double x;
public:
poly();
poly(int n);
poly(int* A, int n, double x);
poly(poly& p);
~poly();
void get_poly(int* A, double& x);
void set_poly(int* A, double x);
void print();
void new_power(int n);
double calculate();
};
class vectpoly{
    public:
    poly* P;
    public:
    vectpoly();
    vectpoly(int m, ...);
    vectpoly(vectpoly& P);
    ~vectpoly();
    void set_vect_member(int n, int m, int *A, double x);
    void print_vect();
    void calculate_vect();
};
void vect_size(int &n, int m);
vectpoly vect_sum(vectpoly V1, vectpoly V2);
vectpoly vect_diff(vectpoly V1, vectpoly V2);