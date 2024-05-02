#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;
int M;
int numarr[501][501] = {0,}; //0부터 유의미 M-1까지 유의미
int original_num[501];
int dp[501][501];

void get_n_clear(){
    cin>>M;
    for(int i = 0 ; i < M ; i++)
        cin>>original_num[i];
    for(int i = 0 ; i < M ; i++)
        numarr[i][i] = original_num[i];
    for(int i = 0 ; i < M ; i++){
        for(int j = i+1 ; j < M ; j++){
            numarr[i][j] = numarr[i][j-1] + original_num[j];
        }
    }
    memset(dp,98765432,sizeof(dp));
    
}


int getresult(){
    for(int i = 0 ; i < M ; i++)
        dp[i][i] = 0;
        
    for(int i = 1 ; i < M ; i++){
        for(int j = 0 ; j < M ; j++){
            //dp[j][j+i] 구하는 중
            if(j+i >= M)
                break;
            for(int p = 0 ; p < i ; p++){
                
                dp[j][j+i] = min(dp[j][j+i],dp[j][j+p] + dp[j+p+1][j+i]);
            }
            dp[j][j+i] += numarr[j][j+i];
        }
    }
    return dp[0][M-1];
}




int main(void){ 
    int N;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        get_n_clear();
        cout<<getresult()<<"\n";
    }
    
}






