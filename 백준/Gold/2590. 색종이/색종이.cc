#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int arr[7];
void input(){
    cin>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>arr[6];
}

int getresult(){
    //6처리
    int result = arr[6];

    //5처리
    result += arr[5];
    if(arr[1] - arr[5]*11 < 0) arr[1] = 0;
    else arr[1] = arr[1] - arr[5]*11;
    
    //4처리
    result += arr[4];
    int remain4 = arr[4]*5;
    if(remain4 - arr[2] > 0){
        remain4 = (remain4-arr[2])*4;
        arr[2] = 0;
        if(arr[1] - remain4 < 0) arr[1] = 0;
        else arr[1] = arr[1] - remain4;
    }
    else arr[2] = arr[2] - remain4;

    //3처리
    result += arr[3]/4;
    arr[3] = arr[3]%4;
    if(arr[3] == 1){
        result++;
        arr[3] = 0;
        if(arr[2] >= 5){
            arr[2] -= 5;
            arr[1] -= 7;
            if(arr[1] < 0) arr[1] = 0;
        }
        else{
            int remain3 = 27;
            remain3 -= arr[2]*4;
            arr[2] = 0;
            arr[1] -= remain3;
            if(arr[1] < 0) arr[1] = 0;
        }
    }
    else if(arr[3] == 2){
        result++;
        arr[3] = 0;
        if(arr[2] >= 3){
            arr[2] -= 3;
            arr[1] -= 6;
            if(arr[1] < 0) arr[1] = 0;
        }
        else{
            int remain3 = 18;
            remain3 -= arr[2]*4;
            arr[2] = 0;
            arr[1] -= remain3;
            if(arr[1] < 0) arr[1] = 0;
        }
    }
    else if(arr[3] == 3){
        result++;
        arr[3] = 0;
        if(arr[2] >= 1){
            arr[2] -= 1;
            arr[1] -= 5;
            if(arr[1] < 0) arr[1] = 0;
        }
        else{
            int remain3 = 9;
            arr[2] = 0;
            arr[1] -= remain3;
            if(arr[1] < 0) arr[1] = 0;
        }
    }
    
    //2처리
    result += (arr[2]*4)/36;
    arr[1] += arr[2]*4%36;
    
    //1처리
    result += arr[1]/36;
    if(arr[1]%36 != 0) result++;
    return result;
}


int main(void){
    input();
    cout<<getresult();
}

