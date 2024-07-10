#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cstdlib>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int len = 0;
int N;
int ori[1000001];
int gett[1000001];
void input(){
    cin>>N;
    for(int i = 0 ; i < N;  i++){
        cin>>ori[i];
    }
}
int main(void){
    FASTIO;
    input();
    gett[0] = ori[0];
    len++;
    for(int i = 1 ; i < N ; i++){
        int lo = 0; int hi = len-1;
        if(ori[i] > gett[hi]){
            gett[len] = ori[i];
            len++;
        }
        else{
            int mid;
            while(lo <= hi){
                mid = (lo+hi)/2;
                if(gett[mid] == ori[i]){
                    lo = mid;
                    break;
                }
                else if(gett[mid] > ori[i]) hi = mid-1;
                else lo = mid+1;
            }
            gett[lo] = ori[i];
        }
    }
    cout<<len;
}