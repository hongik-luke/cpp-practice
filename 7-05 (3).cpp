#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int arr1[31];
int arr2[31];
int N,M;
int v1num,v2num;
vector<int> v1;
vector<int> v2;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N/2 ; i++){
        cin>>arr1[i];
    }
    
    for(int i = N/2 ; i < N ; i++){
        cin>>arr2[i-N/2];
    }
    v1num = N/2;
    v2num = N-v1num;
    

}
void getv(){
    
    for(int i = 0 ; i < (1<<v1num) ; i++ ){
        int64_t num = 0;
        for(int j = 0 ; j <= v1num-1 ; j++){
            if(((1<<j)&i) != 0) num += arr1[j];
            
        }
        if(num <= M) v1.push_back(num);
        
        
    }
    sort(v1.begin(),v1.end());
    
    for(int i = 0 ; i < (1<<v2num) ; i++ ){
        int64_t num = 0;
        for(int j = 0 ; j <= v2num-1 ; j++){
            if(((1<<j)&i) != 0) num += arr2[j];
        }
        
        if(num <= M) v2.push_back(num);
        
    }
    sort(v2.begin(),v2.end());
}
int64_t get(){
    int64_t ret = 0;
    int len = v1.size();
    int len2 = v2.size();
    for(int i = 0; i < len ; i++){
        int remain = M - v1[i];
        
        int lo = 0;
        int hi = len2-1;
        int mid;
        
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(remain >= v2[mid]){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        
        ret += lo;
    }
    return ret;
}



int main(void){
    input();
    getv();
    cout<<get();
}