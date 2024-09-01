#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;

int num,len;
vector<int> sosu;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}
int dp[40010];
void get(){
    dp[0] = 1; 

    for (int i = 0 ; i < len ; i++){
        int p = sosu[i];
        for (int j = p ; j <= num; j++) {
            dp[j] = (dp[j] + dp[j - p]) % 123456789;
        }
    }
}
int main(void){
    FASTIO;
    cin>>num;

    for(int i = 1 ; i <= num ; i++){
        if(isPrime(i)) sosu.push_back(i);
    }
    
    len = sosu.size();
    get();
    cout<<dp[num];
}