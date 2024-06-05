#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int,int>> tree[100010];
int N;
int result = 0;
void input(){
    cin>>N;
    int n1,n2,n3;
    for(int i = 0 ; i < N ; i++){
        cin>>n1;
        while(1){
            cin>>n2;
            if(n2 == -1) break;
            cin>>n3;
            tree[n1].push_back(make_pair(n2,n3));
        }
    }
}
int get(int parent, int now){
    int big1 = 0; int big2 = 0;
    int len = tree[now].size();
    int n;
    for(int i = 0 ; i < len ; i++){
        if(tree[now][i].first == 0) break;
        if(tree[now][i].first == parent) continue;
        
        n = get(now, tree[now][i].first) + tree[now][i].second;
        if(n > big1){
            big2 = big1;
            big1 = n;
        }
        else if(n > big2){
            big2 = n;
        }
    }
    result = max(result,big1+big2);
    return big1;
}
int main(void){
    input();
    get(1,1);
    cout<<result;
}