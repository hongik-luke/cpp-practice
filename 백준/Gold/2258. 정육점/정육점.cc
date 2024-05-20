#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
struct pos{
    int weight;
    int price;
};
bool cmp(const pos a , const pos b){
    if(a.price < b.price)
        return true;
    else if(a.price > b.price)
        return false;
    else{
        if(a.weight > b.weight)
            return true;
        else
            return false;
   }

}

int N,M;
vector <pos> v;
void input(){
    cin>>N>>M;
    int n1,n2;
    pos a;
    for(int i = 0 ; i < N ; i++){
        cin>>n1>>n2;
        a = {n1,n2};
        v.push_back(a);
    }
    sort(v.begin(),v.end(),cmp);
}

int getresult(){
    int now_weight = 0;
    int all_weight = 0;
    int now_price = -1;
    bool can_solve = false;
    for(int i = 0 ; i < v.size() ; i++){
        all_weight += v[i].weight;
        if(now_price < v[i].price){
            now_price = v[i].price;
            now_weight = all_weight;
            if(all_weight >= M )
                return now_price;
        }
        
    }
    if(all_weight >= M) can_solve = true;
    
    
    int real_price = 0;
    all_weight = 0;
    now_price = -1;
    if(can_solve){
        for(int i = 0 ; i < v.size() ; i++){
            if(now_price < v[i].price){
                now_price = v[i].price;
                real_price = 0;
            }
            all_weight += v[i].weight;
            real_price += v[i].price;
            if(all_weight >= M) return real_price;
        }
    }
    
    return -1;
}


int main(void){
    input();
    cout<<getresult();
}