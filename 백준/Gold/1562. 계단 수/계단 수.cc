#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N;
int64_t cashe[103][10][(1<<10)];

int64_t get(){
    
    for(int i = 0 ; i <= 9 ; i++){
        cashe[1][i][(1<<i)] = 1;
    }
    for(int n = 1 ; n < N ; n++){
        for(int j = 0 ; j <= 9 ; j++){
            if(j != 0){
                for(int k = 0 ; k <= (1<<10) ; k++){
                    if(cashe[n][j-1][k] != 0){
                        cashe[n+1][j][(k | (1<<j))] += cashe[n][j-1][k];
                        //cout<<j<<" "<<k<<"\n";
                    }
                }
            }
            if(j != 9){
                for(int k = 0 ; k <= (1<<10) ; k++){
                    if(cashe[n][j+1][k] != 0)
                        cashe[n+1][j][(k | (1<<j))] += cashe[n][j+1][k];
                }
            }
            for(int k = 0 ; k <= (1<<10) ; k++){    
                cashe[n+1][j][k]%=1000000000;
            }
        }
    }
    int64_t result = 0;
    for(int i = 1 ; i <= 9 ; i++){
        result+= cashe[N][i][1023];
    }
    return result%1000000000;
}

int main(void){
    memset(cashe,0,sizeof(cashe));
    
    cin>>N;
    cout<<get();
}