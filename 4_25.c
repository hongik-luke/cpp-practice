#include <iostream>
#include <cstring>
using namespace std;

int casher[2500][2500];

int SomeObscureFunction(int n , int r){
    
    if(r == 0 || n == r)
        return 1;
    int& ret = casher[n][r];
    if(ret != -1)
        return ret;
    
    return ret = SomeObscureFunction(n-1,r-1) + SomeObscureFunction(n-1,r); // 이렇게 써지는거 짱신기함!
   
    
}

int main(void){
    memset(casher,-1,sizeof(casher));
    cout<<SomeObscureFunction(52,12)<<"\n";

}