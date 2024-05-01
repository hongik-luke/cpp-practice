#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
int numarr[510];
int cashe[510];
void get(){
    cin>>M;
    for(int i = 0 ; i < M ; i++)
            cin>>numarr[i];
    memset(cashe,-1,sizeof(cashe));
}


int check(int index){
    
    int& ret = cashe[index+1];
    if(ret != -1)
        return ret;
    ret = 1;
    for(int i = index+1 ; i < M ; i++){
        if(index == -1 || numarr[i] > numarr[index] ){
            ret = max(ret, 1 + check(i));
        }
    }
    return ret;
}


int main(void){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        get();
        cout<<check(-1)-1<<"\n";

    }
}








