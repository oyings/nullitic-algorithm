// 1780 종이의 개수
#include <iostream>

int N, minus_one, zero, one;

int grid[2187][2187];

// 주어진 범위(N)과 시작 위치 (rows,cols) 정보를 check에 전달
void check(int range, int rows, int cols) {

    // 전부 같은 수로 이루어진게 아니라면 true 변환
    bool flag = false;
    // 시작위치를 기준으로 확인
    int first = grid[rows][cols];

    for (int i = rows; i < rows + range; i++) {
        for (int j = cols; j < cols + range; j++) {
            if (grid[i][j] != first) {
                flag = true;
                break;
            }
        }
        if (flag)break;
    }

    // 만약 모두 같은 숫자로 이루어진 종이라면 해당 변수를 +1
    if (flag == false) {
        switch (first) {
            case -1:
                minus_one++;
                break;
            case 0:
                zero++;
                break;
            case 1:
                one++;
                break;
        }
    }
    else {
        // 검사범위는 3으로 나눈 꼴 만큼 감소한다.
        // 모두 같은 수를 가진 종이가 아니라면 9분할 하는 것은 동일하게 수행함
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // 시작위치 (rows,cols)를 기반으로 탐색범위를 설정
                //std::cout << i * (range / 3) + rows << " " << j * (range / 3) + cols << '\n';
                check(range / 3, i * (range / 3) + rows, j * (range / 3) + cols);
            }
        }
    }
}

int main() {

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> grid[i][j];
        }
    }

    check(N, 0, 0);

    std::cout << minus_one << '\n' << zero << '\n' << one;

    return 0;
}