#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;



int main(void)
{
    int n,k;
    cin>>n>>k;
    
    int *arr = new int [n];
    int *result_arr = new int [k+1];
    for(int i =0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    result_arr[0] = 1;
    
    for(int i = 0; i < n ; i++)
    {
        for(int j = arr[i] ; j <= k ; j++)
        {
            result_arr[j] += result_arr[j - arr[i]];
        }
    }
    
    cout<<result_arr[k];
}
