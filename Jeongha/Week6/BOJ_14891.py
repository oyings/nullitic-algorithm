from collections import deque

# 톱니바퀴 입력 받기
arrays = deque()
for i in range(4):
    arrays.append(deque(input()))

# 1
def turn_to_clockwise(array):
    last_value = array[-1]
    array.pop()
    array.insert(0, last_value)
    return array

# -1
def turn_to_anticlockwise(array):
    first_value = array[0]
    array.popleft()
    array.append(first_value)
    return array

def count_score(arrays):
    count = 0
    for i in range(4):
        if arrays[i][0] == '1':
            count += 2 ** i
    return count

n = int(input())
for i in range(n):
    # number번째를, direction 방향으로
    number, direction = map(int, input().split())
    number -= 1
    have_to_turn = [0] * 4
    have_to_turn[number] = direction
    current_direction = direction * -1

    # number 기준 왼쪽 확인
    index = number - 1
    while index >= 0:
        if arrays[index + 1][6] == arrays[index][2]:
            # 맞붙은 톱니가 같으므로 회전하지 않고 종료한다
            break

        # 맞붙은 톱니가 다르므로 회전한다
        have_to_turn[index] = current_direction

        # 다음 톱니바퀴
        index -= 1
        # 방향 변경
        current_direction = current_direction * -1

    # number 기준 오른쪽 확인
    index = number + 1
    current_direction = direction * -1
    while index < 4:
        if arrays[index - 1][2] == arrays[index][6]:
            # 맞붙은 톱니가 같으므로 회전하지 않고 종료한다
            break

        # 맞붙은 톱니가 다르므로 회전한다
        have_to_turn[index] = current_direction

        # 다음 톱니바퀴
        index += 1
        # 방향 변경
        current_direction = current_direction * -1

    for i in range(4):
        if have_to_turn[i] == 1:
            turn_to_clockwise(arrays[i])
        elif have_to_turn[i] == -1:
            turn_to_anticlockwise(arrays[i])

print(count_score(arrays))