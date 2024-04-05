#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	Circle& operator ++() {
	    this->radius++;
	    return *this;
    }
    Circle operator ++(int x) {
	    Circle tmp = *this;
	    this->radius++;
	    return tmp;
    }
    friend Circle operator +(int n, Circle c);
};
Circle operator +(int n, Circle c){
    Circle tmp(n+c.radius);
    return tmp;
}
int main() {
	Circle a(5), b(4),c(1);
	++a;
	b = a++;
	c = 10 + a;
	a.show();
	b.show();
	c.show();
	return 0;
}











