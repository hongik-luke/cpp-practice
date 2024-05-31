#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int N,K;
int arr[10000];
int result_arr[10000];
void getresult(){
    int i = 0;
    int idx = 0;
    int cnt = 0;
    while(cnt < N){
        i++;
        idx = (idx+1)%10000;
        if(i%K == 0){
            result_arr[cnt++] = arr[idx];
        }
        else{
            arr[(idx+N-cnt)%10000] = arr[idx];
        }
    }
}
int main(void){
    cin>>N>>K;
    for(int i = 1 ; i <= N ; i++)
        arr[i] = i;
    
    getresult();
    cout<<"<";
    for(int i = 0 ; i < N-1 ; i++){
        cout<<result_arr[i]<<", ";
    }
    cout<<result_arr[N-1]<<">";
       
}