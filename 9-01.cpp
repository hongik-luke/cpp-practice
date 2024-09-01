#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;
vector<int> parent;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);  
    
    return parent[x];
}
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}
bool connected(int x, int y) {
    return find(x) == find(y);
}
int N,M;
int cnt[3010];
void input(){
    cin>>N>>M;
    int n1,n2;
    parent.resize(N+1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;  
    }
    for(int i = 0 ; i < M ;i++){
        cin>>n1>>n2;
        cnt[n1]++;
        cnt[n2]++;
        unionSets(n1, n2);
    }

}

bool get(){
    int ret_cnt = 0;
    for(int i = 1 ; i <= N ; i++){
        if(!connected(1,i)){
            return false;
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        if(cnt[i]%2 == 1) ret_cnt++;
    }

    if(ret_cnt == 0 || ret_cnt == 2) return true;
    else return false;
}
int main(void){
    input();
    if(get()) cout<<"YES";
    else cout<<"NO";
}