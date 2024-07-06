#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map> 
using namespace std;
int T,N,M;
int arr1[1001];
int arr2[1001];
vector<int> v1;
vector<int> v2;
void input(){
    cin>>T;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr1[i];
    }
    cin>>M;
    for(int i = 0 ; i < M ; i++){
        cin>>arr2[i];
    }
}
map<int, int> ma;

void getv1(int beforeidx, int now){
    if(beforeidx == N-1) return;
    
    v1.push_back(now+arr1[beforeidx+1]);
    getv1(beforeidx+1,now+arr1[beforeidx+1]);
}
void getv2(int beforeidx, int now){
    if(beforeidx == M-1) return;
    
    v2.push_back(now+arr2[beforeidx+1]);
    getv2(beforeidx+1,now+arr2[beforeidx+1]);
}
void getv(){
    for(int i = 0 ; i < N; i++){
        v1.push_back(arr1[i]);
        getv1(i,arr1[i]);
    }
    sort(v1.begin(),v1.end());
     for(int i = 0 ; i < M; i++){
        v2.push_back(arr2[i]);
        getv2(i,arr2[i]);
    }
    sort(v2.begin(),v2.end());
    
}
void v2_mapping(){
    int len = v2.size();
    int cnt = 1;
    for(int i = 0 ; i < len-1 ; i++){
        if(v2[i] == v2[i+1]) cnt++;
        else{
            ma.insert(make_pair(v2[i], cnt));
            cnt = 1;
        }
    }
    ma.insert(make_pair(v2[len-1], cnt));

}
int64_t get(){
    int64_t ret = 0;
    int len = v1.size();
    for(int i = 0 ; i < len ; i++){
        int gett = T-v1[i];
        if(ma.find(gett) != ma.end()){
            ret += ma.find(gett)->second;
        }
    }
    return ret;
}
int main(void){
    input();
    getv();
    v2_mapping();
    cout<<get();
}





