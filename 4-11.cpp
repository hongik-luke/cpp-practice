#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0)
using namespace std;

int arr[500001];
int n,k;
int main(void){
    vector<int> result;  
    cin>>n>>k;
    for(int i = 0 ; i < n ; i++)
        scanf("%1d",&arr[i]);
    for(int j = 0 ; j < n ; j++){
        
        while (k != 0 && !result.empty() && result.back() < arr[j]) {
			result.pop_back(); 
			k--; 
		}
        result.push_back(arr[j]); 
    }
    while(k){
        k--;
        result.pop_back();
    }
    for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
}





