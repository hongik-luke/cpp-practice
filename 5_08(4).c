#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

bool is_it_end = false;
int board[9][9];
int cnt = 0;
struct pos{
    int x;
    int y;
};
vector<pos>v;

void get(){
    for(int i = 0 ; i < 9 ; i++)
        for(int j = 0 ; j < 9 ; j++)
            cin>>board[i][j];

    for(int i = 0 ; i < 9 ; i++)
        for(int j = 0 ; j < 9 ; j++)
            if(board[i][j] == 0){
                cnt++;
                pos newpos;
                newpos.x = i;
                newpos.y = j;
                v.push_back(newpos);
            }
}

bool checklist[10];
bool is_it_right(int xpos , int ypos, int tocheck){
    
    memset(checklist,false,sizeof(checklist));
    int to_squarex = (xpos/3)*3;
    int to_squarey = (ypos/3)*3;
    for(int i = to_squarex ; i < to_squarex+3 ;i++)
        for(int j = to_squarey ; j < to_squarey+3 ;j++)
            checklist[board[i][j]] = true;    
    for(int i = 0 ; i < 9 ; i++){
        checklist[board[i][ypos]] = true;
        checklist[board[xpos][i]] = true;
    }
    
    if(!checklist[tocheck]) return true;
    else return false;
}


void getresult(int now){
    
    if(now == cnt){
        is_it_end = true;
        return;
    }
    

    int inputcnt = 0;
    for(int input = 1; input <= 9 ; input++){
        //cout<<input<<" "<<v[now].x<<" "<<v[now].y<<"\n";
        if(is_it_right(v[now].x,v[now].y,input)){
            board[v[now].x][v[now].y] = input;
            getresult(now+1);
            if(is_it_end) return;
            board[v[now].x][v[now].y] = 0;
        }
        else inputcnt++;
    }
    return;

}


int main(void){
    get();
    getresult(0);
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}







