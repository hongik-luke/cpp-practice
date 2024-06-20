#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N;
int parent[10010];
int get1[2];
void input(){
    cin>>N;
    for(int i = 1 ; i <= N ; i++)
        parent[i] = -1;
    
    int n1,n2;
    for(int i = 0 ; i < N-1 ; i++){
        cin>>n1>>n2;
        parent[n2] = n1;
    }
    cin>>get1[0]>>get1[1];
}
bool check[10010];
int get_parent(){
    memset(check,false,sizeof(check));
    int c = get1[0];
    while(1){
        if(c == -1) break;
        check[c] = true;
        c = parent[c];
    }
    
    c = get1[1];
    while(1){
        if(check[c]) return c;
        c = parent[c];
    }
}


int main(void){
    int TC;
    cin>>TC;
    for(int i = 0; i < TC ; i++){
        input();
        cout<<get_parent()<<"\n";
    }
}