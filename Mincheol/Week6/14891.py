from collections import deque
"""
14891번 - '톱니바퀴'
4개의 톱니바퀴 8개의 톱니
1. 극이 같으면 회전 x
2. 극이 다르면 반대로 회전
3. 연쇄적으로 회전
1<= K <= 100 (회전 횟수)
"""

"""
12시부터 시계 방향으로 주어짐 N = 0, S = 1
ex) 10101111
1.5 * 8 각 1.5시 ?
12시 1.5시 (3시 milestone, idx=2) 5시  6시 7.5시 (9시 milestone, idx=6) 10.5시
"""

wheels = []
for _ in range(4):
    # python은 iterator가 iterable함
    wheels.append(deque(map(int, input())))
k = int(input())

# shift 해줘야.. 해당 위치에서 오른쪽 왼쪽 검사 후 이동
def move_wheel(wheels, picked_wheel, direction):
    rotate = [0] * 4
    picked_num = picked_wheel - 1
    # pivot값 갱신
    rotate[picked_num] = direction

    # 왼쪽 확인
    for wheel in range(picked_num, 0, -1):
        if wheels[wheel][6] != wheels[wheel-1][2]:
            rotate[wheel-1] = -rotate[wheel]
        else:
            break
    # 오른쪽 확인
    for wheel in range(picked_num, 3):
        if wheels[wheel][2] != wheels[wheel+1][6]:
            rotate[wheel+1] = -rotate[wheel]
        else:
            break

    # 실제 회전
    for i in range(4):
        # 시계
        if rotate[i] == 1:
            wheels[i].appendleft(wheels[i].pop())
        # 반시계
        elif rotate[i] == -1:
            wheels[i].append(wheels[i].popleft())


for _ in range(k):
    picked_wheel, direction = map(int, input().split())
    move_wheel(wheels, picked_wheel, direction)

total = 0
weights = [1, 2, 4, 8]
for i in range(4):
    if wheels[i][0] == 1:
        total += weights[i]

print(total)

