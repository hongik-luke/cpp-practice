#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cstdlib>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

string str;
int main(void){
    cin>>str;
    int len = str.size();
    int arr[35];
    for(int i = 0 ; i < len ; i++){
        if(str[i] == '[') arr[i] = -4;
        if(str[i] == '(') arr[i] = -3;
        if(str[i] == ']') arr[i] = -2;
        if(str[i] == ')') arr[i] = -1;
    }
    stack<int> st;
    for(int i = 0 ; i < len ; i++){
        st.push(arr[i]);
        
        if(st.top() == -2 || st.top() == -1){
            int type = st.top();
            st.pop();
            
            int now = 0;
            while(!st.empty() && st.top() != -3 && st.top() != -4){
                now += st.top();
                st.pop();
            }
            if(now == 0){
                now = 1;
            }
            
            if(st.empty() || type-2 != st.top()){
                cout<<0;
                return 0;
            }
            
            st.pop();
            
            st.push(now*(-1*(type-1)));
        }
    }
    int ret = 0;
    while(!st.empty()){
        if(st.top() < 0){
            cout<<0;
            return 0;
        }
        ret += st.top();
        st.pop();
    }
    cout<<ret;
}
