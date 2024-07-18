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
    int len = str.size();
    for(int i = 0; i < len ; i++){
        if(str[i] == 'Y'){
            start += (1<<i);
        }
    }
}
int cashe[(1<<16)+10];
int get(int nowbit){
    //끝인지 체크
    int cnt = 0;
    for(int i = 0 ; i < N; i++){
        if((nowbit & (1<<i)) != 0) cnt++;
    }
    if(cnt >= K) return 0;
    
    //기저
    if(cashe[nowbit] != -1) return cashe[nowbit];
    int& ret = cashe[nowbit];
    ret = 987654;
    
    //탐색
    for(int i = 0 ;i < N ; i++){
        if((nowbit & (1<<i)) == 0){
            int min_ = 9876543;
            for(int j = 0 ; j < N ; j++){
                if((nowbit & (1<<j)) != 0){
                    if(arr[j][i] < min_){
                        min_ = arr[j][i];
                    }
                    
                }
            }
            ret = min(ret, min_ + get(nowbit+(1<<i)));
        }
    }
    return ret;
}
int main() {
    input();
    
    memset(cashe,-1,sizeof(cashe));
    int n = get(start);
    if(n >= 9876) cout<<-1;
    else cout<<n;
}
