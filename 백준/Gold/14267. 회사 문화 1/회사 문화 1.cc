#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

int N,M;
vector<int> v[100100];
int in[100100];
int result[100100];
void input(){
    cin>>N>>M;
    int n1,n2;
    for(int i = 1; i <= N ; i++){
        cin>>n1;
        if(n1 == -1) continue;
        v[n1].push_back(i);
    }
    
    for(int i = 1; i <= M ; i++){
        cin>>n1>>n2;
        in[n1] += n2;
    }
}

void get(int idx, int now){
    result[idx] = now + in[idx];
    
    int len = v[idx].size();
    for(int i = 0; i < len ; i++){
        get(v[idx][i],result[idx]);
    }
    
}

int main(void){
    FASTIO;
    
    input();
    get(1,0);
    for(int i = 1; i <= N ; i++){
        cout<<result[i]<<" ";
    }
}