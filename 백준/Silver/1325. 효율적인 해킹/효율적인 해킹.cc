#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<int> a[10010];
int result[10010];
bool flag[10010];
int maxer = 0;

void bfs(int num) {
    memset(flag, false, sizeof(flag));

    queue<int> q;
    int count = 1;
    flag[num] = true;

    q.push(num);

    while (!q.empty()) {
        int now = q.front(); q.pop();

        int vsize = a[now].size();
        for (int i = 0; i < vsize; i++) {
            if (flag[a[now][i]]) continue;
            q.push(a[now][i]);
            flag[a[now][i]] = true;
            count++;
        }
    }

    result[num] = count;
    maxer = max(count, maxer);

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        a[num2].push_back(num1);
    }


    for (int i = 1; i <= N; i++)
        bfs(i);
    for (int i = 1; i <= N; i++) {
        if (result[i] == maxer) {
            cout << i << " ";
        }
    }

    return 0;
}