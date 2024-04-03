#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};




int main(void)
{
    int n,m;
    cin>>n>>m;
    
    int result = 0;
    result += n*m*2;
    
    int xpos,ypos,temp;
    int arr[n][m];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin>>arr[i][j];
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            
            temp = arr[i][j] * 4;
            
            for(int k = 0 ; k < 4 ; k++)
            {
                xpos = i+x[k];
                ypos = j+y[k];
                if(xpos>=0 && xpos<= n-1 && ypos >=0 && ypos <=m-1)
                {
                    if(arr[i][j] > arr[xpos][ypos])
                        temp -= arr[xpos][ypos];
                    else
                        temp -= arr[i][j];
                }
                
            }
            result += temp;
        }
    }
    
    cout<<result;
    
}