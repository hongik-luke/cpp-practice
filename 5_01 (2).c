#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

int N;
int board[100100][3];
int cashe[100100][3];

void get(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
        cin>>board[i][0]>>board[i][1]>>board[i][2];
    memset(cashe,-1,sizeof(cashe));
}

int getresult(int down , int place){
    
    if(down == N-1) return board[down][place];
    
    int& ret = cashe[down][place];
    if(ret != -1) return ret;

    if(place == 0){
        ret = max(getresult(down+1,0), getresult(down+1,1) );
        
    }
    else if(place == 2){
        ret = max( getresult(down+1,1), getresult(down+1,2) );
    }
    else{
        ret = max( getresult(down+1,0), getresult(down+1,1) );
        ret = max( ret, getresult(down+1,2) );
    }
    
    ret += board[down][place];

    return ret;
}


int main(void){
    get();
    int maxer = getresult(0,0);
    maxer = max(maxer,getresult(0,1)); 
    maxer = max(maxer,getresult(0,2)); 
    cout<<maxer;
}



