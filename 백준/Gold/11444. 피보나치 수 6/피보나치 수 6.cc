#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<int64_t, int64_t> m;

int64_t fibo(int64_t n){
    int64_t result;
    int64_t num1, num2;
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    
    if(n%2 == 0){
        if(m.find(n/2) == m.end()){
            num1 = fibo(n/2);
            m.insert(make_pair(n/2, num1));
        }
        else num1 = m[n/2];
        
        if(m.find(n/2-1) == m.end()){
            num2 = fibo(n/2-1);
            m.insert(make_pair(n/2-1, num2));
        }
        else num2 = m[n/2-1];
        
        result = (num1*num1 + 2*num1*num2) % 1000000007;
    }
    else{
        if(m.find(n/2+1) == m.end()){
            num1 = fibo(n/2+1);
            m.insert(make_pair(n/2+1, num1));
        }
        else num1 = m[n/2+1];
        
        if(m.find(n/2) == m.end()){
            num2 = fibo(n/2);
            m.insert(make_pair(n/2, num2));
        }
        else num2 = m[n/2];
        
        result = (num2*num2 + num1*num1) % 1000000007;
    }
    
    m.insert(make_pair(n, result));
    return result;
}


int main(void){
    int64_t n;
    cin>>n;
    m.insert(make_pair(0,0));
    m.insert(make_pair(1,1));
    m.insert(make_pair(1,2));
    cout<<fibo(n);
}