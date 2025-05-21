"""
2563 - 색종이
색종이의 길이는 각각 10
색종이 수 - FIRST LINE (100 이하)
도화지와 색종이 왼쪽변 사이의 거리(X), 도화지와 색종이 아랫변 사이의 거리(Y)  - SECOND LINE
3 7  - 13 17
15 7 - 25 17
5 2 - 15 12
각각 해당 위치에서 10*10 범위를 1로 채워 넣자
"""

N = int(input())

paper = [[0]*100 for _ in range(100)]

for _ in range(N):
    x, y = map(int, input().split())
    for i in range(x, x+10):
        for j in range(y, y+10):
            paper[i][j] = 1

total_area = 0
for row in paper:
    total_area += sum(row)

print(total_area)
