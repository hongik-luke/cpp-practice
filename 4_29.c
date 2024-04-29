#include <iostream>
#include <cstring>
using namespace std;

int stair[310];
int cash[310][4];
int N;

int SomeObscureFunction(int now, int cnt){
    
    if(now > N || cnt == 3)
        return -3000000;
    if(now == N)
        return stair[N];
        
    int& ret = cash[now][cnt];
    if(ret != -1)
        return ret;    
    
    int result1 = stair[now] + SomeObscureFunction(now+1,cnt+1);
    int result2 = stair[now] + SomeObscureFunction(now+2,1);
    if(result1 >= result2) return ret =  result1;
    else return ret = result2;

}
void getthem(){
    cin>>N;
    stair[0] = 0;
    for(int i = 1 ; i <= N ; i++)
        cin>>stair[i];
    memset(cash,-1,sizeof(cash));
}

int main(void){
    getthem();
    cout<<SomeObscureFunction(0,0);
}