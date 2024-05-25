#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[1000010]; 
void input(){
    cin>>N;
    for(int i = 0 ; i < N;  i++){
        cin>>arr[i];
    }
}

int replaceidx(vector <int> &v, int num){
    int lo = 0; int hi = v.size()-1;
    int mid;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(v[mid] == num){
            lo = mid;
            break;
        }
        else if(v[mid] > num)
            hi = mid;
        else
            lo = mid+1;
    }
    return lo;
}

int find(){
    vector <int> v;
    v.push_back(arr[0]);
    int searchidx = 0;
    for(int i = 1 ; i < N ; i++){
        if(arr[i] > v[v.size()-1]){
            v.push_back(arr[i]);
        }
        else if(arr[i] < v[v.size()-1]){
            searchidx = replaceidx(v,arr[i]);
            v[searchidx] = arr[i];
        }
        else continue;
    }
    return v.size();
}

int main(void){
    input();
    cout<<find();
}