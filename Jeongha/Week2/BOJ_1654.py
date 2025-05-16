import sys

k, n = map(int, input().split())

# 랜선 입력 받기
cables_str = list(sys.stdin.read().splitlines())
cables = []
# 입력 받은 랜선을 정수로 바꿈
for cable in cables_str:
    cables.append(int(cable))

# 가장 짧은 랜선을 저장한다.
cables.sort()
max_cable = cables[-1]

# 가장 짧은 랜선으로부터 탐색한다.
start = 1
end = max_cable

while True:
    # 이분 탐색의 중간 값
    mid = (start + end) // 2

    # 랜선의 개수 확인
    count = 0
    for cable in cables:
        count += cable // mid

    # 이분 탐색 종료
    if start > end :
        break

    # 개수가 부족하면 더 짧게 해서 다시 자른다.
    if count < n:
        end = mid - 1

    # 개수가 많으면 더 길게 해서 다시 자른다.
    # 개수가 같으면 더 길게 해서 자를 수 있는지 본다.
    if count >= n:
        start = mid + 1

print(mid)