//1863
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int arr[1010][1010];
int cashe[1010][1010];
int N,M;
void input(){
    memset(cashe,0,sizeof(cashe));
    cin>>N>>M;
    for(int i = 0 ; i< N ; i++){
        for(int j = 0 ; j < M ; j++){
            scanf("%1d",&arr[i][j]);
            cashe[i][j] = arr[i][j];
        }
    }
}

int getresult(){
    int result = 0;
    for(int i = N-2 ; i >= 0 ; i--){
        for(int j = M-2 ; j >= 0  ; j--){
            if(cashe[i][j] != 0){
                cashe[i][j] = min(cashe[i+1][j+1], min(cashe[i+1][j],cashe[i][j+1])) +1; 
            }     
        }
    }
    
    for(int i = 0 ; i < N ; i++)
        for(int j = 0; j < M  ; j++)
            result = max(result,cashe[i][j]);

    return result*result;  
}

int main(void){
    input();
    cout<<getresult();
}