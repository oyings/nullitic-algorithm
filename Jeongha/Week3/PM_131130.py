from collections import deque


def BFS(n, sx, sy, graph, visited):
    count = 0

    queue = deque()
    queue.append((sx, sy))

    visited[sx][sy] = 1
    visited[sy][sx] = 1
    count += 1

    while queue:
        # x, y부터 탐색
        x, y = queue.popleft()

        for i in range(1, n + 1):
            # 방문하지 않았고, 다음으로 연결된 노드가 있다면
            if visited[y][i] == 0 and graph[y][i] == 1:
                visited[y][i] = 1
                visited[i][y] = 1
                # 큐에 담아 탐색
                queue.append((y, i))
                # 노드 개수 세기
                count += 1
    # 해당 그래프 노드 개수 반환
    return count, visited

def solution(cards):
    answer = 0
    result = []

    n = len(cards)
    visited = [0] * n

    for i in range(n):
        # 노드의 개수
        count = 0

        if visited[i] == 0:
            queue = deque()
            queue.append(i)
            visited[i] = 1
            count += 1
        else:
            pass


        while queue:
            node = queue.popleft()
            # print("current node", node, cards[node])
            next_node = cards[node] - 1
            if visited[next_node] == 0:
                # print("next node", next_node, cards[next_node])
                queue.append(next_node)
                visited[next_node] = 1
                count += 1

        if count == 0:
            pass
        else:
            result.append(count)

    # print(result)

    # 예외 처리
    if len(result) == 1:
        answer = 0
        return answer

    # 내림차순 정렬
    result.sort(reverse=True)
    answer = result[0] * result[1]
    return answer

# 예시 입력
print(solution([8,6,3,7,2,5,1,4]))