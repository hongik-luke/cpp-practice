#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N,K;
string arr[20];
int mul[55];
int a[20];
int len[20];
// 10^m 전처리 
void make_table() {
	mul[0] = 1;
	for (int i = 1; i <= 50; i++) {
		mul[i] = (mul[i - 1] * 10) % K;
	}
	
}
void input(){
    cin>>N;
    for(int i = 0 ; i< N ; i++){
        cin>>arr[i];
    }
    cin>>K;
    for (int i = 0; i < N; i++) {
		len[i] = arr[i].size(); 
		int t = 0;
		for (int j = 0 ; j < len[i] ; j++) {
			t *= 10;
			t += (arr[i][j] - '0'); 
			t %= K;
		}
		a[i] = t;
	}
    
}
int64_t fac(int idx){
    int64_t ret = 1;
    for(int i = 1 ; i <= idx ; i++){
        ret *= i;
    }
    return ret;
}

int64_t gcd(int64_t ret2,int64_t ret1){
    if(ret1 == 0) return ret2;
    else return gcd(ret1,ret2%ret1);
}

int64_t cashe[110][40000];
int64_t get(int before, int bit){
    //cout<<before<<" "<<bit<<"\n";
    if(bit == 0){
        if(before == 0) return 1;
        else return 0;
    }
    if(cashe[before][bit] != -1) return  cashe[before][bit];
    int64_t& ret = cashe[before][bit];
    ret = 0;
    
    for(int i = 0 ; i < N ; i++){
        if((bit&(1<<i)) != 0){
            ret += get((before*mul[len[i]]+a[i])%K,bit-(1<<i));
        }
    }
    return ret;
}
int main(void){
    FASTIO;
    input();
    make_table();
    memset(cashe,-1,sizeof(cashe));
    int64_t ret1 = get(0,(1<<N)-1);
    int64_t ret2 = fac(N);
    int64_t gcdret1 = gcd(ret2,ret1); 
    cout<<ret1/gcdret1<<"/"<<ret2/gcdret1;
}