// 1987 알파벳
#include <iostream>

using namespace std;

// 0-25번 인덱스는 차례대로 A부터 Z를 나타냄 0이면 처리안한 알파벳 아니면 처리함
bool alphabets[27];
int R, C, result;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
// 좌상단을 1행 1열이라고 했기 때문에 이것에 맞춰서 설정
char grid[21][21];

// 현재 방문중인 좌표의 위치와 지나온 칸의 수를 전달함
void solution(pair<int,int>location,int count) {
    alphabets[grid[location.first][location.second] - 'A'] = true;
    count++;

    //상하좌우중에 방문할 수 있는 좌표확인
    for (int i = 0; i < 4; i++) {
        int nx = location.first + dx[i];
        int ny = location.second + dy[i];

        if (nx <= 0 || nx > C || ny <= 0 || ny > R)continue;
        if (alphabets[grid[nx][ny] - 'A'])continue;
        
        cout << '\n';
        solution({ nx,ny }, count);
    }

    // 인접한 좌표들 중에 방문할 수 있는 알파벳이 존재하지 않는다면 최대의 칸수 비교
    // 그리고 현재 방문한 알파벳을 방문하지 않았다는 후처리 필요
    if (count > result)result = count;
    alphabets[grid[location.first][location.second] - 'A'] = 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> grid[i][j];
        }
    }

    solution({1,1}, 0);

    cout << result;

    return 0;
}