#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cctype> 
using namespace std;



int main(void)
{
    
    stack <int> stack;
    char str[101];
    int tok;
    int result = 0;
    cin>>str;
    int len =strlen(str);


    for(int i = 0; i < len ;i++)
    {
        if(isdigit(str[i]))
        {
            tok = stack.top();
            stack.pop();
            stack.push( tok *((int)(str[i]) -48) );
        }
        else if(str[i] =='(')
            stack.push(0);
        else if(str[i] == 'H')
            stack.push(1);
        else if(str[i] == 'C')
            stack.push(12);
        else if(str[i] == 'O')
            stack.push(16);
        else
        {
            tok = 0;
            while(stack.top() != 0)
            {
                tok += stack.top();
                stack.pop();
                
            }
            stack.pop();
            stack.push(tok);
        }

    }
    
    while(!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    cout<<result;
}
