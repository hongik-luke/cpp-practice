#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>



using namespace std;


int N,M;
int weight[31];
int have_to_find[10];

bool dp[31][40100];
bool check[40100];
int nowlimitweight = 0;


void get(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
        cin>>weight[i];
    
    memset(dp,0,sizeof(dp));
    memset(check,false,sizeof(check));
    
    cin>>M;
    for(int i = 0 ; i < M ; i++)
        cin>>have_to_find[i];
}

void getresult(int currentmarble, int currentWeight) {
	if (currentmarble > N)
		return;
	if (dp[currentmarble][currentWeight] != 0)
		return;

	dp[currentmarble][currentWeight] = true;

	getresult(currentmarble + 1, currentWeight + weight[currentmarble]);
	getresult(currentmarble + 1, currentWeight);
	getresult(currentmarble + 1, abs(currentWeight - weight[currentmarble]));
}


void check_result(){
    for(int i = 0 ; i < M ;i++){
        if(dp[N][have_to_find[i]])
            cout<<"Y ";
        else
            cout<<"N ";
    }
}

int main(void){
    get();
    getresult(0,0);
    check_result();
}






