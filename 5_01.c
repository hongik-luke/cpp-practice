#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;
int INF = -987654321;
int N;
int taketime[1500100];
int getprice[1500100];
int cashe[1500100];

void get(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>taketime[i]>>getprice[i];
    }
    memset(cashe,-1,sizeof(cashe));
}

int getresult(int nowday){
    if(nowday > N) return INF;
    
    int& ret = cashe[nowday+1];
    if(ret != -1) return ret;
    
    ret = 0;
    if(nowday != -1 && nowday + taketime[nowday] <= N)
        ret = max(ret, getprice[nowday] + getresult(nowday + taketime[nowday]));
    ret = max(ret, getresult(nowday+1));
        
    return ret;
}


int main(void){
    get();
    cout<<getresult(-1);
}



