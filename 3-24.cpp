#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


int main(void)
{
    int n,firstidx,lastidx,mididx;
    __int64_t hap = 0;
    __int64_t m;
    cin>>n>>m;
    int resultnum;
    
    int *p = new int [n];
    
    for(int i = 0 ; i < n ;i++)
        cin>>p[i];
        
    sort(p,p+n);
    
    
    firstidx = 0;
    lastidx = n-1;
    while(firstidx <= lastidx)
    {
        mididx = (firstidx + lastidx)/2;

        for(int i = mididx + 1 ; i < n ;i++)
        {
            hap += p[i] - p[mididx];
        }
        
        if(hap > m)
            firstidx = mididx +1;
        else if(hap < m)
            lastidx = mididx -1;
        else
        {
            cout<<p[mididx];
            return 0;
        }
        
        hap = 0;
        
    }
    
    resultnum = p[firstidx];
    for(int i = firstidx+1 ; i < n ; i++)
    {
            hap += p[i] - resultnum;
    }
    
    while(1)
    {
        resultnum--;
        hap += (n-firstidx);
        
        if(hap >= m)
        {
            cout<<resultnum;
            return 0;
        }
        
        
    }
    
    return 0;
}