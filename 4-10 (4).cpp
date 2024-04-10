#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class Shape {
	Shape* next;

protected:
	virtual void draw() = 0;
public:
    string type;
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
};

class Line : public Shape {
public:
    Line() {type = "Line";}
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
public:
    Circle() {type = "Circle";}
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rectangle : public Shape {
public:
    Rectangle() {type = "Rectangle";}
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class UI{
protected:
    Shape* pStart;
    Shape* pLast;
    void insert(int n){
        Shape* p;
        if(n == 1)
            p = new Line;
        else if(n == 2)
            p = new Circle;  
        else 
            p = new Rectangle;
        if(pStart == NULL){
            pStart = p;
            pLast = p;
        }
        else{
            pLast->add(p);
            pLast = pLast->getNext();
        }
    }
    void remover(int n){
        if(n == 0){
            Shape* temp = pStart->getNext();
            delete pStart;
            pStart = temp;
            return;
        }
        Shape* nowidx = pStart;
        Shape* beforeidx;
        for(int i = 0 ; i < n ; i++){
            beforeidx = nowidx;
            nowidx = nowidx->getNext();
        }
        beforeidx->add(nowidx->getNext());
        delete nowidx;
    }
    void showall(){
        Shape* nowidx = pStart;
        int i = 0;
        while(nowidx != NULL){
            cout<<i<<" : "<<nowidx->type<<"\n";
            nowidx = nowidx->getNext();
            i++;
        }
        
    }
public:
    UI(){
        pStart = NULL;
        pLast = NULL;
    }
    void useui(){
        while(1){
            int order;
            int n;
            cout<<"삽입 :"<<"1 "<<"삭제 :"<<"2 "<<"전체보기 :"<<"3 "<<"종료 :"<<"4 >> ";
            cin>>order;
            if(order == 1){
                cout<<"선 :"<<"1 "<<"원 :"<<"2 "<<"사각형 :"<<"3  >> ";
                cin>>n;
                this->insert(n);
            }
            else if(order == 2){
                cout<<"삭제하고자하는 인덱스 >> ";
                cin>>n;  
                this->remover(n);
            }
            else if(order == 3){
                this->showall();
            }
            else if(order == 4){
                break;
            }
        }
    }
};

int main(void){
    UI a;
    a.useui();
}










































