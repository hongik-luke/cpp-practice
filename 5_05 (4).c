#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;



int nowindex = 0;
string original;

string makeresult(){
    if(original[nowindex] != 'x'){
        string s;
        s += original[nowindex];
        nowindex++;
        return s;
    }
    nowindex++;
    
    string str[4];
    for(int i = 0 ; i < 4 ; i++){
        str[i] = makeresult(); 
    }
    
    return (string("x")+str[2]+str[3]+str[0]+str[1]);
}


int main(void){
    int N;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>original;
        cout<<makeresult()<<"\n";
        
        original.clear();
        nowindex = 0;
    }
}







