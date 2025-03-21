#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(void) {
	int now;
	int maxer;
	int dp[100010];


	int N;
	int arr[100010];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	now = arr[0];
	maxer = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		maxer = max(maxer, dp[i]);
	}
	cout << maxer;



	return 0;
}