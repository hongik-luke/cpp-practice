#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate{
public:

    virtual bool operation(){
        if(x && y ) return true;
        else return false;
    }
};
class ORGate : public AbstractGate{
public:

    virtual bool operation(){
        if(x  || y ) return true;
        else return false;
    }
};
class XORGate : public AbstractGate{
public:

    virtual bool operation(){
        if(x == y)  return false;
        else return true;
    }
};


class AbstractStack{
public:
    virtual bool push(int n) = 0;
    virtual bool pop(int &n) = 0;
    virtual int size() = 0;
};
class stack : public AbstractStack{
    int arr[1000];
    int numofData;
public:
    stack(){numofData = 0;};
    virtual bool push(int n){
        if(numofData == 999)
            return false;
        arr[numofData] = n;
        numofData++;
        return true;
    }
    virtual bool pop(int &n){
        if(numofData == 0)
            return false;
        numofData--;
        n = arr[numofData];

        return true;
        
    }
    virtual int size(){return numofData;}
};

class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea()  = 0;
	string getname() { return name; }
};

class Oval : public Shape{
public:
    Oval(string n , int w , int h): Shape(n,w,h){};
    virtual double getArea() {
        return width*height*3.14;
    }
};
class Rect : public Shape{
public:
    Rect(string n , int w , int h): Shape(n,w,h){};
    virtual double getArea() {
        return width*height;
    }
};
class Triangular : public Shape{
public:
    Triangular(string n , int w , int h): Shape(n,w,h){};
    virtual double getArea() {
        return width*height/2;
    }
};

int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);

	for (int i = 0; i < 3; i++) {
		cout << p[i]->getname() << " 넓이는 " << p[i]->getArea() << endl;
	}

	for (int i = 0; i < 3; i++) delete p[i];
	return 0;
}











































































