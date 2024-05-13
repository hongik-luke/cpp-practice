#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool is_it_wrong = false;
int N;
int originalboard[23][23];
bool checkboard[23][23];
void input(){
    cin>>N;
    for(int i = 1 ; i <= N; i++)
        for(int j = 1 ; j <= N; j++)
            cin>>originalboard[i][j];
    
    memset(checkboard,true,sizeof(checkboard));
    
    for(int i = 1 ; i <= N; i++)
        checkboard[i][i] = false;

    
}
void getone(int from, int to, int num){
    
    for(int i = 1 ; i <= N ;i++){
        if(i == from || i == to) continue;

        if(num + originalboard[to][i] < originalboard[from][i]){
            is_it_wrong = true;
        }
        else if(num + originalboard[to][i] == originalboard[from][i]){
            checkboard[from][i] = false;
            checkboard[i][from] = false;
        }
        
    }
}


void getthem(){
    for(int i = 1 ; i <= N; i++){
        for(int j = 1 ; j <= N; j++){
            if(checkboard[i][j]){
                getone(i,j,originalboard[i][j]);
            }
        }
    }
            
}


int main(void){
    int result = 0;
    input();
    getthem();
    if(is_it_wrong){
        cout<<-1;
    }
    else{
        for(int i = 1 ; i <= N; i++){
            for(int j = i+1 ; j <= N; j++){
                if(checkboard[i][j])
                    result += originalboard[i][j];
            }
        }
        cout<<result;
    }
    
}



