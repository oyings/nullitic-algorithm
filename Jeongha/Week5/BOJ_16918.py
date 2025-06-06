import sys
from collections import deque
import copy

r, c, n = map(int, input().split())

inputs = sys.stdin.read().splitlines()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def print_graph(graph):
    for row in graph:
        print(''.join(row))

def make_all_bomb():
    for i in range(r):
        for j in range(c):
            graph[i][j] = 'O'

def explode(x, y, graph):
    graph[x][y] = '.'

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < r and 0 <= ny < c:
            graph[nx][ny] = '.'

    return graph

graph = [list(line) for line in inputs]
pre_graph = [row[:] for row in graph]
count = 1

for count in range(1, n + 1):

    if count % 2 == 0:
        # 모두 폭탄으로 만들기
        make_all_bomb()

    elif count != 1:
        # 폭탄 터뜨리기
        for i in range(r):
            for j in range(c):
                if pre_graph[i][j] == 'O':
                    graph = explode(i, j, graph)
        pre_graph = [row[:] for row in graph]


print_graph(graph)
