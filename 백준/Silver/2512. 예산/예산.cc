#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(void) {
	
	int arr[100010];
	int N;
	int hold_money;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> hold_money;

	sort(arr, arr + N);

	int index = 0;
	int beforemoney = 0;
	bool flag = false;
	for (int i = 1; i <= arr[N-1]; i++) {
		while ( arr[index] <= i && index < N ) {
			beforemoney += arr[index];
			index++;
		}
		if (hold_money < beforemoney + (N - index) * i) {
			cout << i - 1;
			flag = true;
			break;
		}
		
	}

	if (!flag) {
		cout << arr[N - 1];
	}
	return 0;
}