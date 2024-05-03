#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

int N;
int board[100100][3];
int cashe[3];

void get(){
    cin>>N; 
    for(int i = 1 ; i <= N ; i++)
        cin>>board[i][0]>>board[i][1]>>board[i][2];
}

void getmaxresult(int nowN){
    if(nowN == 0) return;
    cashe[0] = max(cashe[0],cashe[1]);
    cashe[2] = max(cashe[1],cashe[2]);
    cashe[1] = max(cashe[0],cashe[2]);
    
    cashe[0] += board[nowN][0];
    cashe[1] += board[nowN][1];
    cashe[2] += board[nowN][2];
    getmaxresult(nowN-1);
    
}
void getminresult(int nowN){
    if(nowN == 0) return;
    cashe[0] = min(cashe[0],cashe[1]);
    cashe[2] = min(cashe[1],cashe[2]);
    cashe[1] = min(cashe[0],cashe[2]);
    
    cashe[0] += board[nowN][0];
    cashe[1] += board[nowN][1];
    cashe[2] += board[nowN][2];
    getminresult(nowN-1);
    
}


int main(void){
    get();
    
    cashe[0] = board[N][0];
    cashe[1] = board[N][1];
    cashe[2] = board[N][2];
    getmaxresult(N-1);
    cout<<max(cashe[0],max(cashe[1],cashe[2]))<<" ";
    
    cashe[0] = board[N][0];
    cashe[1] = board[N][1];
    cashe[2] = board[N][2];
    getminresult(N-1);
    cout<<min(cashe[0],min(cashe[1],cashe[2]));
}



