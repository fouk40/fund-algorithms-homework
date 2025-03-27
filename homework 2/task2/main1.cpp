#include "polynom.cpp"
#include <iostream>
int main(){
    vect_size(N, 4);
    int A1[3] = {3, 1, 5};
    int A3[2] = {8, 5};
    int A4[4] = {3, 2, 1};
    int A5[5] = {4, 6, 7, 1, 2};
    int A6[1] = {1};
    poly P1 = poly(A1, 2, 0.5);
    poly P2 = poly(P1);
    poly P3 = poly(A3, 1, 0.5);
    poly P4 = poly(A4, 2, 0.5);
    poly P5 = poly(A5, 4, 0.5);
    poly P6 = poly(A6, 0, 0.5);
    vectpoly V1 = vectpoly(N, P1, P2, P3, P5);
    vectpoly V2 = vectpoly(N, P4, P5, P2, P1);
    vect_sum(V1, V2).print_vect();
    vect_diff(V1, V2).print_vect();
    vect_sum(V1, V2).calculate_vect();
    vect_diff(V1, V2).calculate_vect();
    return 0;
}