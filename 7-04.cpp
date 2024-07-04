#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N,M;
bool check[27];
vector<string> s;
void input(){
    cin>>N>>M;
    string str;
    for(int i = 0 ; i < N ; i ++){
        cin>>str;
        s.push_back(str);
    }
}
int maxget = 0;
void get(int lastidx, int remain){
    if(remain == 0){
        int cnt = 0;
        for(int i = 0 ; i < N ; i ++){
            int len = s[i].size();
            bool flag = true;
            for(int j = 4 ; j < len-4 ; j++){
                if(!check[(int)s[i][j] - (int)'a']){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        maxget = max(maxget,cnt);
        return;
    }
    
    for(int i = lastidx+1 ; i < 26 ; i++){
        if(check[i]) continue;
        check[i] = true;
        get(i,remain-1);
        check[i] = false;
    }
}
int main(void){
    input();
    if(M < 5) cout<<0;
    else{
        memset(check,false,sizeof(check));
        M = M-5;
        check[13] = true;
        check[0] = true;
        check[19] = true;
        check[8] = true;
        check[2] = true;
        get(-1,M);
        cout<<maxget;
    }
}