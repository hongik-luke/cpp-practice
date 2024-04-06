#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray{
    int front, last;
public:
    MyQueue(int x) : BaseArray(x){
        front = 0 ; last = 0;
    }
    void enqueue(int x){
        if(last == this->getCapacity() - 1)
            return ;
        put(last, x);
        last++;
    }
    int dequeue(){
        if(front == last)
            return -1;
        int temp = get(front);
        front++;
        return temp;
    }
    int capacity(){return this->getCapacity();}
    int length(){return last - front;}
};

class MyStack : public BaseArray{
	int top;
public:
    MyStack(int x) : BaseArray(x){top = 0;}
    void push(int x){
        if(top == this->getCapacity() - 1)
            return ;
        put(top, x);
        top++;
    }
    int pop(){
        top--;
        return get(top);
    }
    int capacity(){return this->getCapacity();}
    int length(){return top;}
};


int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택의 용량:" << mStack.capacity() << ", 스택의 크기:" << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
	return 0;
}
