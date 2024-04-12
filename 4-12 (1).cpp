#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)

using namespace std;
int N;
int64_t M;
int original[6][6];
int arr[37][6][6];
int64_t arrnum[37] = {1,};
bool cnt[37] = {false,};




void makearr(int Now){
    if(Now == 37)
        return;
    int sum;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++){
            sum = 0;
            for(int k = 0 ; k < N ; k++){
                sum += arr[Now-1][i][k]*arr[Now-1][k][j];
            }
            arr[Now][i][j] = sum%1000;
        }
    makearr(Now+1);
    return;
}

void makearrnum(int Now){
    if(Now == 37)
        return;
    arrnum[Now] = arrnum[Now-1]*2;
    makearrnum(Now+1);
    return;
}



int main(void){

    cin>>N>>M;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin>>original[i][j];
    
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)            
            arr[0][i][j] = original[i][j];
    makearr(1);
    
    arrnum[0] = 1;
    makearrnum(1);
    
    for(int i = 36 ; i != -1 ; i--){
        if(M >= arrnum[i]){
            cnt[i] = true;
            M = M - arrnum[i];
            if(M == 0)
                break;
        }
    }
    int result[6][6];
    int check = 0;
    for(int p = 0 ; p < 37 ; p++){
        if(!cnt[p])
            continue;
        if(check == 0){
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N ; j++){
                    result[i][j] = arr[p][i][j]%1000;    
                }
            }
            check = 1;
            continue;
        }
        int temp[6][6];
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                temp[i][j] = result[i][j];   
        
        
        int sum;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                sum = 0;
                for(int k = 0 ; k < N ; k++)
                    sum += temp[i][k]*arr[p][k][j];
                result[i][j] = sum%1000;
            }
        }
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++)            
            cout<<result[i][j]<<" ";
        cout<<"\n";
    }
}


