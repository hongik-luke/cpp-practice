#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> up(500100,0);
vector<int> down(500100,0);
int result[500100]; // 1 ~ H 
int min_ = 1000000;
int halfN, H;

void input(){
    cin>>halfN>>H;
    int n;
    for(int i = 0 ; i < halfN ; i++){
        cin>>n;
        if(i%2 == 0) up[H-n+1]++;
        else down[n]++;
    }
    halfN = halfN/2;
}

void make_result(){
    memset(result,0,sizeof(result));
    for(int i = 1 ; i <= H ; i++){
        result[i] += up[i];
        up[i+1] += up[i];
    }
    for(int i = H ; i >= 1 ; i--){
        result[i] += down[i];
        down[i-1] += down[i];
        min_ = min(min_,result[i]);
    }
        
 
}

void print_result(){
    int cnt = 0;
    for(int i = 1 ; i <= H ; i++){
        if(result[i] == min_) cnt++;
    }
    cout<<min_<<" "<<cnt<<"\n";
}

int main(void){
    input();
    make_result();
    print_result();
}