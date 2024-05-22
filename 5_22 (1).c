#include <iostream>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N,M,H; // H 1~H까지  / N 1~N-1까지
vector<pair<int,int>> zerov;
int board[33][10]; // H N 
void input(){
    memset(board,0,sizeof(board));
    cin>>N>>M>>H;
    int n1,n2;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2;
        board[n1][n2] = 1;
    }
    
    for(int i = 1 ; i <= H ; i++){
        for(int j = 1 ; j <= N-1 ; j++){
            if(board[i][j] == 0 && board[i][j+1] != 1)
                zerov.push_back(make_pair(i,j));
        }
    }
}
bool checktheboard(){
    int arr[10];
    for(int i = 1; i <= N ; i++){
        arr[i] = i;
    }
    for(int i = 1 ; i <= H ; i++){
        for(int j = 1 ; j <= N-1 ; j++){
            if(board[i][j] == 1){
                if(board[i][j+1] == 1) return false;
                else{
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    
                }
            }
        }
    }

    for(int i = 1; i <= N ; i++)
        if(arr[i] != i) return false;
    
    
    
    return true;
}
void getresult(){
    if(checktheboard()){
        cout<<0;
        return;
    }
    
    for(int i = 0 ; i < zerov.size() ; i++){
        board[zerov[i].first][zerov[i].second] = true;
        if(checktheboard()){
            cout<<1;
            return;
        }
        board[zerov[i].first][zerov[i].second] = false;
    }
    
    for(int i = 0 ; i < zerov.size() ; i++){
        board[zerov[i].first][zerov[i].second] = true;
        for(int j = i+1 ; j < zerov.size() ; j++){
            board[zerov[j].first][zerov[j].second] = true;
            if(checktheboard()){
            cout<<2;
            return;
            }
            board[zerov[j].first][zerov[j].second] = false;
        }
        board[zerov[i].first][zerov[i].second] = false;
    }
    
    for(int i = 0 ; i < zerov.size() ; i++){
        board[zerov[i].first][zerov[i].second] = true;
        for(int j = i+1 ; j < zerov.size() ; j++){
            board[zerov[j].first][zerov[j].second] = true;
            for(int k = j+1 ; k < zerov.size() ; k++){
                board[zerov[k].first][zerov[k].second] = true;
                if(checktheboard()){
                    cout<<3;
                    return;
                }
                board[zerov[k].first][zerov[k].second] = false;
            }
            board[zerov[j].first][zerov[j].second] = false;
        }
        board[zerov[i].first][zerov[i].second] = false;
    }
    cout<<-1;
    return;
}

int main(void){
    input();
    getresult();
}







