#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int result = 1;
vector <int> resultv;
vector <int> v;
vector <int> printv;
void input(){
    cin>>N;
    int n;
    for(int i = 0 ; i < N ; i++){
        cin>>n;
        v.push_back(n+1);
    }
    sort(v.begin(),v.end());
}
int gcd(int big,int small){
    if(small == 0) return big;
    return gcd(small,big%small);
}
void get(){
    int a = 1;
    while(v[0] != 0){
        if(a != 1){
            for(int i = 0 ; i < N ; i++){
                v[i] = v[i]/a;
            }
            result *= a;
        }
        else{
            for(int i = 0 ; i < N ; i++)
                v[i]--;
        }
        a = v[0];
        for(int i = 1 ; i < N ; i++){
            a = gcd(v[i],a);
            if(a == 1) break;
        }
    }
    for(int i = 1 ; i < N ; i++){
        a = gcd(v[i],a);
        if(a == 1) break;
    }
    if(a != 1) result*=a;

    for(int i = 2 ; i <= result ; i++){
        while(result%i == 0){
            resultv.push_back(i);
            result/=i;
        }
    }
    for(int i = (1<<resultv.size())-1 ; i != 0 ; i--){
        int n = 1;
        for(int j = 0 ; (1<<j) <= i ; j++){
            if( (1<<j) & i) n*=resultv[j];
        }
        printv.push_back(n);
    }
}
void print_r(){
    sort(printv.begin(), printv.end());
    for(int i = 1 ; i < printv.size() ; i++){
        if(printv[i-1] != printv[i]) cout<<printv[i-1]<<" ";
    }
    cout<<printv[printv.size()-1];
    
}

int main(void){
    input();
    get(); 
    print_r();
}