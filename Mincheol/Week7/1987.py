"""
1987번 - '알파벳'
"""
# 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

R, C = map(int, input().split())
board = []

for _ in range(R):
    board.append(list(input()))

visited = set()
max_num = 0
visited.add(board[0][0])

def dfs(x, y, cnt):
    global max_num
    if max_num < cnt:
        max_num = cnt

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < R and 0 <= ny < C and board[nx][ny] not in visited:
            visited.add(board[nx][ny])
            dfs(nx, ny, cnt+1)
            visited.remove(board[nx][ny])


dfs(0, 0, 1)
print(max_num)

