#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int,int> ii;
vector<ii> v[55];
int get_price[55];
int INF = 1e9;
int N,M,F,L;
void input(){
    cin>>N>>F>>L>>M;
    int n1,n2,n3;
    for(int i = 0; i < M ; i++){
        cin>>n1>>n2>>n3;
        v[n1].push_back({n2,n3});
    }
    for(int i = 0; i < N ; i++)
        cin>>get_price[i];
    
    for(int i = 0; i < N ; i++){
        int len  = v[i].size();
        for(int j = 0 ; j < len ; j++)
            v[i][j].second -= get_price[v[i][j].first];
    }
}
queue<int> cycle;
bool check[55];
bool BFS(){
    while(!cycle.empty()){
        int c = cycle.front();
        cycle.pop();
        
        int len = v[c].size();
        for(int i = 0; i < len ; i++){
            if(check[v[c][i].first]) continue;
            check[v[c][i].first] = true;
            
            cycle.push(v[c][i].first);
        }
    }
    
    if(check[L]) return true;
    else return false;
}
int64_t price[55];
bool get(){
    for(int i = 0 ;i < N ; i++)
        price[i] = INF;
    price[F] = -get_price[F];
    
    for(int i = 0 ; i < N ; i++){
        bool check = false;
        for(int here = 0 ; here < N ; here++){
            int len = v[here].size();
            for(int j = 0 ; j < len ; j++){
                int there = v[here][j].first;
                int cost = v[here][j].second;
                
                if(price[here] < INF-9999 && price[there] > price[here] + cost){
                    price[there] = price[here] + cost;
                    if(i == N-1){
                        cycle.push(there);
                    }
                }
            }
        }
    }
    return true;
}
int main() {
    input();
    get();
        
    if(price[L] == INF){
        cout<<"gg";
        return 0;
    }
    if(BFS()) cout<<"Gee";
    else cout<<-price[L];
}