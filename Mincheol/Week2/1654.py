"""
1654번 - 랜선 자르기
모두 같은 길이의 랜선 만들기
O(KlogM)
최대 길이의 BS * 내부 K번 순회
"""
# 원하는 랜선의 개수, 기존 랜선의 개수
K, N = map(int, input().split())
l_lan = [int(input()) for _ in range(K)]
# 가능한 랜선의 길이는 1부터 최대 길이인 max까지
start = 1
end = max(l_lan)
answer = 0

while start <= end:
    mid = (start + end) // 2
    cur_lans = 0

    # 준비한 랜선을 꺼내서 mid 크기로 각각 잘라 준다.
    for lan in l_lan:
        cur_lans += lan // mid
    # 현재 랜선이 N보다 작다면 문제를 충족하지 못한다.
    if cur_lans < N:
        end = mid - 1
    # 현재 랜선이 N보다 크거나 같다면 Promising하다. 최대 길이까지 탐색한다.
    # 랜선의 크기 후보 이후 더 큰 값을 찾는 범위로 변하기에 최대값을 반드시 보장한다.
    else:
        answer = mid
        start = mid + 1

print(answer)