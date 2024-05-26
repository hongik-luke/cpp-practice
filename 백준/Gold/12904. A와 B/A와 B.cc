#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string first;
string to_find;
int first_len;

bool find(string s){
    int len = s.size();
    if(len == first_len){
        for(int i = 0 ; i < len ; i++){
            if(first[i] != s[i]) return false;
        }
        return true;
    }
    
    if(s[len-1] == 'A'){
        string s1 = s.substr(0,len-1);
        return find(s1);
    }
    else{
        string s2;
        s2.resize(len-1);
        for(int i = 0 ; i < len-1 ; i++){
            s2[i] = s[len-2-i];
        }
        return find(s2);
    }

}
int main(void){
    cin>>first>>to_find;
    first_len = first.size();
    if(find(to_find)) cout<<1;
    else cout<<0;
}