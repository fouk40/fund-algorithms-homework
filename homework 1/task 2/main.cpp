#include "quart.cpp"
using namespace std;
int main(){
quart q1 = quart(1.0, 2.0, 3.0, 4.0);
quart q2 = quart(5.0, 7.0, 1.0, 9.0);
quart q3 = quart(q2);
q3.print();
q3.~quart();
q3.print();
q1.print();
q2.print();
cout <<"q1 + q2 = ";
sum(q1, q2).print();
cout <<"q1 x q2 = ";
v_pr(q1, q2).print();
cout <<s_pr(q1, q2)<<"\n";
cout <<"q1/q2 = ";
div(q1, q2).print();
cout << "q1 mod = "<<q1.quart_mod()<<"\n";
cout << "q2 mod = "<<q2.quart_mod()<<"\n";
cout <<"q1 sopr = ";
q1.quart_sopr().print();
cout <<"q1 normalized = ";
q1.norm().print();
cout <<"q1 inversion = ";
q1.inv().print();
cout <<"Euclid distance = "<<euc(q1, q2)<<"\n";
cout <<"Chebishev distance = " << cheb(q1,q2)<<"\n";
return 0;
}