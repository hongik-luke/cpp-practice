#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
map<string,int> mapp;

void input(){
    int N;
    string str;
    string need;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>str;
        int idx = str.find(".");
        need = str.substr(idx+1);
        
        auto iter = mapp.find(need);
        if(iter->second != 0){
            iter->second++;
        }
        else{
            mapp.insert(make_pair(need,1));
        }
    }
    
}

void print_result(){
    for (auto iter = mapp.begin(); iter != mapp.end(); ++iter) {
        cout<<iter->first<<" "<<iter->second<<'\n';
    }
}

int main(void){
    input();
    print_result();
}