#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int main(void){
    while(1){
        int n1,n2;
        cin>>n1>>n2;
        if(n1 == 0 && n2 == 0) break;
        if(n1 > n2) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
}