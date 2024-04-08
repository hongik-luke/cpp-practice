#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;


int Map[16] = {0,};
int n;
int cnt = 0;

void Search(int now){
    if(now == n+1)
    {
        cnt++; 
        return;
    }

    for(int i = 0 ; i < n ; i++){
        if(Map[i] != 0)
            continue;
        
        int endflag = 0;
        int downi = i;
        for(int j = 1 ; j < now ; j++){
            downi--;
            if(downi < 0)
                break;
            if(Map[downi]+j == now)
            {
                endflag = 1;
                break;
            }
        }
        int upi = i;
        for(int j = 1 ; j < now ; j++){
            upi++;
            if(upi > n-1)
                break;
            if(Map[upi]+j == now)
            {
                endflag = 1;
                break;
            }
        }
        if(endflag != 1){
            Map[i] = now;
            Search(now+1);
            Map[i] = 0;
        }
    }
}
int main(void){
    cin>>n;
    Search(1);
    cout<<cnt;
}
            