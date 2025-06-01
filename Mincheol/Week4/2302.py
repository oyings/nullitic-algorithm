"""
2302번 - 극장 좌석
1 <= N <= 40
0 <= M <= N
다음 M 개의 줄에는 고정석의 번호가 작은 수부터 큰 수의 순서로 한 줄에 하나씩 입력된다.
사람들이 좌석에 앉는 서로 다른 방법의 가짓수를 구하는 프로그램
경우의 수 이용.

"""
N = int(input())
M = int(input())
fixed = [int(input()) for _ in range(M)]
num_case = [0] * (N + 1)

# 총 i자리일 때 배치 가능한 경우의 수 갱신
num_case[0] = 1 # 빌 때
num_case[1] = 1

# 총 i자리일 때 배치 가능한 경우의 수 갱신
for i in range(2, N+1):
    num_case[i] = num_case[i-1] + num_case[i-2]

answer = 1
start = 0

# 고정석 제외 범위만큼의 경우의 수 곱 b-a-1 (0도 fixed 가정)
for fs in fixed:
    length = fs - start - 1
    answer *= num_case[length]
    start = fs

# 마지막 구간이거나, fixed가 없거나 b-a
answer *= num_case[N-start]

print(answer)

