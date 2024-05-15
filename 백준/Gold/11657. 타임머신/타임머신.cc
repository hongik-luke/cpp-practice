#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct pos {
    int value;
    int idx;
};

int IMF = 98765432;
int F = 9876543;
int N,M;

vector<pos> v[510];
void input(){
    cin>>N>>M;
    int n1,n2,n3;
    pos newpos;
    for(int i = 0 ; i< M ;i++){
        cin>>n1>>n2>>n3;
        newpos = {n3,n2};
        v[n1].push_back(newpos);
    }
}
vector<int64_t> resultv(510,IMF);
bool bellmen_ford(){
    resultv[1] = 0;
    for(int repeat = 0 ; repeat < N ; repeat++){
        bool is_true = true;
        for(int here = 1 ; here <= N ; here++){
            for(int i = 0 ; i < v[here].size() ; i++){
                int there = v[here][i].idx;
                int value = v[here][i].value;
                if(resultv[here] < IMF - F && resultv[there] > resultv[here] + value){
                    resultv[there] = resultv[here] + value;
                    is_true = false;
                }
                
            }
        }
        if(is_true) return false;
    }
    
    return true;
}

int main(void){
    input();
    if(bellmen_ford()) cout<<-1;
    else{
        for(int i = 2 ; i <= N ; i++){
            if(resultv[i] == IMF) cout<<-1<<"\n";
            else cout<<resultv[i]<<"\n";
        }
    }
}