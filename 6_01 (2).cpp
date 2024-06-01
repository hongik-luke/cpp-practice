#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector <int64_t> num_;
int N;
int min_arr[3];
int64_t  min_ = 10000000000;
void input(){
    cin>>N;
    int n;
    for(int i = 0 ; i < N; i++){
        cin>>n;
        num_.push_back(n);
    }
    sort(num_.begin(),num_.end());
}

void getresult(){
    for(int i = 0 ; i < N-2 ; i++){
        int pick1 = num_[i];
        int lo = i+1; int hi = N-1;
        while(lo < hi){
            if(abs(pick1 + num_[lo] + num_[hi]) < min_){
                min_ = abs(pick1 + num_[lo] + num_[hi]);
                min_arr[0] = pick1;
                min_arr[1] = num_[lo];
                min_arr[2] = num_[hi];
            }
            if(num_[lo] + num_[hi] + pick1 > 0){
                hi--;
            }
            else lo++;
        }
    }
    
}

int main(void){
    input();
    getresult();
    cout<<min_arr[0]<<" "<<min_arr[1]<<" "<<min_arr[2];
}