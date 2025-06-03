
n = int(input())
m = int(input())
fibonacchi_sequence = [0] * 41

# 피보나치의 수
def fibonacci(n):
    if fibonacchi_sequence[n] != 0:
        return fibonacchi_sequence[n]
    if n == 0 or n == 1:
        fibonacchi_sequence[n] = 1
    else:
        fibonacchi_sequence[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return fibonacchi_sequence[n]

current_seat = 1
number_list = []

for i in range(m):
    number = int(input())
    # 블록 사이즈를 구함
    block_size = number - current_seat
    # 블록 사이즈를 리스트에 넣음
    number_list.append(block_size)
    # 다음 블록을 위해 자리 옮김
    current_seat = number + 1

# 마지막 VIP 좌석 이후의 블록
block_size = n - current_seat + 1
number_list.append(block_size)

answer  = 1
for i in range(len(number_list)):
    answer *= fibonacci(number_list[i])

print(answer)
