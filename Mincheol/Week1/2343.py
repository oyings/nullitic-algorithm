"""
기타 레슨 - 2343번
"""
n, m = map(int, input().split())
lessons = list(map(int, input().split()))

start = max(lessons)
end = sum(lessons)
answer = end

while start <= end:
    mid = (start + end) //2
    count = 1
    total = 0

    for lesson in lessons:
        #누적합이 mid보다 크다면 total 초기화 ^ count++
        if total + lesson > mid:
            count += 1
            total = 0
        total += lesson

    if count <= m:
        answer = mid
        end = mid -1
    else:
        start = mid + 1

print(answer)