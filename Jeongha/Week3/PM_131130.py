from collections import deque

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