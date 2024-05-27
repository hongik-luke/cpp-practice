#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int press1[100010];
int n_press1[100010];
int check[100010];
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        scanf("%1d",&n_press1[i]);
        if(i == 0 || i == 1){
            press1[i] = (n_press1[i]+1)%2;
        }
        else{
            press1[i] = n_press1[i];
        }
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%1d",&check[i]);
    }
}
int get(){
    int result1 = 1,result2 = 0;
    for(int i = 1 ; i < N ; i++){
        if(press1[i-1] != check[i-1]){
            result1++;
            press1[i-1] = (press1[i-1]+1)%2;
            press1[i] = (press1[i]+1)%2;
            press1[i+1] = (press1[i+1]+1)%2;
        }
    }
    for(int i = 1 ; i < N ; i++){
        if(n_press1[i-1] != check[i-1]){
            result2++;
            n_press1[i-1] = (n_press1[i-1]+1)%2;
            n_press1[i] = (n_press1[i]+1)%2;
            n_press1[i+1] = (n_press1[i+1]+1)%2;
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        if(press1[i] != check[i]){
            result1 = -1;
            break;
        }
        
    }
    for(int i = 0 ; i < N ; i++){
        if(n_press1[i] != check[i]){
            result2 = -1;
            break;
        }
    }
    if(result1 != -1 && result2 != -1) return min(result1,result2);
    return max(result1,result2);
}

int main(void){
    input();
    int n = get();
    if(n == -1) cout<<-1;
    else cout<<n;
}