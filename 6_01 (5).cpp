#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
vector <int> v;
void input(){
    cin>>N;
    int n;
    for(int i = 0 ; i < N ; i++){
        cin>>n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
}

int64_t get(){
    int64_t cnt = 0;
    for(int i = 0 ; i < N ; i++){
        if(v[i] > 0) break;
        int pick1 = v[i];
        
        int lo = i+1; int hi = N-1;
        while(lo < hi){
            if(pick1 + v[lo] + v[hi] == 0){
                if(v[lo] == v[lo+1] || v[hi] == v[hi-1]){
                    if(v[lo] == v[hi]){
                        cnt += ((hi-lo+1)*(hi-lo)/2);
                        break;
                    }
                    else{
                        int v1 = 1 ; int v2 = 1;
                        while(v[lo] == v[lo+1]){
                            v1++;
                            lo++;
                        }
                        while(v[hi-1] == v[hi]){
                            v2++;
                            hi--;
                        }
                        lo++;
                        hi--;
                        cnt += v1*v2;
                    }
                }
                else{
                    cnt++;
                    if(abs(v[lo] - v[lo+1]) >= abs(v[hi] - v[hi-1])){
                        hi--;
                    }
                    else lo++;
                }
                
                
            }
            else if(pick1 + v[lo] + v[hi] < 0){
                lo++;
            }
            else hi--;
        }
    }
    return cnt;
}

int main(void){
    input();    
    cout<<get();
}










