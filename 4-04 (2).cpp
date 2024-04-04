#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main(void)
{
    int n;
    cin>>n;

    long long hap = 0;
    
    
    int arr[6];
    for(int i = 0 ; i < 6 ; i++)
        cin>>arr[i];

    
    if(n == 1)
    {
        sort(arr,arr+6);
        for(int i = 0 ; i < 5 ; i++)
            hap += arr[i];
        cout<<hap;
        return 0;
    }
    
    int newarr[3];
    for(int i = 0 ; i < 3 ; i++)
    {
        if(arr[i] < arr[5-i])
            newarr[i] = arr[i];
        else
            newarr[i] = arr[5-i];
    }

    sort(newarr,newarr+3);

    long long case_1 = 4;
    long long case_2 = (long long)4*(n-1) + (long long)4*(n-2);
    long long case_3 = (long long)(n-2)*(n-2) + (long long)4*(n-1)*(n-2);
    hap = (case_1+case_2+case_3)*newarr[0] + (case_1+case_2)*newarr[1] + (case_1)*newarr[2];

    cout<<hap;
    return 0;
}


