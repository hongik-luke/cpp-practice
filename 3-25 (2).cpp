#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;



int main(void)
{
    int n,m;
    cin>>n>>m;
    string check;
    int cnt = 0;
    int mididx,firidx,lastidx;
    string *arr = new string [n];
    
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    
    sort(arr,arr+n);

    for(int i = 0 ; i < m ; i++)
    {
        firidx = 0;
        lastidx = n-1;
        cin>>check;
        
        while(1)
        {
            if(firidx > lastidx)
                break;
            
            mididx = (firidx + lastidx)/2;
            if(check.compare(arr[mididx]) == 0)
            {
                cnt++;
                break;
            }
            else if(check.compare(arr[mididx]) < 0)
                lastidx = mididx -1;
            else
                firidx = mididx +1;
        }
    }
    
    cout<<cnt;
}
