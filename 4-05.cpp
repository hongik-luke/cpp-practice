#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class MyIntStack {
	int* p;
	int size;
	int tos;
public:
	MyIntStack() :MyIntStack(1) {}
	MyIntStack(int size);
	MyIntStack(MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack :: MyIntStack(int size){
    this-> p = new int[size];
    this->size = size;
    this-> tos = 0;
}

MyIntStack :: MyIntStack(MyIntStack& s){
    this-> p = new int[s.size];
    for(int i = 0 ; i < s.size ; i++){
        this->p[i] = s.p[i];
    }
    this->size = s.size;
    this-> tos = s.tos;
}

MyIntStack ::~MyIntStack(){
    delete [] p;
}
bool MyIntStack ::push(int n){
    
    if(tos == size-1)
        return false;
    p[tos] = n;
    tos++;
    return true;
}
bool MyIntStack :: pop(int& n){
    if(tos == 0)
        return false;
    tos--;
    n = p[tos];
    return true;
}

int main(void)
{
    MyIntStack a(100);
    a.push(5); a.push(15); a.push(52); a.push(55);
    MyIntStack b = a;
    b.push(100);
    int n;
    for(int i = 0 ; i < 4;  i++)
    {
        a.pop(n);
        cout<<n<<" ";
    }
    for(int i = 0 ; i < 5;  i++)
    {
        b.pop(n);
        cout<<n<<" ";   
    } 
}
