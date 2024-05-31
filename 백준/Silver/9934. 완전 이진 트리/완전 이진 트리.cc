#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
vector <int> result[15];
int arrlen;
int N;
void input_seperate(){
    int num;
    cin>>N;
    arrlen = (1<<(N))-1;
    
    for(int i = 1 ; i <= arrlen ; i++){
        cin>>num;
        for(int j = N-1 ; j >= 0 ; j--){
            int K = 1<<j;
            if(i%K == 0){
                result[N-1-j].push_back(num);
                break;
            }
        }
    }
    
}

void print_result(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < result[i].size() ; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(void){
    input_seperate();
    print_result();
}