#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)

using namespace std;
int arr[66][66];
struct pos{
    int x;
    int y;
};

void check(pos start, int N){
    //cout<<"!"<<start.x<<start.y<<N<<"\n";
    if(N == 1){
        cout<<arr[start.x][start.y];
        return;
    }
    
    bool yes = false;
    for(int i = start.x ; i < start.x + N ; i++){
        for(int j = start.y ; j < start.y + N ; j++){
            if(arr[start.x][start.y] != arr[i][j]){
                yes = true;
                break;
            }    
        }
    if(yes)
        break;
        
    }
    
    if(!yes){

        cout<<arr[start.x][start.y];

    }
    else{

        int halfN = N/2;
        cout<<"(";
        check({start.x ,start.y},halfN);
        check({start.x ,start.y + halfN},halfN);
        check({start.x+halfN ,start.y},halfN);
        check({start.x+halfN ,start.y+halfN},halfN);
        cout<<")";
    }
    
    
}

int main(void){
    int N;
    pos start, finish;
    cin>>N;
    string s;
    for(int i=1; i<=N; i++){
    	cin>>s;
        for(int j=0; j<N; j++){
        	arr[i][j+1] = s[j] - '0'; 
        }
    }
    start = {1,1};

    check(start,N);
}


