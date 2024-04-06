#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

class calculate{
    int n;
    int arr[11];
    int oper[4];
    int max,min;
public:
    calculate(int n){
        max = -1000000001;
        min = 1000000001;
        this->n = n;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
    
        for(int i = 0 ; i < 4 ; i++)
            cin>>oper[i];
    }
    void action(int now, int idx);
    int getmax(){return max;}
    int getmin(){return min;}
};
void calculate:: action(int now = 0,int idx = 0){
    
    if(idx == 0)
        now = arr[0];
    if(idx == n-1)
    {
        if(now > max)
            max = now;
        if(now < min)
            min = now;
        return;
    }
    
    for(int i = 0 ; i < 4 ; i++){
        
        if(oper[i] == 0)
            continue;
        oper[i]--;
        if(i == 0)
            action(now+arr[idx+1],idx+1);
        else if(i == 1)
            action(now-arr[idx+1],idx+1);
        else if(i == 2)
            action(now*arr[idx+1],idx+1);
        else
            action(now/arr[idx+1],idx+1);
        
        oper[i]++;
    }
}

int main(void){
    int n;
    cin>>n;
    calculate A(n);
    A.action();
    
    cout<<A.getmax()<<"\n"<<A.getmin();
}


