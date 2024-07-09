#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
char arr[4][8];
void input(){
    string str;
    for(int i = 0 ; i < 4 ; i++){
        cin>>str;
        for(int j = 0 ; j < 8 ; j++){
            arr[i][j] = str[j];
        }
    }
}

void turn(int idx,int temp){
    int new_arr[8];
    if(temp == 1){
        for(int i = 0; i < 8 ; i++)
            new_arr[i] = arr[idx][(i+7)%8];
    }
    else{
        for(int i = 0; i < 8 ; i++)
            new_arr[i] = arr[idx][(i+1)%8];
    }
    for(int i = 0; i < 8 ; i++){
        arr[idx][i] = new_arr[i];
    }    
}
void get(int num,int temp){
    queue<pair<int,int>> q;
    q.push(make_pair(num,temp));
    int lo = num;
    int lotemp = temp;
    while(lo >= 1){
        if(arr[lo][6] == arr[lo-1][2]){
            break;
        }
        else{
            lo--;
            lotemp = -lotemp;
            q.push(make_pair(lo,lotemp));
        }
    }
    int hi = num;
    int hitemp = temp;
    while(hi <= 2){
        if(arr[hi][2] == arr[hi+1][6]){
            break;
        }
        else{
            hi++;
            hitemp = -hitemp;
            q.push(make_pair(hi,hitemp));
        }
    }
    
    while(!q.empty()){
        pair<int,int> t = q.front();
        //cout<<t.first<<"\n";
        turn(t.first,t.second);
        q.pop();
    }
    
}
int simul(){
    cin>>N;
    int n1,n2;
    for(int i = 0 ; i < N ; i++){
        cin>>n1>>n2;
        n1 = n1-1;
        get(n1,n2);
    }
    int cnt = 0;
    for(int i = 0 ; i < 4; i++){
        if(arr[i][0] == '1'){
            cnt += (1<<i);
        }
    }
    
    return cnt;
}
int main(void) {
    FASTIO;
    input();
    cout<<simul();
    
}