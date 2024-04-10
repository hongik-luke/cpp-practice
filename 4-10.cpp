#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class GameObject {
protected:
	int distance;
	int x, y;
public:
	GameObject(int startX, int startY, int distance) {
		this->x = startX; this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {};
	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject *p) {
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};
class Human : virtual public GameObject{
protected:
    char name;
public:
	Human(int startX, int startY, int distance) :GameObject(startX, startY, distance) {
	    this->name = 'H';
	}
    virtual ~Human() {};
    virtual void move(){
        char key;
		cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
		cin >> key;
        if(key == 'a'){
            if(y - distance >= 0) y = y - distance;
            else y = 20 + y - distance;
        }
        else if(key == 's'){
            if(x + distance <=  9) x = x + distance;
            else x = x + distance - 10;
        }
        else if(key == 'd'){
            if(x - distance >= 0) x = x - distance;
            else x = 10 + x - distance;
        }
        else{
            if(y + distance <= 19) y = y + distance;
            else y = y + distance - 20;
            
        }
    };
	virtual char getShape(){
	    return name;
	};
};

class Monster : virtual public GameObject{
protected:
    char name;
public:
	Monster(int startX, int startY, int distance) :GameObject(startX, startY, distance) {
	    this->name = 'M';
	    srand((unsigned)time(0));
	}
    virtual ~Monster() {};
    virtual void move(){
        int num;
		num = rand() % 4;
        if(num == 0){
            if(y - distance >= 0) y = y - distance;
            else y = 20 + y - distance;
        }
        else if(num == 1){
            if(x + distance <=  9) x = x + distance;
            else x = x + distance - 10;
        }
        else if(num == 2){
            if(x - distance >= 0) x = x - distance;
            else x = 10 + x - distance;
        }
        else{
            if(y + distance <= 19) y = y + distance;
            else y = y + distance - 20;
            
        }
    }
	virtual char getShape(){
	    return name;
	}
};
class Food : virtual public GameObject{
	int count;
	char name;
public:
	Food(int startX, int startY, int distance) :GameObject(startX, startY, distance) {
		srand((unsigned)time(0));
		count = 0;
		this->name = '@';
	}
	void move() {
		int n1, num;		//n1 : 2/5 확률, n2 : 방향 선택
		n1 = rand() % 5;
		num = rand() % 4;
		if (n1 >= 1 && n1 <= 2){
		    if(num == 0){
                if(y - distance >= 0) y = y - distance;
                else y = 20 + y - distance;
            }
            else if(num == 1){
                if(x + distance <=  9) x = x + distance;
                else x = x + distance - 10;
            }
            else if(num == 2){
                if(x - distance >= 0) x = x - distance;
                else x = 10 + x - distance;
            }
            else{
                if(y + distance <= 19) y = y + distance;
                else y = y + distance - 20;
            }
		}
	}
	virtual char getShape(){
	    return name;
	}
};

class Game{
public:
    void game() {
        Human* h = new Human(0, 0, 1);	Monster *m = new Monster(5, 5, 2);
		Food* f = new Food(8, 9, 1);
		cout<<"game start"<<"\n";
		
	    while(1){				
			for (int i = 0; i<10; i++) {
				for (int j = 0; j<20; j++) {
				    cout<<"|";
					if (m->getX() == i && m->getY() == j) cout << m->getShape();	
					else if (h->getX() == i && h->getY() == j) cout << h->getShape();
					else if (f->getX() == i && f->getY() == j) cout << f->getShape();
					else cout << '-';
					cout<<"|";
				}
			    cout << "\n";
			}
			
				
			if(m->collide(h)){
				cout<<"Monster catched human, game lose!"<<"\n";
				break;
			}
			if(m->collide(f)){
				cout<<"Monster catched Food, game lose!"<<"\n";
				break;
			}
            if(h->collide(f)){
				    cout<<"Human catched Food, game win!"<<"\n";
				break;
			}
			h->move();
			f->move();
			m->move();
	    }
    }
};

int main(void){
    Game* g = new Game;
	g->game();
	delete g;
}