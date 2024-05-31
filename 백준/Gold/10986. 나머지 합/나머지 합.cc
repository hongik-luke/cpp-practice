#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int N,M;
int hap_arr[1000100];
int cnt_arr[1000100];
void input(){
    cin>>N>>M;
    int hap = 0;
    int n;
    for(int i = 1 ; i <= N ; i++){
        cin>>n;
        hap += n;
        hap %= M;
        hap_arr[i] = hap;
    }
}
int64_t getresult(){
    int64_t result = 0;
    for(int i = 1 ; i <= N ; i++){
        if(hap_arr[i] == 0) result++;
        
        if(cnt_arr[hap_arr[i]] != 0) result += cnt_arr[hap_arr[i]];
        cnt_arr[hap_arr[i]]++;
    }
    return result;
}
int main(void){
    input();
    memset(cnt_arr,0,sizeof(cnt_arr));
    cout<<getresult();
}