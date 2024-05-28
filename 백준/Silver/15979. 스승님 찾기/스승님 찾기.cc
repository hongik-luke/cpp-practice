#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N,M;
int gcd(int a,int b){
    if(a == 0 || b == 0) return a+b;
    if(a > b){
        return gcd(b,a%b);    
    }
    else{
        return gcd(a,b%a);  
    }
}
int main(void){
    cin>>N>>M;
    N = abs(N); M = abs(M);
    if(M == 0 && N == 0){
        cout<<0;
    }
    else{
        if (gcd(N,M) == 1) cout<<1;
        else cout<<2;
    }
    return 0;
}