#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int N, M;
int64_t arr[1000001];
int64_t seg[4000001][2];

void input() {
    int a1, a2;
    cin >> N >> a1 >> a2;
    M = a1 + a2;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void make_seg(int idx, int lo, int hi) {
    if (lo == hi) {
        seg[idx][0] = arr[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    make_seg(idx * 2, lo, mid);
    make_seg(idx * 2 + 1, mid + 1, hi);
    seg[idx][0] = seg[idx * 2][0] + seg[idx * 2 + 1][0];
}

void propagate(int idx, int lo, int hi) {
    if (seg[idx][1] != 0) {
        seg[idx][0] += seg[idx][1] * (hi - lo + 1);
        if (lo != hi) {
            seg[idx * 2][1] += seg[idx][1];
            seg[idx * 2 + 1][1] += seg[idx][1];
        }
        seg[idx][1] = 0;
    }
}

int64_t change(int idx, int lo, int hi, int64_t l, int64_t r, int64_t val) {
    propagate(idx, lo, hi);
    if (hi < l || r < lo) return seg[idx][0];
    if (l <= lo && hi <= r) {
        seg[idx][1] += val;
        propagate(idx, lo, hi);
        return seg[idx][0];
    }
    int mid = (lo + hi) / 2;
    seg[idx][0] = change(idx * 2, lo, mid, l, r, val) + change(idx * 2 + 1, mid + 1, hi, l, r, val);
    return seg[idx][0];
}

int64_t get(int idx, int lo, int hi, int64_t l, int64_t r) {
    propagate(idx, lo, hi);
    if (hi < l || r < lo) return 0;
    if (l <= lo && hi <= r) return seg[idx][0];
    int mid = (lo + hi) / 2;
    return get(idx * 2, lo, mid, l, r) + get(idx * 2 + 1, mid + 1, hi, l, r);
}

void print() {
    int t;
    for (int i = 0; i < M; i++) {
        cin >> t;
        if (t == 1) {
            int64_t l, r, val;
            cin >> l >> r >> val;
            l -= 1;
            r -= 1;
            change(1, 0, N - 1, l, r, val);
        } else {
            int64_t l, r;
            cin >> l >> r;
            l -= 1;
            r -= 1;
            cout << get(1, 0, N - 1, l, r) << "\n";
        }
    }
}

int main(void) {
    FASTIO;
    input();
    make_seg(1, 0, N - 1);
    print();
}




