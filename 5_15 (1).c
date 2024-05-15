// 해결한 거 같긴한데 왜인지 이유는 모르겠다.
// 이럴땐 벨만 포드 쓰면돼~ 해서 그냥 쓰는 느낌
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct pos {
    int value;
    int idx;
};
int IMF = 98765432;
int F = 9876543;
int N,M,W;

vector<pos> v[510];
void input(){
    cin>>N>>M>>W;
    int n1,n2,n3;
    pos newpos;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        newpos = {n3,n2-1};
        v[n1-1].push_back(newpos);
        newpos = {n3,n1-1};
        v[n2-1].push_back(newpos);
    }
    for(int i = 0 ; i < W ; i++){
        cin>>n1>>n2>>n3;
        newpos = {-n3,n2-1};
        v[n1-1].push_back(newpos);
    }
    
}

bool getresult(){
    vector<int> distance(N,IMF);
    distance[0] = 0;
    bool check;
    
    // 음수 사이클이 없을 경우 -> 0(idx 1)에 대한 최단경로가 완성되고 난 뒤 
    // 완화되지 않음 distance[there] > distance[here] + cost를 만족하는 간선 하나도 없음
    // 허나 음수 사이클이 있는 경우 계속 돌아갈 거임 더 큰 음수가 되면서
    // 그러니 음수 사이클이 없을 때 돌 수 있는 한계치(N-1) 이상으로 완화시켰을 때 계속 완화하고 있다면 이건 음수사이클이 있다고 볼 수 있음
    
    //정상적인 최단경로는 최대 N-1번까지 따라서 N번째에도 돌았다는 건 음수싸이클이 있다는 것.
    //이를 이용해서 음수 싸이클이 존재하는지 여부를 체크할 수 있음.
    for(int iter = 0 ; iter < N; iter++){
        check = false;
    
        for(int here = 0 ; here < N ; here++){
            for(int j = 0 ; j < v[here].size() ; j++){
                int there = v[here][j].idx;
                int cost = v[here][j].value;
                
                if(distance[here] <  IMF-F &&  distance[there] > distance[here] + cost){
                    check = true;
                    distance[there] = distance[here] + cost;
                }
            }
        }
        if(!check){
            for(int iter = 0 ; iter < distance.size() ; iter++){
                cout<<distance[iter]<<"\n";
            }
            return false;
        }
    }
    for(int iter = 0 ; iter < distance.size() ; iter++){
                cout<<distance[iter]<<"\n";
            }
    return true;
}

int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ;i++){
        input();
        if(getresult()){
            cout<<"YES"<<"\n";
            
        }
        else cout<<"NO"<<"\n";
        for(int i = 0 ; i <= N ; i++)
            v[i].clear();
    }
}