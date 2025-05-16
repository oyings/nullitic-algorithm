# https://school.programmers.co.kr/learn/courses/30/lessons/131128

def solution(X, Y):
    answer = ''
    count_x = [0] * 10
    count_y = [0] * 10

    # 어떤 숫자를 몇 개 가지고 있는지 확인
    for number in str(X):
        count_x[int(number)] += 1

    for number in str(Y):
        count_y[int(number)] += 1

    # 공통 숫자 담기
    commonNumber = []
    for i in range(10):
        if count_x[i] != 0 and count_y[i] != 0:
            times = min(count_x[i], count_y[i])
            commonNumber.extend([i] * times)

    # 예외 처리
    if len(commonNumber) == 0:
        answer = "-1"
        return answer
    if sum(commonNumber) == 0:
        answer = "0"
        return answer

    # 큰 수 찾기
    # 공통으로 찾은 숫자들을 내림차순으로 정렬
    commonNumber.sort(reverse=True)

    # 하나의 숫자로 합치기
    for number in commonNumber:
        answer += str(number)

    return answer

print(solution(11152, 15122))