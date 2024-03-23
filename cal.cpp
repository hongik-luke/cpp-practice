#include <iostream>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;


#include "cal.h"

void Calculator :: setvalue(int a, int b)
{
    num1 = a;
    num2 = b;
}
void Calculator :: setob(string ob)
{
    this->ob = ob;
}
int Calculator :: Calculate()
{
    if(ob == "+")
        return num1 + num2;
    else if(ob == "-")
        return num1 - num2;
    else if(ob == "*")
        return num1 * num2;
    else
        return num1 / num2;
}

int main(void)
{
    Calculator c;
    int n1,n2;
    string object;
    while(1)
    {
        cout<<"입력 n1 n2 ob = ";
        cin>>n1>>n2>>object;
        
        c.setvalue(n1,n2);
        c.setob(object);
        cout<<c.Calculate()<<"\n\n";
    }
}































