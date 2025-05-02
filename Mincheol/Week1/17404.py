"""
RGB거리 2 - 17404번
첫 요소를 고정하고 실험.
t_cost <= 1000 * 1000 (N)
"""
INF = float('inf')
n = int(input())
cost = [list(map(int, input().split())) for _ in range(n)]

total = INF

for fixed in range(3):
    dp = [[INF] * 3 for _ in range(n)]
    dp[0][fixed] = cost[0][fixed]

    for i in range(1, n):
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0]
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + cost[i][1]
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2]

    for last_color in range(3):
        if last_color != fixed:
            total = min(total, dp[n-1][last_color])

print(total)