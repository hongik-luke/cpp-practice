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

int main(void){
    map<string, int> m;
    
    
    cout<<"<점수 관리 프로그램>"<<"\n";
    int order;
    while(1){
        cout<<"입력 1 조회 2 종료 3 >>";
        cin>>order;
        if(order == 1){
            string name;
            int score;
            cout<<"이름 점수 >> "<<"\n";
            cin>>name>>score;
            m.insert({name,score});
        }
        else if(order == 2){
            string searchname;
            int searchscore;
            while(1){
                cout<<"이름 >> ";
                cin>>searchname;
                if(m.find(searchname) == m.end()){
                    cout<<"없는데?"<<"\n";
                    continue;
                }
                cout<<"점수 >> ";
                cin>>searchscore;
            
                if(m[searchname] == searchscore){
                    cout<<"통과!"<<"\n";
                    break;
                }
                else{
                    cout<<"틀렸는데?"<<"\n";
                    continue;
                }
            }

        }
        else if(order == 3){
            break;
        }
        else if(order == 4){
            cout<<m.size();
        }
    }
    
    
    
    
    
    
    
    
    
    
    
    
}