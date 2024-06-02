#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int main(void){
    char n[1000100];
    cin.get(n,100100);
    bool check = false;
    int len = 0;
    for(int i = 0 ; i < 100100 ; i++){
        if(n[i] == NULL){
            for(int j = 0 ; j < len ; j++){
                cout<<n[i-1-j];
            }
            break;
        }
        
        if(n[i] == '<'){
            for(int j = 0 ; j < len ; j++){
                cout<<n[i-1-j];
            }
            len = 0;
            cout<<"<";
            check = true;
            continue;
        }
        if(n[i] == '>'){
            cout<<">";
            check = false;
            continue;
        }
        if(check){
            cout<<n[i];
            continue;
        }
        
        if(n[i] == ' '){
            for(int j = 0 ; j < len ; j++){
                cout<<n[i-1-j];
            }
            cout<<" ";
            len = 0;
            continue;
        }
        
        len++;
    }
}