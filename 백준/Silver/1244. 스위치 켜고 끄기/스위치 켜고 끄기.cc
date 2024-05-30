#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int len;
int switches[110];
int stu_cnt;
pair<int,int> stu[110];
void input(){
    cin>>len;
    for(int i = 1 ; i <= len ; i++){
        cin>>switches[i];
    }
    cin>>stu_cnt;
    for(int i = 1 ; i <= stu_cnt ; i++){
        cin>>stu[i].first>>stu[i].second;
    }

}
    
void getresult(){
    for(int i = 1 ; i <= stu_cnt ; i++){
        
        if(stu[i].first == 1){
            for(int j = stu[i].second ; j <= len ;j = j + stu[i].second){
                switches[j] = (switches[j]+1)%2;
            }
        }
        else{
            int lo = stu[i].second; 
            int hi = stu[i].second; 
            while(lo > 1 && hi < len){
                if(switches[lo-1] == switches[hi+1]){
                    lo--;
                    hi++;
                }
                else break;
            }
            for(int j = lo ; j <= hi ; j++){
                switches[j] = (switches[j]+1)%2;
            }
        }
    }
}

int main(void){
    input();
    getresult();
    for(int i = 1 ; i <= len ; i++){
        cout<<switches[i]<<" ";
        if(i % 20 == 0) cout<<"\n";
    }
    
}