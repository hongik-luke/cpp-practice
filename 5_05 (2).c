#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int N,M;
bool is_they_friend[20][20];

void get(){
    cin>>N>>M;
    memset(is_they_friend,false,sizeof(is_they_friend));
    for(int i = 0 ; i < M ; i++){
        int num1,num2;
        cin>>num1>>num2;
        is_they_friend[num1][num2] = true;
        is_they_friend[num2][num1] = true;
    }
}
int getresult(vector<int> remain){
    if(remain.size() == 0)
        return 1;

    int num = 0;
    vector<int>nowremain = remain;
    for(int i = 1 ; i < remain.size() ;i++){
        if(is_they_friend[remain[0]][remain[i]]){
            
            nowremain.erase(nowremain.begin()+i);
            nowremain.erase(nowremain.begin());

            num += getresult(nowremain);
            
            nowremain = remain;
        }
    }
    return num;
}

int main(void){
    get();
    vector<int> student;
    for(int i = 0 ;i < N ;i++)
        student.push_back(i);
        
    cout<<getresult(student);
}








