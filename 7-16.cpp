#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
vector<int> v[20];
void input(){
    cin>>N;
    int n;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < (1<<i+1) ; j++){
            cin>>n;
            v[i].push_back(n);
        }
    }
    
}
int get(int high, int idx){
    if(high == N-1) return v[high][idx];
    
    int ret1 = get(high+1,idx*2);
    int ret2 = get(high+1,idx*2+1);
    if(ret1 > ret2){
        v[high+1][idx*2+1] += (ret1-ret2);
        return ret1 + v[high][idx];
    }
    if(ret1 < ret2){
        v[high+1][idx*2] += (ret2-ret1);
        return ret2 + v[high][idx];
    }
    
    return ret2 + v[high][idx];
}
int main(void){
    input();
    int ret1 = get(0,0);
    int ret2 = get(0,1);
    if(ret1 > ret2){
        v[0][1] += ret1-ret2;
    }
    if(ret1 < ret2){
        v[0][0] += ret2-ret1;
    }
    int64_t ret = 0;
    for(int i = 0 ; i < N ; i++){
        int k = v[i].size();
        for(int j = 0 ; j < k ; j++){
            ret += v[i][j];
        }
    }
    cout<<ret;
}