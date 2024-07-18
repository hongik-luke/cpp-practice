#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int arr[18][18];
int start = 0;
int K;
void input(){
    string str;
    cin>>N;
    for(int i = 0 ;i < N ; i++){
        for(int j = 0 ;j < N ; j++){
            cin>>arr[i][j];
        }  
    }  
    cin>>str;
    cin>>K;
    for(int i = 0; i < N ; i++){
        if(str[i] == 'Y'){
            start += (1<<i);
            K--;
            if(K < 0) K = 0;
        }
    }
}
int cashe[(1<<16)+10][18];

int get(int now ,int remain){
    //기저
    if(remain == 0) return 0;
    
    if(cashe[now][remain] != -1) return cashe[now][remain];
    int& ret = cashe[now][remain];
    ret = 98765432;
    
    for(int i = 0; i < N; i++){
        if((now & (1<<i)) == 0){
            int min_ = 9876543;
            for(int j = 0; j < N ; j++){
                if((now & (1<<j)) != 0 && min_ > arr[j][i]){
                    min_ = arr[j][i];
                }
            }
            ret = min(ret, get(now+(1<<i),remain-1) + min_);
        }
    }
    return ret;
    
}
int main() {
    input();
    
    memset(cashe,-1,sizeof(cashe));
    int n = get(start,K);
    if(n >= 987654) cout<<-1;
    else cout<<n;
}

