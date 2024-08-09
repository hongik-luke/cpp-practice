#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
string str;
int check[30];
int main() {
    cin>>N;
    cin>>str;
    memset(check,-1,sizeof(check));
    int ret = 0;
    int len = str.size();
    int cnt = 0;
    int now = -1;
    for(int i = 0 ; i < len ; i++){
        if(check[str[i]-'a'] == -1){
            if(cnt == N){
                int nowmin = 99999999;
                for(int j = 0 ; j < 28 ; j++){
                    if(check[j] != -1){
                        nowmin = min(nowmin,check[j]);
                    }
                }
                for(int j = 0 ; j < 28 ; j++){
                    if(check[j] == nowmin){
                        check[j] = -1;
                    }
                }
                ret = max(i-now-1,ret);
                now = nowmin;
                
            }
            else{
                cnt++;
            }
        }
        check[str[i]-'a'] = i;
    }
    ret = max(len-now-1,ret);
    cout<<ret;
}