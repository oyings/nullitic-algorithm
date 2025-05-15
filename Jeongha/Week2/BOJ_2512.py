# 지방의 수
n = int(input())

# 지방의 예산
n_list = list(map(int, input().split()))

# 국가 예산
m = int(input())

# 최대 금액 선정
n_list.sort()
max_cost = n_list[-1]

start = 1


# O(log max_cost)
while True:
    mid = (start + max_cost) // 2
    sum = 0

    # O(n)
    for i in range(n):
        if n_list[i] >= mid:
            sum += mid
        else:
            sum += n_list[i]

    if start > max_cost:
        break

    # 총 합이 국가 예산보다 적으면 돈을 더 쓸 수 있다.
    if sum <= m:
        start = mid + 1

    # 총 합이 국가 예산보다 많으면 돈을 덜 써야한다.
    if sum > m:
        max_cost = mid - 1


print(mid)