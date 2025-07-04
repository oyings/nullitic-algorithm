"""
13335번 - '트럭'
"""
from collections import deque

# 트럭의 수, 다리 길이, 다리 최대하중
n, w, L = map(int, input().split())

# 트럭의 무게
weights = deque(map(int, input().split()))

# 트럭의 순서는 바꿀 수 없음
bridge = deque([0] * w)
time = 0
cur_load = 0

while bridge:
    time += 1
    # deque 사용 o(1)
    cur_load -= bridge.popleft()

    if weights:
        # 추가해도 하중을 견디면
        if cur_load + weights[0] <= L:
            weight = weights.popleft()
            cur_load += weight
            bridge.append(weight)
        else:
            # 못 버티면 hold on a second
            bridge.append(0)

print(time)