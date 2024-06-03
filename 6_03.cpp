#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
pair<int,int> elecline[105];

void input(){
    cin>>N;
    for(int i = 0 ; i < N; i++){
        cin>>elecline[i].first>>elecline[i].second;   
    }
    sort(elecline,elecline+N);
}
int cashe[105][505];
int get(int idx, int bhigh){
    if(idx == N) return 0;
    
    int& ret = cashe[idx][bhigh];
    if(ret != -1) return ret;
    
    ret = get(idx+1,bhigh)+1;
    if(bhigh < elecline[idx].second)
        ret = min(ret, get(idx+1, elecline[idx].second));
        
    return ret;
}


int main(void){
    input();
    memset(cashe,-1,sizeof(cashe));
    cout<<get(0, 0);
}