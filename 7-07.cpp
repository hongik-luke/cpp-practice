#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N;
int arr[100000];
int64_t ret;
bool input(){
    cin>>N;
    if(N == 0) return false;
    for(int i = 0 ; i < N; i++){
        cin>>arr[i];
    }
    return true;
}
void get(int lo , int hi){
    if(lo == hi){
        ret = max(ret,(int64_t)arr[lo]);
        return;
    }
    int mid = (lo+hi)/2;
    int64_t now;
    int high = arr[mid];
    int getlo = mid;
    int gethi = mid;
    while(1){
        if(getlo == lo && gethi == hi){
            break;
        }
        else if(getlo == lo){
            gethi++;
            high = min(high,arr[gethi]);
        }
        else if(gethi == hi){
            getlo--;
            high = min(high,arr[getlo]);
        }
        else{
            if(arr[getlo-1] > arr[gethi+1]){
                getlo--;
                high = min(high,arr[getlo]);
            }
            else{
                gethi++;
                high = min(high,arr[gethi]);
            }
        }
        now = high;
        now *= (gethi-getlo+1);
        ret = max(ret,now);
    }
    
    
    get(lo,mid);
    get(mid+1,hi);
    
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        if(!input()) break;
        ret = 0;
        get(0,N-1);
        cout<<ret<<"\n";
    }
}




