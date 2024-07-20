#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
int N;
vector<int> v1[300010];

bool check[300010];
void input(){
    cin>>N;
    int n1,n2;
    for(int i = 0; i < N-1 ; i++){
        cin>>n1>>n2;
        v1[n2].push_back(n1);
        v1[n1].push_back(n2);
    }
    memset(check,false,sizeof(check));
}
int64_t result = 0;
int retu(int idx){
    int ret = 1;
    
    int len = v1[idx].size();
    for(int i = 0; i < len ; i++){
        if(check[v1[idx][i]]) continue;
        check[v1[idx][i]] = true;
        int64_t n = retu(v1[idx][i]);
        
        result += (n*(n-1)/2 + n*(N-n));
        ret += n;
    }
    
    return ret;
}

int main(void){
    FASTIO;
    
    input();
    check[1] = true;
    retu(1);
    
    cout<<result;
}