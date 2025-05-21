"""
1138번 - 한 줄로 서기
N(사람의 수) <= 10 | N - FISRT
키가 1인 사람부터 차례대로 키큰 사람 몇명이 왼쪽에 있는지? - SECOND

"""

N = int(input())
lines = list(map(int, input().split()))
answer = [0] * N

for i in range(N):
    count = 0
    for j in range(N):
        if count == lines[i] and answer[j] == 0:
            answer[j] = i+1
            break
        elif answer[j] == 0:
            count += 1


print(*answer)