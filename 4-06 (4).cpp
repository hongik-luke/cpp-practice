#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;
bool Alphabet[26];

int array1[51][12];
int len[51];
int maax = 0;
int n,m;

void check();
void DFS(int idx = 0, int nowidx = 0){
    if(idx == m){
        check(); 
        return;
    }
    for(int i = nowidx ; i < 26 ; i++){
        if(Alphabet[i]||i == 0||i == 2||i == 8||i == 13 ||i == 19)
            continue;

        Alphabet[i] = true;
        DFS(idx+1,i+1);
        Alphabet[i] = false;
    }
    return;
}
void check(){
    int cnt;
    int result = 0;
    for(int i = 0 ; i < n ; i++){
        cnt = 0;
        for(int j = 0 ; j < len[i]; j++)
        {
            if(Alphabet[array1[i][j]])
                cnt++;
        }
        if(cnt == len[i])
            result++;
    }
    if(result > maax)
        maax = result;

    return;
}


int main(void){
    
    char arr[51][16];
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
    m = m -5;
    if(m < 0){
        cout<<maax; 
        return 0;
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 4 ; j < strlen(arr[i]) -4 ; j++)
            array1[i][j-4] = arr[i][j] -97;
        len[i] = strlen(arr[i]) -8;
    }
    Alphabet[(int)'a'-97] = true;
    Alphabet[(int)'c'-97] = true;
    Alphabet[(int)'i'-97] = true;
    Alphabet[(int)'n'-97] = true;
    Alphabet[(int)'t'-97] = true;
    
    DFS();
    cout<<maax;
    
}

