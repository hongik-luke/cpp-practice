#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N,M;
vector<int> v;
int dp[10010];
void input(){
    memset(dp,0,sizeof(dp));
    v.clear();
    cin>>N;
    int n1;
    for(int i = 0 ; i <  N ; i++){
        cin>>n1;
        v.push_back(n1);
    }
    cin>>M;
    dp[0] = 1;
}

int getresult(){
    for(int i = 0 ; i < N ; i++){
        for(int j = v[i] ; j <= M ; j++){
            dp[j] += dp[j - v[i]];
        }
    }

    return dp[M];
}

int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        input();
        cout<<getresult()<<"\n";
        
    }
}



