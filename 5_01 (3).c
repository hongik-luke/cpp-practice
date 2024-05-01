#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int N,M,K;
int numarr1[110];
int numarr2[110];
int cashe[110][110];
void get(){
    cin>>M>>K;
    for(int i = 0 ; i < M ; i++)
            cin>>numarr1[i];
    for(int i = 0 ; i < K ; i++)
            cin>>numarr2[i];
    memset(cashe,-1,sizeof(cashe));
}


int check(int index1, int index2){
    
    int& ret = cashe[index1+1][index2+1];
    if(ret != -1)
        return ret;
    ret = 2;
    
    int a = (index1 == -1 ? NEGINF : numarr1[index1]);
    int b = (index2 == -1 ? NEGINF : numarr2[index2]);
    int now = max(a,b);
    
    for(int i = index1+1 ; i < M ; i++){
        if(numarr1[i] > now){
            ret = max(ret, 1 + check(i,index2));
        }
    }
    
    for(int i = index2+1 ; i < K ; i++){
        if(numarr2[i] > now ){
            ret = max(ret, 1 + check(index1,i));
        }
    }

    return ret;
}


int main(void){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        get();
        cout<<check(-1,-1)-2<<"\n";

    }
}








