"""
1913 - 달팽이
----------------
3 3 (홀수인 자연수 보장)
9 2 3
8 1 4
7 6 5
남쪽 -> 동쪽 -> 북쪽 -> 서쪽
남쪽... 패턴이 같음
"""


N = int(input())
target = int(input())
start = N*N

# 이렇게 해야 동일한 객체가 아닌 각 행마다 다른 객체로 만들어짐
snail = [[0]*N for _ in range(N)]

# 남, 동, 북, 서
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

x = 0
y = 0

t_x = 0
t_y = 0
dir = 0


# 남 동 북 서 인데 한쪽으로 최대한 가야함.
# 기껏 해봐야 (n^2)
while start > 0:
    snail[x][y] = start
    if start == target:
        t_x = x + 1
        t_y = y + 1

    new_x = x + dx[dir]
    new_y = y + dy[dir]

    # 허용 범위를 벗어나거나 빈자리가 아니면 방향 전환
    if new_x < 0 or new_x > N-1 or new_y < 0 or new_y > N-1 or snail[new_x][new_y] != 0:
        dir = (dir + 1) % 4
        new_x = x + dx[dir]
        new_y = y + dy[dir]

    x = new_x
    y = new_y

    start -= 1

for i in range(N):
    print(*snail[i])

print(t_x, t_y)