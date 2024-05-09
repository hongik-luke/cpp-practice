#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int N,M; //사람 수, 파티 수
bool person[53][53]; // 앞인덱스번째 사람 , 뒤인덱스 연결되어있는지 여부
bool is_he_know[53];
vector <int> party[53];

void dfs(int nowidx){
    for(int i = 1 ; i <= N ; i++){
        if(person[nowidx][i] == true && is_he_know[i] == false){
            is_he_know[i] = true;
            dfs(i);
        }
    }
    return;
}

void get(){
    memset(person,false,sizeof(person));
    memset(is_he_know,false,sizeof(is_he_know));
    cin>>N>>M;
    int k, nowperson;
    cin>>k;
    for(int i = 0; i < k ; i++){
        cin>>nowperson;
        is_he_know[nowperson] = true;
    }
    
    for(int i = 0 ; i < M ; i++){
        cin>>k;
        for(int j = 0 ; j < k ; j++){
            cin>>nowperson;
            party[i].push_back(nowperson);
        }
        
        for(int j = 1 ; j < party[i].size() ; j++){
            for(int c = 0 ; c <= j-1 ; c++){
                person[party[i][c]][party[i][j]] = true;
                person[party[i][j]][party[i][c]] = true;
            } 
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        if(is_he_know[i])
            dfs(i);
    }
}



int getresult(){
    int resultcnt = 0;
    for(int i = 0 ; i < M ; i++){
        int cnt = 0;
        for(int j = 0 ; j < party[i].size() ; j++){
            if(is_he_know[party[i][j]] == false)
                cnt++;
        }
        if(cnt == party[i].size()) resultcnt++;
    }
    return resultcnt;
}


int main(void){
    get();
    cout<<getresult()<<"\n";
}







