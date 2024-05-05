#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int wordcnt;
string word[300100];
int wordlen[300100];
char board[5][5];


void getword(){
    cin>>wordcnt;
    for(int i = 0; i < wordcnt ; i++){
        cin>>word[i];
        wordlen[i] = word[i].length();
    }
}

void getboard(){
    for(int i = 0 ; i < 4 ;i++)
        for(int j = 0 ; j < 4 ;j++)
            cin>>board[i][j];
}


int len_and_score[] = {0,0,0,1,1,2,3,5,11};
int score;
int corretsentence_cnt;
string highsentence; 
int highsentence_len;
bool is_it_right(int index);

void getresult(){
    score = 0;
    corretsentence_cnt = 0;
    highsentence.clear();
    highsentence_len = 0;
    for(int i = 0 ; i < wordcnt ; i++){
        if(is_it_right(i)){
            score += len_and_score[wordlen[i]];
            corretsentence_cnt++;
            
            if(wordlen[i] > highsentence_len){
                highsentence = word[i];
                highsentence_len = wordlen[i];
            }
            else if(wordlen[i] == highsentence_len){
                highsentence = (highsentence < word[i] ? highsentence : word[i]);
                highsentence_len = wordlen[i];
            }

        }
    }
}
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
bool boardmap_bool[5][5];
int now_word_index;

bool circuit_board(int nowx,int nowy,int nowindex);
bool is_it_right(int index){
    now_word_index = index;
    
    for(int i = 0 ;i < 4 ; i++){
        for(int j = 0 ;j < 4 ; j++){
            if(board[i][j] == word[index][0]){

                memset(boardmap_bool,false,sizeof(boardmap_bool));
                boardmap_bool[i][j] = true;
                if(circuit_board(i,j,1)){
                    return true;
                }
            }
        }
    }
    return false;
}

bool circuit_board(int nowx,int nowy,int nowindex){
    if(nowindex == wordlen[now_word_index])
        return true;
    bool nowbool = false;
    int newx,newy;
    for(int i = 0; i < 8 ; i++){
        newx = nowx + dx[i];
        newy = nowy + dy[i];
        if(newx < 0 || newx > 3 ||newy < 0 || newy > 3 || boardmap_bool[newx][newy] == true)
            continue;
        if(board[newx][newy] == word[now_word_index][nowindex]){
            boardmap_bool[newx][newy] = true;
            nowbool = nowbool || circuit_board(newx,newy,nowindex+1);
            boardmap_bool[newx][newy] = false;
        }
    }
    return nowbool;
    
}



int main(void){
    getword();
    int N;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        getboard();
        getresult();
        cout<<score<<" "<<highsentence<<" "<<corretsentence_cnt<<"\n";
    }
}






