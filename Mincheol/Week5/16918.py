"""
16918번 - '봄버맨'
i,j(자신)  북 남 동 서 폭팔, 연쇄 폭팔 X
R = ROW, C = COLUMN, N = SEC
(1 <= R, C, N <= 200)
"""

R, C, N = map(int, input().split())
grid = [list(input()) for _ in range(R)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def explode(grid):
    result = [['O'] * C for _ in range(R)]
    for i in range(R):
        for j in range(C):
            if grid[i][j] == 'O':
                result[i][j] = '.'
                for d in range(4):
                    ni, nj = i + dx[d], j + dy[d]
                    # 터지는 범위가 유효한 범위면 터트림
                    if 0 <= ni < R and 0 <= nj < C:
                        result[ni][nj] = '.'
    return result

final = None

# 짝수초에는 매번 폭탄이 가득 차있음
if N == 1:
    final = grid
elif N % 2 == 0:
    final = [['O'] * C for _ in range(R)]
# 매 3초 후에는 폭탄이 폭팔한다 3, 7 동형이다 % 4 == 3 규칙성
elif N % 4 == 3:
    final = explode(grid)
# 매 3초 후에는 폭탄이 폭팔한다 5, 9 동형이다 % 4 == 1 규칙성
elif N % 4 == 1:
    first_explosion = explode(grid)
    final = explode(first_explosion)

for row in final:
    print(''.join(row))