#pragma once
class quart{
public:
double q_a, q_b, q_c, q_d;
public:
quart(double a = 1, double b = 0, double c = 0, double d = 0);
quart(quart& q);
~quart();
double quart_mod();
quart quart_sopr();
void set_quart(double a, double b, double c, double d);
void get_quart(double& a, double& b, double& c, double& d);
void print();
quart norm();
quart inv();
};
quart sum(quart q1, quart q2);
quart dif(quart q1, quart q2);
quart v_pr(quart q1, quart q2);
double s_pr(quart q1, quart q2);
quart div(quart q1, quart q2);
double euc(quart q1, quart q2);
double cheb(quart q1, quart q2);