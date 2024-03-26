#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main(void)
{
    int n,m,resultnum;
    int cnt;
    int lastcheck;
    cin>>n>>m;
    
    int *arr = new int [n];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    sort(arr,arr+n);

    int first = 1;
    int last = arr[n-1] - arr[0];
    int mid;
    
    while(first<=last)
    {
        
        mid = (first+last)/2;
        cnt = 1;
        lastcheck = arr[0];
        
        for(int i = 1 ; i< n ;i++){
            if(arr[i]- lastcheck >= mid){
                cnt++;
                lastcheck = arr[i];
            }
        }

        if(cnt >= m)
        {
            resultnum = mid;
            first = mid+1;
        }
        else
            last = mid-1;
    }
    
    cout<<resultnum;
    
}