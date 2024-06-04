#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
// 2463 비용 = 상호 배타적 집합 끝나면 꼭! 꼭! 풀어보기
// 간선을 입력받고 정렬한 후 가중치를 둬서 저장한다.
// 간선이 큰 것부터 연결시킨다 
// 1) 만약 같은 집합이라면 무시한다.
// 2) 이 때 각 집합의 크기를 곱한 수 에 가중치를 곱해서 정답에 더하고 나눠준다.
    // 3) 따로따로이던 집합 두개를 같은 집합으로 만들어 준다.
// 간선이 모두 연결되었다면 리턴하여 정답을 출력한다.
int64_t result = 0;
int N,M;
int64_t all = 0;
struct pos{
    int from;
    int to;
    int value;
};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value < b.value;
    }
};
struct dis{
    vector<int> parent,rank;
    vector<int64_t> size;
    dis(int N) : parent(N+1), rank(N+1,1),size(N+1,1){
        for(int i = 1 ; i <= N ; i++)
            parent[i] = i;
    }
    int find(int idx){
        if(idx == parent[idx]) return idx;
        return parent[idx] = find(parent[idx]);
    }
    bool marge(int u,int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        
        if (rank[u] > rank[v]) swap(u, v);
	    parent[u] = v;
	    size[v] = size[u]+size[v];
	    if (rank[u] == rank[v]) rank[v]++;
	    return true;
    }
    int64_t getsize(int idx){
        return size[find(idx)];
    }
};
priority_queue<pos,vector<pos>,cmp> pq;
void input(){
    cin>>N>>M;
    pos n;
    for(int i = 0 ; i < M ; i++){
        cin>>n.from>>n.to>>n.value;
        pq.push(n);
        all += n.value;
    }
}

void get_result(){
    pos n;
    dis a(N);
    while(!pq.empty()){
        n = pq.top();
        pq.pop();
        if(a.find(n.from) == a.find(n.to)){
            //cout<<n.value;
            all -= n.value;
            continue;
        }
        result += all*(int64_t)(a.getsize(n.from)*a.getsize(n.to));
        result %= 1000000000;
        a.marge(n.from, n.to);
        all -= n.value;
    }
    
}
int main(void){
    input();
    get_result();
    cout<<result;
}