#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
//2042
//1 세그트리 제작
//2 값 변경 제작
//3 구간합 구하기 제작
// 내일^^
int N,K;
int arr[55];
int Notouch = -1;
void input(){
    cin>>N;
    for(int i = 0;  i < N;  i++)
        cin>>arr[i];
    cin>>K;
}

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first < b.first;
    }
};
void make_result(){
    while(K != 0){
        int fix = Notouch+1;
        if(fix == N) break;
        vector<int> after;
        for(int i = fix ; i < N ; i++)
            after.push_back(arr[i]);
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(int i = fix ; i < N ; i++){
            pq.push(make_pair(arr[i],i));
        }
        while(1){
            if(pq.empty()) break;
            pair<int,int> now = pq.top();
            pq.pop();
            if(now.second-fix <= K){
                arr[fix] = now.first;
                K = K - (now.second-fix);
                int idx = fix+1;
                for(int i = 0 ; i < after.size() ; i++){
                    if(after[i] == arr[fix]) continue;
                    arr[idx++] = after[i]; 
                }
                break;
            }
        }
        Notouch++;
    }

}
int main(void){
    input();
    make_result();
    for(int i = 0 ; i < N ; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
}