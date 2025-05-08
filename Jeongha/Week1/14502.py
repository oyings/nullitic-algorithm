# 백준 14502 연구소
import itertools
import sys
from collections import deque
from itertools import combinations

n, m = map(int, input().split())
inputs = sys.stdin.read().splitlines()

graph = [[0] * m for _ in range(n)]

# 빈 칸을 저장할 배열
safety_list = []

# 탐색
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 맵 저장 및 빈 칸 좌표 저장
for i in range(n):
    for j in range(m):
        graph[i][j] = int(inputs[i].split()[j])
        # 빈 칸 좌표 저장
        if graph[i][j] == 0:
            safety_list.append([i, j])

# 빈 칸 좌표 중 3가지를 조합해 선정한 리스트
safety_list = list(itertools.combinations(safety_list, 3))


# 바이러스가 모두 퍼진 결과
def BFS(new_graph):
    visited = [[False] * m for _ in range(n)]
    queue = deque()

    for i in range(n):
        for j in range(m):
            if graph[i][j] == 2:
                new_graph[i][j] = 2
                queue.append((i, j))

                while len(queue) > 0:
                    x, y = queue.popleft()
                    visited[x][y] = True

                    for k in range(4):
                        nx, ny = x + dx[k], y + dy[k]
                        if 0 <= nx < n and 0 <= ny < m:
                            if new_graph[nx][ny] == 0 and not visited[nx][ny]:
                                new_graph[nx][ny] = 2
                                visited[nx][ny] = True
                                queue.append((nx, ny))

    return new_graph

# 결과에서 안전 영역 카운트
def count_safety(new_graph):
    count = 0
    for i in range(n):
        for j in range(m):
            if new_graph[i][j] == 0:
                count += 1
    return count

# 그래프  출력 함수
def print_graph(graph):
    for i in range(n):
        for j in range(m):
            print(graph[i][j], end=" ")
        print('')
    print('')

# 경우의 수 모두 파악
result = 0
for safety in safety_list:

    # 새로운 맵
    new_graph = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                new_graph[i][j] = 1

    # 추가 세 칸에 벽 세우기
    new_graph[safety[0][0]][safety[0][1]] = 1
    new_graph[safety[1][0]][safety[1][1]] = 1
    new_graph[safety[2][0]][safety[2][1]] = 1


    # 벽 세운 후 바이러스 퍼뜨리기
    new_graph = BFS(new_graph)

    # 안전 영역 카운트
    result = max(result, count_safety(new_graph))

print(result)