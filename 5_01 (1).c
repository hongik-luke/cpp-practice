#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
int triangle[110][110];
int cashe[110][110];
void get(){
    cin>>M;
    for(int i = 1 ; i <= M ; i++)
        for(int j = 1 ; j <= i ; j++)
            cin>>triangle[i][j];
    memset(cashe,-1,sizeof(cashe));
}
int getresult(int down, int next){
    
    if(down == M)
        return triangle[down][next];
        
    int& ret = cashe[down][next];
    if(ret != -1)
        return ret;
        
    ret = triangle[down][next] + max(getresult(down+1,next),getresult(down+1,next+1));
    return ret;
}

int main(void){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        get();
        cout<<getresult(1,1)<<"\n";
    }
}




