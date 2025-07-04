n, m = map(int, input().split())
alphabet_map = [list(input()) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


stack = [(0, 0, set(alphabet_map[0][0]))]
max_length = 1

while stack:
    x, y, path = stack.pop()
    # 가장 긴 경로를 저장
    max_length = max(max_length, len(path))

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            # 다음 칸의 알파벳이 아직 방문하지 않았다면
            current_alphbet = alphabet_map[nx][ny]
            if  not current_alphbet in path:
                # 집합 연산을 수행한다.
                stack.append((nx, ny, path | {alphabet_map[nx][ny]}))

print(max_length)