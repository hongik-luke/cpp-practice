#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cstdlib>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N,M,L;
vector<int> v;
vector<int> len;
int len__;

void input(){
    cin>>N>>M>>L;
    int n;
    for(int i = 0 ; i < N;  i++){
        cin>>n;
        v.push_back(n);
    }
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end());
    int len_ = v.size();
    for(int i = 0 ; i < len_-1 ;  i++){
        len.push_back(v[i+1]-v[i]);
    }
    len__ = len.size();
}
bool check(int num){
    int cnt = 0;
    for(int i = 0 ; i < len__;  i++){
        cnt += len[i]/num;
        if(len[i]%num == 0) cnt--;
    }
    
    if(cnt > M) return true;
    else return false;
}

int get(){
    if(L-N < M) return 0;
    
    int lo = 1;
    int hi = 1000;
    int mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(mid)){
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return lo;
}
int main(void){
    FASTIO;
    input();
    cout<<get();
}





