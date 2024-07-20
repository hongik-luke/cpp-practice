#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int N;
double arr[22][22];
void input(){
    cin>>N;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            cin>>arr[i][j];
            arr[i][j]/=100;
        }
    }
}
double cashe[(1<<20)+10];
double get(int idx, int bit){
    if(idx == N || bit == 0) return 100;
    
    if(cashe[bit] != -1.0) return cashe[bit];
    double& ret = cashe[bit];
    ret = 0;
    
    for(int i = 0; i < N ; i++){
        if((bit & (1<<i)) != 0){
            ret = max(ret, (get(idx+1,bit-(1<<i))*arr[idx][i]));
        }
    }

    return ret;
}
int main() {
    input();
    for(int j = 0; j < (1<<20)+10 ; j++){
        cashe[j] = -1.0;
    }
    
    double ret = get(0,(1<<N)-1);
    printf("%0.10lf",ret);
}