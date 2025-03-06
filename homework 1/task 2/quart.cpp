#include <iostream>
#include "quart.h"
#include <cmath>
#include <algorithm>
using namespace std;
quart::quart(double a, double b, double c, double d){
    q_a = a;
    q_b = b;
    q_c = c;
    q_d = d;
}
quart::quart(quart& q){
    q_a = q.q_a;
    q_b = q.q_b;
    q_c = q.q_c;
    q_d = q.q_d;
}
quart::~quart(){
    q_a = 0;
    q_b = 0;
    q_c = 0;
    q_d = 0;
}
double quart::quart_mod(){
return (sqrt(pow(q_a,2) + pow(q_b,2) + pow(q_c,2) + pow(q_d,2)));
}
quart quart::quart_sopr(){
    quart q1;
    q1.q_a = q_a;
    q1.q_b =(-1)*q_b;
    q1.q_c =(-1)*q_c;
    q1.q_d =(-1)*q_d;
    return(q1);
}
void quart::set_quart(double a, double b, double c, double d){
    q_a = a;
    q_b = b;
    q_c = c;
    q_d = d;
}
void quart::get_quart(double& a, double& b, double& c, double& d){
    a = q_a;
    b = q_b;
    c = q_c;
    d = q_d;
}
void quart::print(){
    cout <<q_a<<" + "<<q_b<<"i + "<<q_c<<"j + "<<q_d<<"k\n";
}
quart quart::norm(){
    quart q1;
    q1.q_a = q_a/quart_mod();
    q1.q_b = q_b/quart_mod();
    q1.q_c = q_c/quart_mod();
    q1.q_d = q_d/quart_mod();
    return(q1);
}
quart quart::inv(){
    quart q1;
    q1.q_a = quart_sopr().q_a/pow(quart_mod(),2);
    q1.q_b = quart_sopr().q_b/pow(quart_mod(),2);
    q1.q_c = quart_sopr().q_c/pow(quart_mod(),2);
    q1.q_d = quart_sopr().q_d/pow(quart_mod(),2);
    return (q1);
}
quart sum(quart q1, quart q2){
    quart res;
    res.q_a = q1.q_a + q2.q_a;
    res.q_b = q1.q_b + q2.q_b;
    res.q_c = q1.q_c + q2.q_c;
    res.q_d = q1.q_d + q2.q_d;
    return(res);
}
quart dif(quart q1, quart q2){
    quart res;
    res.q_a = q1.q_a - q2.q_a;
    res.q_b = q1.q_b - q2.q_b;
    res.q_c = q1.q_c - q2.q_c;
    res.q_d = q1.q_d - q2.q_d;
    return(res);
}
quart v_pr(quart a, quart b){
    quart res;
    res.q_a = a.q_a * b.q_a - a.q_b * b.q_b - a.q_c * b.q_c - a.q_d * b.q_d;
    res.q_b = a.q_a * b.q_b + a.q_b * b.q_a + a.q_c * b.q_d - a.q_d * b.q_c;
    res.q_c = a.q_a * b.q_c - a.q_b * b.q_d + a.q_c * b.q_a + a.q_d * b.q_a;
    res.q_d = a.q_a * b.q_d + a.q_b * b.q_c - a.q_c * b.q_b + a.q_d * b.q_a;
    return (res);
}
double s_pr(quart q1, quart q2){
    return(q1.q_a*q2.q_a + q1.q_b*q2.q_b + q1.q_c*q2.q_c + q1.q_d*q2.q_d);
}
quart div(quart q1, quart q2){
    return (v_pr(q1, q2.inv()));
}
double euc(quart q1, quart q2){
    return(sqrt(pow(q1.q_a-q2.q_a,2)+pow(q1.q_b-q2.q_b,2)+pow(q1.q_c-q2.q_c,2)+pow(q1.q_d-q2.q_d,2)));
}
double cheb(quart q1, quart q2){
    return(max(max(q1.q_a-q2.q_a, q1.q_b-q2.q_b), max(q1.q_c-q2.q_c, q1.q_d - q2.q_d)));
}