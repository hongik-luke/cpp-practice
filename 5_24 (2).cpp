#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
struct flower{
    int f_month;
    int f_day;
    int l_month;
    int l_day;
};
int N;
vector <flower> flowerv;

bool cmp(flower a , flower b){
    if(a.f_month < b.f_month)
        return true;
    else if(a.f_month > b.f_month)
        return false;
    else{
        if(a.f_day <= b.f_day) return true;
        else return false;
    }
}
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

void input(){
    cin>>N;
    int n1,n2,n3,n4;
    flower f;
    for(int i = 0; i < N ; i++){
        cin>>n1>>n2>>n3>>n4;
        f.f_month = n1;
        f.f_day = n2;
        f.l_month = n3;
        f.l_day = n4;
        flowerv.push_back(f);
    }
    sort(flowerv.begin(),flowerv.end(),cmp);
}

int getresult(){
    pair<int,int> nowtime = make_pair(3,1);
    pair<int,int> lasttime = make_pair(12,1);
    bool yes = false;
    int result = 0;
    pair<int,int> nexttime = make_pair(3,1);
    
    for(int i = 0 ; i < flowerv.size() ;i++){
        if(cmp_to_in(flowerv[i].f_month, flowerv[i].f_day, nowtime.first, nowtime.second)){
            if(cmp_to_in(nexttime.first, nexttime.second, flowerv[i].l_month, flowerv[i].l_day)){
                nexttime = make_pair(flowerv[i].l_month, flowerv[i].l_day);
            }
            //cout<<nowtime.first<<" "<<nowtime.second<<" "<<nexttime.first<<" "<<nexttime.second<<"\n";
        }
        else{
            nowtime = {nexttime.first,nexttime.second};
            result++;
            if(cmp_to_in(flowerv[i].f_month, flowerv[i].f_day, nowtime.first, nowtime.second)){
                if(cmp_to_in(nexttime.first, nexttime.second, flowerv[i].l_month, flowerv[i].l_day)){
                    nexttime = make_pair(flowerv[i].l_month, flowerv[i].l_day);
                }
            }
            else return 0;
            
        }
        
        if(cmp_to_in(lasttime.first, lasttime.second, nexttime.first, nexttime.second)){
                result++;
                yes = true;
                break;
        }
    }
    
    if(yes) return result;
    else return 0;
}


int main(void){
    input();
    cout<<getresult();
}
