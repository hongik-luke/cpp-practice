#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
vector<pair<int, int>> arr;
vector<int> LIS,idx,ans;
void input(){
    cin>>N;
    int n1,n2;
    for(int i = 0 ; i < N ; i++){
        cin>>n1>>n2;
        arr.push_back({n1,n2});
    }
    sort(arr.begin(),arr.end());
}

void get(){
    LIS.push_back(arr[0].second);
	idx.push_back(0);
    for(int i = 1; i < N; i++) {
		int cur = arr[i].second;

		//선을 자르지 않아도 됨
	    if (LIS.back() < cur) {
		    idx.push_back(LIS.size());
		    LIS.push_back(cur);
	    }
		//선을 잘라야 함
	    else {
	        vector<int>::iterator iter = lower_bound(LIS.begin(), LIS.end(), cur);
		    *iter = cur;
		    idx.push_back(iter - LIS.begin());
	    }   
    }
	cout << N - LIS.size() << '\n';
	
	int cur = LIS.size() - 1;
	int len = idx.size();
	for (int i = len - 1; i >= 0; i--){
		if (cur == idx[i]) cur--;
		else ans.push_back(arr[i].first);
	}

	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << "\n";
}

int main(void){
    FASTIO;
    input();
    get();
}

