#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int M = 1000000003;
int64_t cashe[2][1010][1010]; // nowidx
int N,K;

int64_t findthat(int onefull, int nowidx, int choose){
    //cout<<nowidx<<" "<<choose<<"\n";
    if(choose == K) return 1;
    if(nowidx == N-1 || N-1-nowidx < 2*(K-choose)) return 0;
    
    int64_t& ret = cashe[onefull][nowidx][choose];
    if(ret != -1) return ret;
    ret = 0;
    
    for(int next = nowidx+2; next < N-1 ; next++){
        //cout<<next<<"!";
        ret += findthat(onefull,next,choose+1);
        //ret = ret% M;
    }
    if(nowidx+2 <= N-1 && onefull == 0){
        ret += findthat(onefull,N-1,choose+1);
        //ret = ret% M;
    }
    ret = ret % M;
    return ret;
}
int find(){
    int64_t result = findthat(1,0,1);
    result = result % M;
    for(int i = 1 ; i < N ; i++){
        result += findthat(0,i,1);
        result = result % M;
    }
    
    return result%M;
}

int main(void){
    memset(cashe,-1,sizeof(cashe));
    cin>>N>>K;
    cout<<find();
}