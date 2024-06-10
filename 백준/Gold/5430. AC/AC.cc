#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

void input(vector<int>& v){
    int temp = 0;
    string str;
    cin>>str;
    int len = str.size();
    for(int i = 1 ; i < len-1 ; i++){
        if(str[i] == ','){
            v.push_back(temp);
            temp = 0;
        }
        else{
            if(temp != 0) temp *= 10;
            temp += (int)str[i] - '0';
        }
    }
    if(len != 2) v.push_back(temp);
    
    return;
}

int main(void){
    int TC, N;
    string str;
    vector<int> v;
    cin>>TC;
    
    for(int i = 0 ; i < TC ; i++){
        cin>>str>>N;
        v.clear();
        int len = str.size();
        input(v);
        int vlen = v.size();
        
        deque <int> dq;
        for(int i = 0 ; i < vlen ; i++)
            dq.push_back(v[i]);
        
        bool flag = true;
        int temp = 1;
        for(int i = 0; i < len ; i++){
            if(str[i] == 'R') temp *= -1;
            else{
                if(dq.empty()){
                    cout<<"error\n";
                    flag = false;
                }
                if(temp == 1) dq.pop_front();
                else dq.pop_back();
            }
        }
        
        if(flag){
            int num;
            cout<<"[";
            while(!dq.empty()){
                if(temp == 1){
                    num =dq.front();
                    dq.pop_front();
                }
                else{
                    num =dq.back();
                    dq.pop_back();
                }
                cout<<num;
                if(!dq.empty())cout<<",";
            }
            cout<<"]\n";
        }
    }
}