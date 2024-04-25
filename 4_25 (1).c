#include <iostream>
#include <cstring>
using namespace std;

int board[110][110];
int cashe[110][110];

int SomeObscureFunction(int m , int x , int y){

    if(x > m-1 || y > m-1)
        return 0;
    if(x == m-1 && y == m-1)
        return 1;
    int& ret = cashe[x][y];
    if(ret != -1)
        return ret;
    int jumpsize = board[x][y];
    ret = (SomeObscureFunction(m,x+jumpsize,y) + SomeObscureFunction(m,x,y+jumpsize));
    return ret;
}

int main(void){
    int n;
    int m;
    cin>>n;
    memset(cashe,-1,sizeof(cashe)); //!!
    for(int i = 0 ; i < n ; i++){
        cin>>m;
        for(int j = 0 ; j < m ; j++)
            for(int k = 0 ; k < m ; k++)
                cin>>board[j][k];
        
        
        if(SomeObscureFunction(m,0,0) != 0)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";

        memset(cashe,-1,sizeof(cashe));
        
    }

}