#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int v[100005];

bool check[100005];
bool done[100005];
int cnt = 0;
void dfs(int nowindex){
    check[nowindex] = true;
    
    int next = v[nowindex];
    if(!check[next]){
        dfs(next);
    }
    else if(!done[next]){
        cnt++;
        done[next] = true;
        for (int i = next ; i != nowindex ; i = v[i]){
            cnt++;
        }
        return ;
    }

    done[nowindex] = true;
}

int getresult(){
    cnt = 0;
    memset(check,false,sizeof(check));
    memset(done,false,sizeof(done));
    for(int i = 1 ; i <= N ; i++){
        if(!check[i]){
            dfs(i);
        }
    }

    return N - cnt;
}

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int number;
    cin>>number;
    for(int i = 0 ; i < number ; i++){
        cin>>N;
        for(int i = 1 ; i <= N ; i++)
            cin>>v[i];
        cout<<getresult()<<"\n";
    }

}







