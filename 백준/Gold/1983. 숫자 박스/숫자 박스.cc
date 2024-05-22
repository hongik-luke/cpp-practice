#include <iostream>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int IMF = -9876543;
int N;
int upbox = 0; int downbox = 0;
int uparr[410]; int downarr[410];
int up_zero,down_zero;
int cashe[405][405][405];
void input(){
    cin>>N;
    int num;
    for(int i = 0 ; i < N ; i++){
        cin>>num;
        if(num == 0) continue;
        uparr[upbox] = num;
        upbox++;
    }
    
    for(int i = 0 ; i < N ; i++){
        cin>>num;
        if(num == 0) continue;
        downarr[downbox] = num;
        downbox++;
    }
    up_zero = N - upbox;
    down_zero = N - downbox;
}
int getresult(int boxidx, int upidx, int downidx){
    if(boxidx > N) return 0; 
    
    int& ret = cashe[boxidx][upidx][downidx];
    if(ret != IMF) return ret;
    ret = max(ret, getresult(boxidx+1,upidx,downidx) + uparr[boxidx-upidx]*downarr[boxidx-downidx] ) ;
    
    if(downidx < down_zero){
        ret = max(ret, getresult(boxidx+1,upidx,downidx+1));
    }
    if(upidx < up_zero){
        ret = max(ret, getresult(boxidx+1,upidx+1,downidx));
    }
    return ret;
}

int main(void){
    fill(&cashe[0][0][0],&cashe[402][402][402],IMF);
    input();
    cout<<getresult(0,0,0);
}
