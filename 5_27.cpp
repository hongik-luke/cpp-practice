#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> sosu;
bool sosu_b[4100000];
void getsosu(){
    for(int i = 2 ; i <= 2000 ; i++){
        if(!sosu_b[i]) continue;
        for(int j = i*i ; j <= 4100000 ; j += i){
            sosu_b[j] = false;
        }
    }
    for(int i = 1 ; i <= 4100000 ; i++ ){
        if(sosu_b[i]) sosu.push_back(i);
    }
}
int N;
int getresult(){
    int ret = 0;
    int hap = sosu[0];
    int first = 0 ; int last = 0;
    while(first <= last){
        if(hap > N){
            hap -= sosu[first];
            first++;
        }
        else{
            if(hap == N) ret++;
            last++;
            if(last >= sosu.size()) break;

            hap += sosu[last];
        }
    }
    
    return ret;
}

int main(void){
    memset(sosu_b,true,sizeof(sosu_b));
    sosu_b[1] = false;
    getsosu();
    cin>>N;
    cout<<getresult();
}


