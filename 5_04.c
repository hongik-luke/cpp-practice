#include <iostream>
#include <algorithm>
#include <cstring>



using namespace std;

int N;
int dp[2010][2010];
int num[2010];
void get(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
        cin>>num[i];
    
    memset(dp,-1,sizeof(dp));
}

int getresult(int nowindex, int Alastindex, int Blastindex){
    if(nowindex == N)
        return 0;
    int& ret = dp[Alastindex+1][Blastindex+1];
    if(ret != -1) return ret;
    
    int result1 = getresult(nowindex+1,nowindex,Blastindex);
    if(Alastindex != -1) 
        result1 += abs(num[nowindex] - num[Alastindex]);
    
    int result2 = getresult(nowindex+1,Alastindex,nowindex); 
    if(Blastindex != -1) 
        result2 += abs(num[nowindex] - num[Blastindex]);


    return ret = min(result1,result2);
}


int main(void){
    get();
    cout<<getresult(1,0,-1);
}






