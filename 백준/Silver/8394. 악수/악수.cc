#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
// 이게 뭔 문제여 ㅅㅂ
int N;

int main(void){
    cin>>N;
    if(N == 1 || N == 2){
        cout<<N;
        return 0;
    }
    int n1 = 1, n2 = 2;
    for(int i = 3; i <= N ; i++){
        int temp = n2;
        n2 = (n1+n2)%10;
        n1 = temp;
    }
    cout<<n2%10;
}