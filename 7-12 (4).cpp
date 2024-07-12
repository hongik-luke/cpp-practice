#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
int arr[20][2];
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i][0]>>arr[i][1];
    }
}
double memories[140000][20];
double get(int now ,int bit, double dis){
    if(bit == 0) return sqrt((arr[0][0] - arr[now][0])*(arr[0][0] - arr[now][0]) + (arr[0][1] - arr[now][1])*(arr[0][1] - arr[now][1]));
    
    if(memories[bit][now] != 0) return memories[bit][now];
    double& ret = memories[bit][now];
    ret = 77777772.0;
    
    for(int i = 0 ; i < N ; i++){
        if((bit & (1<<i)) != 0){
            double n = sqrt((arr[i][0] - arr[now][0])*(arr[i][0] - arr[now][0]) + (arr[i][1] - arr[now][1])*(arr[i][1] - arr[now][1]));
            ret = min(ret, get(i,bit-(1<<i), dis)+n);
        }
    }
    return ret;
}
int main(void){
    input();
    memset(memories,0,sizeof(memories));
    printf("%lf",get(0,(1<<N)-2, 0.0));
}