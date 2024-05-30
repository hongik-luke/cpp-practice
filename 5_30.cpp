#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int N;
int arr[500010];
int result[500010];
void input(){
    cin>>N;
    for(int i = 1 ; i <= N ; i++){
        cin>>arr[i];
    }
}

void getresult(){
    stack <int> st;
    for(int i = N ; i >= 1 ; i--){
        
        while(!st.empty() && arr[i] >= arr[st.top()]){
            result[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

int main(void){
    input();
    getresult();
    for(int i = 1 ; i <= N ; i++){
        cout<<result[i]<<" ";
    }
}