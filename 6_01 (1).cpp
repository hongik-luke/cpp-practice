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

int64_t get_three(int lomax, int himax){
    if(lomax == himax) return num_[lomax];
    
    int64_t ret = 10000000000;
    int64_t gap = num_[himax]+num_[lomax];
    
    int lo2 = lomax; int hi2 = himax;
    while(lo2 <= hi2){
        int mid2 = (lo2 + hi2)/2;
        if(abs(gap + num_[mid2]) < abs(gap + ret)) ret = num_[mid2];
        
        if(gap + num_[mid2] > 0){
            hi2 = mid2-1;
        }
        else lo2 = mid2+1;
    }
    
    return ret;
}


void getresult(){
    int lo = 0; int hi = N-1;
    while(lo < hi){
        int64_t mid_num = get_three(lo+1,hi-1);
        
        if(abs(num_[lo]+mid_num+num_[hi]) < min_ ){
            min_ = abs(num_[lo]+mid_num+num_[hi]);
            min_arr[0] = num_[lo];
            min_arr[1] = mid_num;
            min_arr[2] = num_[hi];
        }
        
        if(num_[lo]+num_[hi] >= 0){
            hi--;
        }
        else{
            lo++;
        }
    }
}

int main(void){
    input();
    getresult();
    cout<<min_arr[0]<<" "<<min_arr[1]<<" "<<min_arr[2];
}