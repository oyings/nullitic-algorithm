// 1932 정수 삼각형
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> input_v[500];
vector<int> mid_sum[500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    // 1번째는 값이 하나 2번째줄은 값이 두개 3번째는 3개...
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            int num;
            cin >> num;
            input_v[i].push_back(num);
        }
    }

    // 첫번째 줄에 대해선 값을 처리할 필요 없음
    // 초기값만 넣어주는 것으로 해결된다.
    mid_sum[0].push_back(input_v[0][0]);

    for (int i = 1; i < N; i++) {
        // 양 끝값들에 대해선 합을 비교할 필요 없다
        for (int j = 0; j < input_v[i].size(); j++) {
            if (j == 0) {
                mid_sum[i].push_back(mid_sum[i - 1][0] + input_v[i][j]);
            }
            else if (j == input_v[i].size() - 1) {
                mid_sum[i].push_back(mid_sum[i - 1][j - 1] + input_v[i][j]);
            }
            else {
                //중간에 끼인 위치라면 앞선 누적합의 값을 비교할 필요가 있다.
                mid_sum[i].push_back(max(mid_sum[i - 1][j - 1], mid_sum[i - 1][j]) + input_v[i][j]);
            }
        }
    }

    int mx = -1;
    for (int i = 0; i < N; i++) {
        if (mid_sum[N - 1][i] > mx) {
            mx = mid_sum[N - 1][i];
        }
    }

    cout << mx;

    return 0;
}