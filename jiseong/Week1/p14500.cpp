#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> used;
int result = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void dfs(int r, int c, int depth, int sum) {
    if (depth == 4) {
        result = max(result, sum);
        return;
    }
    for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if (used[nr][nc]) continue;
        used[nr][nc] = true;
        dfs(nr, nc, depth + 1, sum + board[nr][nc]);
        used[nr][nc] = false;
    }
}

// 'ㅗ' 모양 네 가지 경우를 따로 계산
void checkT(int r, int c) {
    // 네 방향으로 뻗는 합
    int wingSum = board[r][c];
    int minWing = 1001;
    int wings = 0;
    for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        wingSum += board[nr][nc];
        minWing = min(minWing, board[nr][nc]);
        ++wings;
    }
    // 날개가 3개 이상일 때만 ㅗ 모양 완성 가능
    if (wings >= 3) {
        result = max(result, wingSum - (wings == 4 ? minWing : 0));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.assign(N, vector<int>(M));
    used.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            used[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            used[i][j] = false;
            checkT(i, j);
        }
    }

    cout << result << "\n";
    return 0;
}
