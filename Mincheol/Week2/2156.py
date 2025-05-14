"""
2156번 - 포도주 시식
1 <= N <= 100,000
"""

N = int(input())
wines = [int(input()) for _ in range(N)]

wine_flow = [0] * N
#dp 0 초기화
wine_flow[0] = wines[0]

if N > 1:
    wine_flow[1] = wines[0] + wines[1]
#OOX OXO XOO 총 3개일 때
if N > 2:
    wine_flow[2] = max(wine_flow[1], wine_flow[0] + wines[2], wines[1] + wines[2])

#i >= 3
for i in range(3, N):
    #OOX OXO XOO
    wine_flow[i] = max(wine_flow[i-1], wine_flow[i-2] + wines[i], wine_flow[i-3] + wines[i] + wines[i-1])

print(wine_flow[N-1])