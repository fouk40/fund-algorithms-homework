#include "polynom.h"
#include<iostream>
#include <cstdarg>
#include <cmath>
using namespace std;
int N;
void vect_size(int &n, int m){
n = m;
}
poly::poly(){
}
poly::poly(int n){
    this->A = new int[n];
}
poly::poly(int* A, int n, double x){
this->n = n;
this->A = new int [n+1];
for (int i = 0; i <= n; i++){
    this->A[i] = A[i];
}
this->x = x;
}
poly::poly(poly& p){
this->n = p.n;
this->A = new int [p.n+1];
for (int i = 0; i <= p.n; i++){
    this->A[i] = p.A[i];
}
this->x = p.x;
}
poly::~poly(){
}
void poly::get_poly(int* A, double& x){
    A = new int [this->n+1];
    for (int i = 0; i<=this->n; i++){
        A[i] = this->A[i];
    }
    x = this->x;
}
void poly::set_poly(int* A, double x){
    for (int i = 0; i <= this->n; i++){
        this->A[i] = A[i];
    }
    this->x = x;
}
void poly::print(){
    cout << A[0]<<" + ";
    for (int i = 1; i<n; i++){
        cout <<A[i]<<"x^"<<i<<" + ";
    }
    cout << A[n]<<"x^"<<n<<"\n";
    cout << "x = "<<x<<"\n";
}
void poly::new_power(int n){
    if (n<this->n){
        int *A1 = new int[n];
        for (int i = 0; i<=n; i++){
            A1[i] = A[i];
        }
        delete[] A;
        A = new int [n];
        for (int i = 0; i<=n; i++){
            A[i] = A1[i];
        }
        delete[] A1;
    }else{
        int *A1 = new int[n];
        for (int i = 0; i<=this->n; i++){
            A1[i] = A[i];
        }
        for (int i = this->n+1;i<n;i++){
            cout << "A"<<i<<" = ";
            cin >> A1[i];
        }
        delete[] A;
        A = new int [n];
        for (int i = 0; i<=n; i++){
            A[i] = A1[i];
        }
        delete[] A1;
    }
}
vectpoly::vectpoly(){
    P = new poly[N];
}
vectpoly::vectpoly(int m, ...){
P = new poly[m];
va_list p;
va_start(p, m);
for (int i = 0;i<m;i++){
    poly* temp = va_arg(p, poly*);
    int k = temp->n;
    P[i].A = new int[k+1];
    P[i].n = temp->n;
    P[i].x = temp->x;
    for (int j = 0; j<=k; j++){
    P[i].A[j] = temp->A[j];
    }
}
va_end(p);
}
vectpoly::vectpoly(vectpoly& P){
this->P = new poly[N];
for (int i = 0; i<N; i++){
   this->P[i] = P.P[i];
}
}
vectpoly::~vectpoly(){
    delete[] this->P;
}
void vectpoly::set_vect_member(int n, int m, int *A, double x){
    this->P[n].n = m;
    for(int i = 0; i<n; i++){
        this->P[n].A[i] = A[i];
    }
    this->P[n].x = x;
}
vectpoly vect_sum(vectpoly V1, vectpoly V2){
    vectpoly res = vectpoly();
    for (int i = 0; i<N; i++){
        if(i%2==0){res.P[i].A = new int[max(V1.P[i].n, V2.P[i+1].n)+1];}
        else{res.P[i].A = new int[max(V1.P[i].n, V2.P[i-1].n)+1];}
        res.P[i].x = V1.P[i].x;
}
    for (int i = 0; i<N;i++){
        if(i%2==0){
            res.P[i].n = max(V1.P[i].n, V2.P[i+1].n);
            for(int j = 0; j<max(V1.P[i].n, V2.P[i+1].n)+1;j++){
                res.P[i].A[j] = 0;
            }
            for (int j = 0; j<V1.P[i].n+1;j++){
                res.P[i].A[j]+=V1.P[i].A[j];
            }
            for (int j = 0; j<V2.P[i+1].n+1;j++){
                res.P[i].A[j]+=V2.P[i+1].A[j];
            }
        }
        else{
            res.P[i].n = max(V1.P[i].n, V2.P[i-1].n);
            
            for(int j = 0; j<max(V1.P[i].n, V2.P[i-1].n)+1;j++){
                res.P[i].A[j] = 0;
            }
            for (int j = 0; j<V1.P[i].n+1;j++){
                res.P[i].A[j]+=V1.P[i].A[j];
            }
            for (int j = 0; j<V2.P[i-1].n+1;j++){
                res.P[i].A[j]+=V2.P[i-1].A[j];
            }
        }
        }
        return res;
    }
void vectpoly::print_vect(){
    for (int i = 0; i<N; i++){
    cout << "P"<<i<<": "; P[i].print();
    }
}
vectpoly vect_diff(vectpoly V1, vectpoly V2){
    vectpoly res = vectpoly();
    for (int i = 0; i<N; i++){
        if(i%2==0){res.P[i].A = new int[max(V1.P[i].n, V2.P[i+1].n)+1];}
        else{res.P[i].A = new int[max(V1.P[i].n, V2.P[i-1].n)+1];}
        res.P[i].x = V1.P[i].x;
}
    for (int i = 0; i<N;i++){
        if(i%2==0){
            res.P[i].n = max(V1.P[i].n, V2.P[i+1].n);
            for(int j = 0; j<max(V1.P[i].n, V2.P[i+1].n)+1;j++){
                res.P[i].A[j] = 0;
            }
            for (int j = 0; j<V1.P[i].n+1;j++){
                res.P[i].A[j]+=V1.P[i].A[j];
            }
            for (int j = 0; j<V2.P[i+1].n+1;j++){
                res.P[i].A[j]-=V2.P[i+1].A[j];
            }
        }
        else{
            res.P[i].n = max(V1.P[i].n, V2.P[i-1].n);
            
            for(int j = 0; j<max(V1.P[i].n, V2.P[i-1].n)+1;j++){
                res.P[i].A[j] = 0;
            }
            for (int j = 0; j<V1.P[i].n+1;j++){
                res.P[i].A[j]+=V1.P[i].A[j];
            }
            for (int j = 0; j<V2.P[i-1].n+1;j++){
                res.P[i].A[j]-=V2.P[i-1].A[j];
            }
        }
        }
        return res;
    }
double poly::calculate(){
    double res;
    for(int i = 0; i<=n;i++){
        res+=A[i]*pow(x, i);
    }
    return res;
}
void vectpoly::calculate_vect(){
    for (int i = 0; i<N;i++){
        cout <<"P"<<i<<" = "<<P[i].calculate()<<"\n";
    }
}