# 상근이 카드
n = int(input())
myCards = list(map(int, input().split()))

# 주어진 카드
m = int(input())
givenCards = list(map(int, input().split()))

# 결과를 출력할 리스트
results = []

myCards.sort()

# 이분 탐색 함수
def binary_search(myCards, card, startIndex, endIndex):
    if startIndex >= endIndex:
        return 0


    start = myCards[startIndex]
    end = myCards[endIndex]
    midIndex = (endIndex + startIndex) // 2
    mid = myCards[midIndex]

    # 시작, 중간, 끝 값이 찾아야할 카드라면 1 반환 후 종료
    if start == card or end == card or mid == card:
        return 1

    if card > mid:
        return binary_search(myCards, card, midIndex + 1, endIndex)
    else:
        return binary_search(myCards, card, startIndex, midIndex - 1)

# 주어진 카드 하나씩 탐색
for i in range(m):
    result = binary_search(myCards, givenCards[i], 0, len(myCards) - 1)
    results.append(result)

# 결과 출력
print(' '.join(map(str, results)))