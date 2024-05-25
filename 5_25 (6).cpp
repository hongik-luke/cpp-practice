#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int N;
vector<int> minusv;
vector<int> plusv;

void input(){
    cin>>N;
    int n;
    for(int i = 0 ; i < N ; i++){
        cin>>n;
        if(n < 0) minusv.push_back(n);
        else plusv.push_back(n);
    }
}

void result(){
    int pidx1,pidx2;
    int returnmin = 2000000001;
    
    if(minusv.size() >= 2){
        returnmin = abs(minusv[minusv.size()-2]+minusv[minusv.size()-1]);
        pidx1 = minusv[minusv.size()-2];
        pidx2 = minusv[minusv.size()-1];
    }
    if(plusv.size() >= 2){
        if(returnmin > abs(plusv[0]+plusv[1])){
            returnmin = abs(plusv[0]+plusv[1]);    
            pidx1 = plusv[0];
            pidx2 = plusv[1];
        }
    }
    
    for(int i = 0 ; i < minusv.size() ; i++){
        if(plusv.size() == 0) break;
        int lo = 0 ; int hi = plusv.size()-1;
        int mid;
        while(lo < hi){
            mid = (lo + hi)/2;
            if(minusv[i] + plusv[mid] > 0)
                hi = mid;
            else
                lo = mid+1;
        }

        if(returnmin > abs(minusv[i]+plusv[lo])){
            returnmin = abs(minusv[i]+plusv[lo]);
            pidx1 = minusv[i];
            pidx2 = plusv[lo];
        }
    
        if(lo != 0){
            if(returnmin > abs(minusv[i]+plusv[lo-1])){
                returnmin = abs(minusv[i]+plusv[lo-1]);
                pidx1 = minusv[i];
                pidx2 = plusv[lo-1];
            }
        }
        //cout<<pidx1<<pidx2<<"\n";
    }
    
    cout<<pidx1<<" "<<pidx2;
}

int main(void){
    input();
    result();
}

