"""
1932번 - '정수 삼각형'
삼각형 이루는 정수 0 <= INT <= 9999
삼각형의 크기 1 <= N <= 500
N+1 줄까지 정수 삼각형
"""

n = int(input())
triangle = [list(map(int, input().split())) for _ in range(n)]
# -1층의 값을 더해서 경로의 값을 누적해야 해서 0층은 제외
for i in range(1, n):
    for j in range(i + 1):
        if j == 0:
            triangle[i][j] += triangle[i - 1][j]
        elif j == i:
            triangle[i][j] += triangle[i - 1][j - 1]
        else:
            triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j])

print(max(triangle[-1]))

