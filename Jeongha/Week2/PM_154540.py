# https://school.programmers.co.kr/learn/courses/30/lessons/154540

# 제출 시 아래 코드 제외
maps = ["XXX","XXX", "XXX"]

from collections import deque

# 주어진 배열을 2차원 배열에 담는 함수
def make_graph(maps, col, row):
    graph = [[''] * col for _ in range(row)]

    for i in range(row):
        for j in range(col):
            graph[i][j] = maps[i][j]

    return graph

# 무인도를 탐색할 함수
def BFS(graph, visited, x, y, row, col):
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    count = 0
    queue = deque()
    queue.append((x, y))
    count += int(graph[x][y])

    while queue:
        x, y = queue.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx and nx < row and 0 <= ny and ny < col:
                if graph[nx][ny] != 'X' and visited[nx][ny] == False:
                    queue.append((nx, ny))
                    visited[nx][ny] = True
                    count += int(graph[nx][ny])
    return count


def solution(maps):
    answer = []

    # 행 열 지정
    col = len(maps[0])
    row = len(maps)

    # 2차원 배열에 담기
    graph = make_graph(maps, col, row)


    # BFS 수행하기
    visited = [[False] * col for _ in range(row)]

    for i in range(row):
        for j in range(col):
            # 방문하지 않은 새로운 숫자라면 새로운 섬을 의미한다.
            if visited[i][j] == False and graph[i][j] != 'X':
                # 반환받은 count값을 answer에 넣는다.
                answer.append(BFS(graph, visited, i, j, row, col))

    # 결과 반환
    answer.sort()
    if len(answer) == 0:
        answer.append(-1)
        return answer
    return answer

solution(maps)