#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int N;
int arr[10010];
vector<int> v[10010];
vector<int> retv;
void input(){
    cin>>N;
    int n1,n2;
    for(int i = 1; i <= N ; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < N-1 ; i++){
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
}
bool check[10010];
int cashe[10010][2];
void get(int idx){
    check[idx] = true;
    cashe[idx][0] = 0;
    cashe[idx][1] = arr[idx];
    
    int len = v[idx].size();
    for(int i = 0 ; i < len ; i++){
        if(check[v[idx][i]]) continue;
        
        get(v[idx][i]);
        
        cashe[idx][0] += max(cashe[v[idx][i]][0],cashe[v[idx][i]][1]);
        cashe[idx][1] += cashe[v[idx][i]][0];
    }
}

void get_retv(int idx, bool beforein_out){
    check[idx] = true;
    if(cashe[idx][1] > cashe[idx][0] && beforein_out == false){
        retv.push_back(idx);
        int len = v[idx].size();
        for(int i = 0 ; i < len ; i++){
            if(check[v[idx][i]]) continue;
        
            get_retv(v[idx][i], true);
        }
    }
    else{
        int len = v[idx].size();
        for(int i = 0 ; i < len ; i++){
            if(check[v[idx][i]]) continue;
        
            get_retv(v[idx][i],false);
        }
    }
}
int main() {
    input();
    //1) 최대 구하기
    memset(check,false,sizeof(check));
    memset(cashe,-1,sizeof(cashe));
    get(1);
    cout<<max(cashe[1][0],cashe[1][1])<<"\n";
    
    //2) 정점 구하기 및 출력
    memset(check,false,sizeof(check));
    get_retv(1,false);
    int len = retv.size();
    sort(retv.begin(), retv.end());
    for(int i = 0 ; i < len ; i++){
        cout<<retv[i]<<" ";
    }
}
