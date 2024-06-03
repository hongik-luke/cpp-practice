#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
int cashe[2][100010]; // 바로 앞 우리가 0 없음 1 있음
//앞에 있는데 사자를 놓고 싶으면 왼쪽에 있으면 오른쪽에 / 오른쪽에 있으면 왼쪽밖에 놓을 수 없음
//따라서 왼쪽에 있건 오른쪽에 있건 있으면 1군데에만 놓을 수 있음 ,즉 같이 세면됨

int get(int idx,int front){
    //기저 범위를 넘었다.
    if(idx > N-1) return 1;
    
    int& ret = cashe[front][idx];
    if(ret != -1) return ret;
    
    ret = get(idx+1,0)%9901;
    if(front == 0) ret = ret + 2*get(idx+1,1);
    else ret = ret + get(idx+1,1);

    
    return ret%9901;
}

int main(void){
    cin>>N;
    memset(cashe,-1,sizeof(cashe));
    cout<<get(0,0);
}