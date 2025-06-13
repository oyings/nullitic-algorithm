"""
14503번 - '로봇 청소기'

index는 정방향
0 북 1 동 2 남 3 서
3<=N,M<=50

"""

room = []
# 북, 동, 남, 서
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
x, y, direct = map(int, input().split())

for _ in range(n):
    row = list(map(int, input().split()))
    room.append(row)

cleand = 0

# 0 청소 안함, 1 벽, 2 완료 가정
while True:
    # 청소가 안된 칸만 여기로 넘어옴
    if room[x][y] == 0:
        room[x][y] = 2
        cleand += 1

    moved = False
    # 빈 칸이 있으면 회전한다? 그리고 그 방향 청소 되지 않으면 전진?
    for i in range(4):
        # 반시계 방향으로
        direct = (direct + 3) % 4
        nx = x + dx[direct]
        ny = y + dy[direct]
        if 0<= nx <= n-1 and 0 <= ny <= m-1 and room[nx][ny] == 0:
            x, y = nx, ny
            moved = True
            break

    # x, y가 갱신 되었다면 다음 기점으로
    if moved:
        continue
    """
    북쪽 0 -> 남쪽 2
    남쪽 2 -> 북쪽 0
    서쪽 3 -> 동쪽 1
    동쪽 1 -> 서쪽 3
    2 더해주고 % 4 이용 
    """
    # 빈 칸이 없었던 경우
    nd = (direct + 2) % 4
    nx = x + dx[nd]
    ny = y + dy[nd]

    # 유효 범위고, 벽이 아니면 후진
    if 0<= nx <= n and 0 <= ny <= m and room[nx][ny] != 1:
        x, y = nx, ny
        continue

    break


print(cleand)