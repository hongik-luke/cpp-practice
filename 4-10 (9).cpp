#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector> 
#include <map>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	int getradius() { return radius; }
	string getName() { return name; }
};
int main(void){
    cout<<"<원 삽입및 삭제 프로그램>"<<"\n";
    vector<Circle*> v;
    int order;
    while(1){
        cout<<"삽입 1 삭제 2 모두보기 3 종료 4 >> ";
        cin>>order;
        if(order == 1){
            int n;
            string name;
            cout<<"반지름 이름 >> ";
            cin>>n>>name;
            v.push_back(new Circle (n, name));
        }
        else if(order == 2){
            string searchname;
            cout<<"삭제 원 이름 >> ";
            cin>>searchname;
            vector<Circle*>::iterator it;
			it = v.begin();
			int size = v.size();
            for(int i = 0; i <= size; i++)
			{
			    cout<<"check";
				if (v[i]->getName() == searchname){
					
					it = v.erase(it);
					it++;
					continue;
				}
				it++;
			}
        }
        else if(order == 3){
            for (int i = 0; i < size(v); i++)
				cout << v[i]->getName() <<"    "<<v[i]->getradius() <<endl;
			
        }
        else if(order == 4)
            break;

        else{
            continue;
        }
    }
}




















































