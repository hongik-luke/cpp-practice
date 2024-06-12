#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

int N;
int bottomcashe[101];
int topcashe[101];


struct pos{
    int x;
    int y;
};
pos arr[110];
bool compare(pos a, pos b) {
    return a.x < b.x;
}
void get(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
        cin>>arr[i].x>>arr[i].y;
    sort(arr,arr+N,compare);

    memset(bottomcashe,-1,sizeof(bottomcashe));
    memset(topcashe,-1,sizeof(topcashe));
}

int top(int index){
    
    if(index == 0)
        return 1;
        
    int& ret = topcashe[index];
    if(ret != -1) return ret;

    ret = 1;
    for(int i = index-1 ; i >= 0 ; i--){
        if(arr[index].y > arr[i].y )
            ret = max(ret, 1+top(i));
    }

    return ret;
}

int bottom(int index){
    if(index == N-1)
        return 1;
        
    int& ret = bottomcashe[index];
    if(ret != -1) return ret;
    
    ret = 1;
    for(int i = index+1 ; i < N ; i++){
        if(arr[index].y < arr[i].y )
            ret = max(ret,1+bottom(i));
    }
    return ret;
}


int search(){
    int minresult = 9876611;
    for(int i = 0 ; i < N ; i++){
        minresult = min(minresult, N - (top(i) + bottom(i)) + 1);   
    }
    
    return minresult;
}

int main(void){
    get();
    cout<<search();
}