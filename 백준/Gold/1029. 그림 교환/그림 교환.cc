#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int N;
int arr[17][17];
void input(){
    cin>>N;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            scanf("%1d",&arr[i][j]);
        }
    }
}
int cashe[17][12][(1<<15)+10];
int get(int bit, int now, int price){

    if(bit == 0) return 0;
    
    if(cashe[now][price][bit] != -1) return cashe[now][price][bit];
    int& ret = cashe[now][price][bit];
    ret = 0;
    
    for(int i = 0; i < N ; i++){
        if((bit & (1<<i)) != 0){
            if(arr[now][i] >= price)
                ret = max(ret, get(bit-(1<<i),i,arr[now][i])+1);
        }
    }
    
    return ret;
}
int main() {
    input();
    memset(cashe,-1,sizeof(cashe));
    cout<<get((1<<N)-2,0,0)+1;

}