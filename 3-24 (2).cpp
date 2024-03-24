#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    string str = "Are you happy? i am happyaa";
    int index = 0;
    while(1)
    {
        if(str.find('a',index) == -1)
            break;
        
        index = str.find('a',index);
        cout<<index<<"\n";
        index = index+1;
    }
}

int main3151(void)
{
    string s = "12351";
    const char *st =s.c_str();
    cout<<st;
}