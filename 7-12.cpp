#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
int arr[50000];
map<int,int> mp;
vector<int> result;
int all_plus;
void input(){
    cin>>N;
    for(int i = 0 ; i < (1<<N) ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+(1<<N));
    for(int i = 0 ; i < (1<<N) ; i++){
        if(mp.find(arr[i]) == mp.end()){
            mp.insert({arr[i], 0});
        }
    }
    all_plus = arr[(1<<N)-1];
}
void plus_(int t){
    int len = result.size();
    for(int i = 1 ; i <= (1<<len)-1 ; i++){
        int temp = i;
        int now = 0;
        for(int j = 0 ; temp != 0 ; j++){
            if((i & (1<<j)) != 0){
                now += result[j];
                temp -= (1<<j);
            }
        }
        if(now == 0) continue;
        now += t;
        auto it = mp.find(now);
        it->second++;
    }

    result.push_back(t);
}
void get(){
    for(int i = (1<<N)-2 ; i >= 0 ; i--){
        int t = all_plus - arr[i];
        auto it = mp.find(t);
        if(it->second > 0){
            it->second--;
        }
        else{
            plus_(t); 
            if(result.size() == N) return;       
        }
    }
}
int main(void){
    FASTIO;
    input();
    get();
    int len = result.size();
    sort(result.begin(),result.end());

    for(int i = 0 ; i < len ; i++){
        cout<<result[i]<<" ";
    }
}