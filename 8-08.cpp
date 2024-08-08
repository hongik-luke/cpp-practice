#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;
int N;
vector<int> v;
void input(){
    cin>>N;
    int n1;
    for(int i = 0 ; i < N ; i++){
        cin>>n1;
        v.push_back(n1);
    }
    sort(v.begin(),v.end());
}

int64_t get(){
    int64_t ret = 0;
    int len = v.size();
    for(int i = 0 ; i < len ; i++){
        int lo = i+1;
        int hi = len-1;
        while(lo < hi){
            if(v[lo] + v[hi] + v[i] == 0){
                if(v[lo] == v[hi]){
                    ret += (hi-lo+1)*(hi-lo)/2;
                    break;
                }
                int hicnt = 1;
                int locnt = 1;
                while(v[hi]-v[hi-1] == 0){
                    hicnt++;
                    hi--;
                }
                while(v[lo+1]-v[lo] == 0){
                    locnt++;
                    lo++;
                }
                ret += hicnt*locnt;
                lo++;
            }
            else if(v[lo] + v[hi] + v[i] > 0) hi--;
            else lo++;
        }
    }
    
    return ret;
}

int main() {
    FastIO;
    input();
    cout<<get();
}