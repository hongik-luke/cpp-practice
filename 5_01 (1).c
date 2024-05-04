#include <iostream>
#include <algorithm>
#include <cstring>



using namespace std;

int MOD = 1000000; 
string str;
int N;
int numarr[5010];
int cashe[5010]; //K, N 
bool is_wrong = false;
void get(){
    cin>>str;
    
    N = str.length();
    int idx = 0 ;
    for(int i = 0; i < str.length()-1; i++){
        if(str[i] == '0'){
            is_wrong = true;
            break;
        }
        
        if(str[i+1] != '0'){
            numarr[idx] = str[i] - 48;
        }
        else{
            numarr[idx] = (str[i] - 48)*10 + (str[i+1] - 48);
            N--;
            if(numarr[idx] > 26) {
                is_wrong = true;
                break;
            }
            i++;
        }
        idx++;
        
    }
    if(str[str.length()-1] != '0')
        numarr[idx] = str[str.length()-1] -48;
    else if(str.length() == 1 && str[str.length()-1] == '0') is_wrong = true;
    else if(str[str.length()-1] == '0' && str[str.length()-2] == '0') is_wrong = true;

    
    memset(cashe,-1,sizeof(cashe));

}

int getresult(int index){
    
    if(index >= N-1)
        return 1;
    
    int& ret = cashe[index];
    if(ret != -1 ) return ret;
    
    if((numarr[index] == 1 && numarr[index+1] <= 9) || (numarr[index] == 2 && numarr[index+1] <= 6) )
        ret =(getresult(index+1) + getresult(index+2)) % 1000000;
    else
        ret = getresult(index+1);

    
    return ret;
}


int main(void){
    get();
    if(is_wrong){
        cout<<0<<"\n";
        return 0;
    }

    cout<<getresult(0)%1000000<<"\n";
    
}






