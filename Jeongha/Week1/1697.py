# 백준 1697 숨바꼭질
from collections import deque

n, k = map(int, input().split())
visited = [0] * 100001

def BFS():
    queue = deque()
    queue.append(n)
    visited[n] = 0

    while len(queue) > 0:
        val = queue.popleft()
        v1 = val - 1
        v2 = val + 1
        v3 = val * 2


        if 0 <= v1 < 10001 and not visited[v1]:
            queue.append(v1)
            visited[v1] = visited[val] + 1
        if 0 <= v2 < 10001 and not visited[v2]:
            queue.append(v2)
            visited[v2] = visited[val] + 1
        if 0 <= v3 < 10001 and not visited[v3]:
            queue.append(v3)
            visited[v3] = visited[val] + 1

        if val == k:
            return visited[val]


print(BFS())