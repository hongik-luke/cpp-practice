#include <string>
#include <vector>
#include <string.h>
#include <cmath>
int n[300];
using namespace std;
bool check(int first, int len){
    if(len == 1) return true;
    int mid = first + len/2;
    
    if(n[mid] == 0){
        if(n[mid-(len+1)/4] == 1 || n[mid+(len+1)/4] == 1) return false;
    }
   
    bool flag1,flag2;
    flag1 = check(first,len/2);
    flag2 = check(mid+1,len/2);
    if(flag1&& flag2) return true;
    else return false;
        
    
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    int num_len[] = {1,3,7,15,31,63,127,255};
    int len = numbers.size();
    for(int i = 0 ; i < len ; i++){
        memset(n,0,sizeof(n));
        int j;
        for(j = 0; numbers[i] != 0 ; j++){
            if((numbers[i] & (1LL<<j)) == 0){
                n[j] = 0;
            }
            else{
                n[j] = 1;
                numbers[i] -= (1LL<<j);
            }
        }
        int a = 0;
        while(1){
            if(j > num_len[a]) a++;
            
            else {
                j = num_len[a];
                break;
            }
        }
        
        if(check(0,j)) answer.push_back(1);
        else answer.push_back(0);
        
    }
    
    return answer;
}