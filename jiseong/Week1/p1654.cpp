#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;
    vector<long long> a(K);
    long long hi = 0;
    for (int i = 0; i < K; i++) {
        cin >> a[i];
        hi = max(hi, a[i]);
    }

    long long lo = 1, ans = 0;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long cnt = 0;
        for (auto &len : a) {
            cnt += len / mid;
        }
        if (cnt >= N) {
            ans = mid;      // 가능한 길이이므로 저장
            lo = mid + 1;   // 더 큰 길이 시도
        } else {
            hi = mid - 1;   // 길이를 줄여야 함
        }
    }

    cout << ans << "\n";
    return 0;
}
