#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>


using namespace std;

int INF = 98765;
int N,K;
vector<int> v;
int type[8];
int dp[35][8] //n,type


void get(){

    int nownum;
    cin>>N>>K;
    
    for(int i = 0 ;i < N ; i++){

        cin>>nownum;
        bool check = true;
        for(auto i = 0 ; i < v.size() ; i++){
            if(v[i] == nownum){
                check = false;
                break;
            }
        }
        
        if(check == true)
            v.push_back(nownum);
    }
    sort(v.begin(), v.end());
    N = v.size();
    memset(cashe,-1,sizeof(cashe));
}

int getresult(int index, int nowvalue) {
	if(nowvalue > K)
	    return INF;
	if(nowvalue == K)
	    return 0;
	
	int& ret = cashe[index][nowvalue];
	if(ret != -1) return ret;
	ret = INF;
	for(int i = index ; i < N ;i++){
        ret = min(ret, 1 + getresult(i,nowvalue+v[i]));
	}

	return ret;
}


int main(void){
    get();
    int result = getresult(0,0); 
    if(result == INF)
        cout<<-1;
    else
        cout<<result;
}






