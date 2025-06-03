from itertools import combinations

n, m = map(int, input().split())

maps = [[0] * (n + 1) for _ in range(n + 1)]
houses = []
chickens = []

# 1부터 시작하는 맵
for i in range(1, n + 1):
    inputs = list(map(int, input().split()))
    for j in range(1, n + 1):
        maps[i][j] = inputs[j - 1]
        if inputs[j - 1] == 1:
            houses.append([i, j])
        elif inputs[j - 1] == 2:
            chickens.append([i, j])
        else:
            pass

# m 개를 선정하는 모든 경우의 수 비교
combi_ckickens = list(combinations(chickens, m))

# m 개를 선정하여 거리 비교
min_result = 2500
for i in range(len(combi_ckickens)):
    result = 0
    # print(combi_ckickens[i], '가 선정된다면?')


    # 첫 번째 집부터 m개의 치킨 중에 가장 가까운 거리 선정
    for j in range(len(houses)):
        house_x = houses[j][0]
        house_y = houses[j][1]
        min_distance = 100

        for k in range(m):
            distance = 0
            chicken_x = combi_ckickens[i][k][0]
            chicken_y = combi_ckickens[i][k][1]

            # 거리 계산
            distance = abs(house_x - chicken_x) + abs(house_y - chicken_y)

            min_distance = min(min_distance, distance)

        # print(f'{house_x}, {house_y} 에서 {combi_ckickens[i]}중에서 가까운 치킨집과의 거리는 {min_distance}')
        result += min_distance
    min_result = min(min_result, result)


print(min_result)