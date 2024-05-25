#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int N;
int arr[100010];

void input(){
    cin>>N;
    int n;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}

void result(){
    int pidx1,pidx2;
    int minresult = 2000000001;
    int nidx1 = 0,nidx2 = N-1;
    while(nidx1 < nidx2){
        if(abs(arr[nidx1] + arr[nidx2]) < minresult){
            minresult = abs(arr[nidx1] + arr[nidx2]);
            pidx1 = nidx1;
            pidx2 = nidx2;
        }
        if(arr[nidx1] + arr[nidx2] == 0) break; 
        else if(arr[nidx1] + arr[nidx2] < 0)
            nidx1++;
        else
            nidx2--;
        
    }
    
    

    cout<<arr[pidx1]<<" "<<arr[pidx2];
}

int main(void){
    input();
    result();
}

