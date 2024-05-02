#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;


int cashe[110][12];
int len , k;
int numarr[110];

void get(){
    cin>>len>>k;
    for(int i = 0 ; i < len ; i++)
        cin>>numarr[i];
    sort(numarr,numarr+len);
    memset(cashe,-1,sizeof(cashe));
}

int square(int n){return n*n;}

int getresult(int first, int last){

    int minresult = 87654321;
    
    for(int j = numarr[first] ; j <= numarr[last] ; j++){
        int nowresult = 0;
        for(int i = 0 ; i <= last-first ; i++){
            nowresult += square(j - numarr[i+first]);
        }
        minresult = min(nowresult , minresult);
    }
    //cout<<index<<" "<<index+howmany-1<<" "<<minresult<<"\n";
    return minresult;
}
int seperate(int index , int parts){
    if(index == len) return 0;
    if(parts == 0) return 98765443;
    
    int ret = cashe[index][parts];
    if(ret != -1) return ret;   
    ret = 7654321;
    
    for(int i = 1 ; i+index <= len ; i++){
        ret = min(ret, getresult(index,index+i-1) + seperate(index+i, parts-1));
        //cout<<index<<" "<<index+i-1<<" "<<index+i<<" "<<parts-1<<" "<<ret<<"\n";
    }
    
    return ret;
    
}
int main(void){
    int N;
    cin>>N;
    for(int i = 0 ; i < N ;i++){
        get();
        cout<<seperate(0, k)<<"\n";
    }
}








