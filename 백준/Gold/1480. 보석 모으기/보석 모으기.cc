#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int N,M,C;
int arr[15];
void input(){
    cin>>N>>M>>C;
    for(int i = 0; i < N ; i++){
        cin>>arr[i];
    }
}
int cashe[12][(1<<13)][25];
int get(int bagnum, int bitcnt, int remainbag){
    if(bagnum == M) return 0;
    
    if(cashe[bagnum][bitcnt][remainbag] != -1) return cashe[bagnum][bitcnt][remainbag];
    int& ret = cashe[bagnum][bitcnt][remainbag];
    ret = 0;
    
    for(int i = 0; i < N ; i++){
        if((bitcnt & (1<<i)) == 0){
            if(remainbag >= arr[i]){
                ret = max(ret, get(bagnum,bitcnt+(1<<i),remainbag-arr[i])+1);
            }
            else{
                ret = max(ret, get(bagnum+1,bitcnt,C));
            }
        }
    }
    return ret;
}
int main() {
    input();
    memset(cashe,-1,sizeof(cashe));
    cout<<get(0,0,C);
}