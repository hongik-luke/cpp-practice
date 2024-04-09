#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

struct pos{
    int start;
    int end;
};

bool compare(const pos &a, const pos &b){
 
    if(a.end < b.end)
        return true;
    else if(a.end > b.end)
        return false;
    else{
        if(a.start < b.start)
            return true;
        else
            return false;
    }

}
int main(void){
    int n,m;
    int64_t result;
    pos nowpos;
    vector <pos>v;
    
    cin>>n>>m;
    result = m;
    
    for(int i = 0 ; i < n ; i++){
        cin>>nowpos.start>>nowpos.end;
        if(nowpos.start > nowpos.end)
            v.push_back(nowpos);
        
    }

    sort(v.begin(), v.end(), compare);

    nowpos = v[0];
    for(int i = 1 ; i < v.size() ; i++){
        if(nowpos.start >= v[i].end){
            nowpos.start = max(nowpos.start,v[i].start);
            nowpos.end = min(nowpos.end,v[i].end);
        }
        else{
            result += (nowpos.start - nowpos.end)*2;
            nowpos = v[i];

        }
    }
    result += (nowpos.start - nowpos.end)*2;
    cout<<result<<"\n";

}