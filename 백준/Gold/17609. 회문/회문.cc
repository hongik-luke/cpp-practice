#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;

int TC;
string str;
int palindrome(int lo, int hi, int cnt){
    if(cnt >= 2) return 2;
    
    int nowcnt = cnt;
    while(lo < hi){
        if(str[lo] == str[hi]){
            lo++;
            hi--;
        }
        else{
            if(nowcnt >= 1) return 2;
            if(str[lo+1] == str[hi] && str[lo] == str[hi-1]){
                
                return min(palindrome(lo+1,hi,cnt+1),palindrome(lo,hi-1,cnt+1));
            }
            else if(str[lo+1] == str[hi]){
                lo++;
                nowcnt++;
            }
            else if(str[lo] == str[hi-1]){
                hi--;
                nowcnt++;
            }
            else{
                return 2;
            }
        }
    }
    
    return nowcnt;

}
int main(){
    FastIO;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        cin>>str;
        int cnt = 0;
        int ret = palindrome(0,str.size()-1,cnt);
        
        
        if(ret == 0) cout<<0<<"\n";
        else if(ret == 1) cout<<1<<"\n";
        else cout<<2<<"\n";
    }
}