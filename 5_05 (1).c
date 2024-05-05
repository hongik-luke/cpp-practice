#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int wordcnt;
string word[300100];
int nowwordidx;

char board[5][5];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};


void get(){
    for(int i = 0 ; i < 5 ;i++)
        for(int j = 0 ; j < 5 ;j++)
            cin>>board[i][j];       
    cin>>wordcnt;
    for(int i = 0 ; i < wordcnt ; i++){
        cin>>word[i];
    }
}


bool get_it(int nowx,int nowy, int searchidx){

    if(searchidx == word[nowwordidx].length())
        return true;
    bool ret = false;
    int newx;
    int newy;
    for(int i = 0 ; i < 8 ; i++){
        newx = nowx + dx[i];
        newy = nowy + dy[i];
        if(newx < 0 || newx > 4 || newy < 0 || newy > 4)
            continue;
        if(board[newx][newy] == word[nowwordidx][searchidx]){
            ret = ret || get_it(newx,newy,searchidx+1);
        }
    }
    

    return ret;
}
bool wordresult(int index){
    bool return_result = false;
    
    for(int i = 0 ; i < 5 ;i++)
        for(int j = 0 ; j < 5 ;j++)
            if(word[index][0] == board[i][j]){
                nowwordidx = index;
                return_result = return_result || get_it(i,j,1);

            }
    return return_result;
}

void getresult(){
    for(int i = 0 ; i < wordcnt ; i++){
        
        if(wordresult(i)) cout<<word[i]<<"\n";
    }
}
int main(void){
    get();
    getresult();
}





