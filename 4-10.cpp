#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cctype>
#include <map>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

int main(void){
    stack <string> pstack;
    string s;
    cin>>s;
    string* str = new string [s.length()];
    for(int i = 0 ; i < s.length();  i++)
        str[i] = s.substr(i,1);
    
    
    for(int i = 0 ; i < s.length();  i++){
        if(str[i] == "(" || str[i] == "["){
            pstack.push(str[i]);
            continue;
        }
        else{
            if(pstack.empty())
            {
                cout<<0;
                return 0;
            }
            int num = 1;
            if(pstack.top() != "[" && pstack.top() != "("){
                num = 0;
                while(!pstack.empty()){
                    if(pstack.top() != "[" && pstack.top() != "("){
                        int temp = stoi(pstack.top());
                        num += temp;
                        pstack.pop();
                    }
                    else 
                        break;
                }
            }
            if(pstack.empty())
            {
                cout<<0;
                return 0;
            }
            
            if(str[i] == ")" && pstack.top() == "("){
                pstack.pop();
                num = num*2;
                pstack.push(to_string(num));
            }
            else if(str[i] == "]" && pstack.top() == "["){
                pstack.pop();
                num = num*3;
                pstack.push(to_string(num));
            }
            else{
                cout<<0;
                return 0;
            }
        }

    }
    int result;
    while(!pstack.empty()){
        if(pstack.top() == "[" ||pstack.top() == "(" || pstack.top() == "]" ||pstack.top() == ")")
        {
            cout<<0;
            return 0;
        }
        int temp2 = stoi(pstack.top());
        result += temp2;
        pstack.pop();
    }
    cout<<result;
}









