def solution(x):
    answer = False
    numbers = list(str(x))
    value = 0
    for i in range(len(numbers)):
        value += int(numbers[i])
    if x % value == 0:
        answer = True
    return answer