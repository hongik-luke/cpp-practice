#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct flower{
    int f_month;
    int f_day;
    int l_month;
    int l_day;
};
struct cmp{
    bool operator()(flower a , flower b){
        if(a.f_month > b.f_month)
            return true;
        else if(a.f_month < b.f_month)
            return false;
        else{
            if(a.f_day >= b.f_day) return true;
            else return false;
        }
    }
};
int N;

bool cmp_to_in(int mon1, int day1, int mon2, int day2){
    if(mon1 < mon2)
        return true;
    else if(mon1 > mon2)
        return false;
    else{
        if(day1 <= day2) return true;
        else return false;
    }
}
priority_queue <flower, vector<flower> ,cmp> flowerq;
void input(){
    cin>>N;
    int n1,n2,n3,n4;
    flower f;
    for(int i = 0; i < N ; i++){
        cin>>f.f_month>>f.f_day>>f.l_month>>f.l_day;
        flowerq.push(f);
    }
    
}

int getresult(){
    

    int nowtime_1 = 3 ; int nowtime_2 = 1; 
    int lasttime_1 = 12 ; int lasttime_2 = 1; 
    int nexttime_1 = 3 ; int nexttime_2 = 1; 
    bool yes = false;
    int result = 0;
    
    while(!flowerq.empty()){
        
        flower f = flowerq.top();
        if(cmp_to_in(f.f_month, f.f_day,nowtime_1,nowtime_2 )){
            if(cmp_to_in(nexttime_1, nexttime_2, f.l_month, f.l_day)){
                nexttime_1 = f.l_month;
                nexttime_2 = f.l_day;
            }
            //cout<<nowtime.first<<" "<<nowtime.second<<" "<<nexttime.first<<" "<<nexttime.second<<"\n";
        }
        else{
            nowtime_1 = nexttime_1;
            nowtime_2 = nexttime_2;
            result++;
            if(cmp_to_in(f.f_month, f.f_day, nowtime_1, nowtime_2)){
                if(cmp_to_in(nexttime_1, nexttime_2, f.l_month, f.l_day)){
                    nexttime_1 = f.l_month;
                    nexttime_2 = f.l_day;
                }
            }
            else break;
            
        }
        
        if(cmp_to_in(lasttime_1, lasttime_2,nexttime_1, nexttime_2)){
            result++;
            yes = true;
            break;
        }
        flowerq.pop();
    }
    
    if(yes) return result;
    else return 0;
}


int main(void){
    input();
    cout<<getresult();
    return 0;
}
