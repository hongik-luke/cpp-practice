//1863
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int arr[50010];
int N;
void input(){
    cin>>N;
    int n1;
    for(int i = 0 ; i < N;  i++){
        cin>>n1>>arr[i];
    }
}
int getresult(){
    int result = 0;
    stack <int> st;
    for(int i = 0 ; i < N;  i++){
        if(st.empty()){
            if(arr[i] != 0)
                st.push(arr[i]);
        
        }
        else if(st.top() <= arr[i]){
            st.push(arr[i]);
        }
        else{
            int lastpop = -1;
            while(!st.empty()){
                if(st.top() <= arr[i])
                    break;
                if(lastpop != st.top()){
                    result++;
                    lastpop = st.top();
                }
                st.pop();
            }
            if(arr[i] != 0)
                st.push(arr[i]);
        }
        
    }
    if(!st.empty()) result++;
    while(!st.empty()){
        int last = st.top();
        st.pop();
        if(!st.empty()){
            if(last != st.top())
                result++;
        }
    }
    
    return result;
}

int main(void){
    input();
    cout<<getresult();
}







