#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int N;
pair<int,int> arr[15];
void input(){
    cin>>N;
    for(int i = 0; i < N ; i++){
        cin>>arr[i].first>>arr[i].second;
    }
}

int get(){
    int result = 2000000000;
    for(int i = (1<<N)-1 ; i > 0 ; i--){
        int S = 1, B = 0;
        for(int j = 0 ; j < N ; j++){
            if(i & (1<<j)){
                S *= arr[j].first;
                B += arr[j].second;
            }    
        }
        result = min(result,abs(S-B));
    }
    return result;
}
int main(void){
    input();
    cout<<get();
}









