#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> v[100];
void input(){
    cin>>N;
    int n1;
    for(int i = 0; i < N ; i++){
        cin>>n1;
        if(i == 0) continue;
        
        v[n1].push_back(i);
    }
}

struct cmp{
    bool operator()(int x,int y){
        return x > y;
    }
};
int get(int idx){
    if(v[idx].size() == 0) return 0;
    
    int ret = 0;
    int len = v[idx].size();
    vector<int> v1;
    for(int i = 0; i < len ; i++){
        v1.push_back(get(v[idx][i]));
    }
    sort(v1.begin(),v1.end(),cmp());
    
    for(int i = 0; i < len ; i++){
        ret = max(ret, i+1+v1[i]);
    }
    return ret;
}

int main(void){
    input();
    cout<<get(0);
}