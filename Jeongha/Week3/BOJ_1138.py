n = int(input())
taller_count = list(map(int, input().split()))

# taller_count(왼쪽 사람 수) 배열 반복
    # 1부터 끝까지 사람들을 검사한다.
        # 본인의 왼쪽 사람 수가 0이면
            # 배열의 맨 뒤에 사람을 넣는다.
                # 배열을 가지고 검사한다.
                    # 내 앞자리 사람이 나보다 큰지 카운트한다.
                    # 카운트한 값이 왼쪽 사람 수와 같으면 검사 성공
                    # 카운트한 값이 왼쪽 사람 수와 다르면 검사 실패
                # 검사를 성공 했으면 다음으로 넘어간다.
            # 검사를 실패 했으면 방금 넣었던 자리 앞에 넣어 본다.
                # 배열을 가지고 검사한다.
        # 왼쪽 사람 수가 2면
            # 배열의 맨 뒤에 넣는다.
                # 배열을 가지고 검사한다.
                # ...
results = []

def checking(person, count, current_index):
    # print(f"{person}의 왼쪽 사람 수는 {count}이므로 배열에 넣고 검사한다.")
    # print(f"현재 배열은 {results}이다.")

    new_count = 0

    # 본인보다 왼쪽 값이 본인보다 큰지 확인한다.

    for i in range(current_index):
        if results[i] > person:
            new_count += 1

    if new_count == count:
        return True
    else:
        return False


for count in range(n):

    for person in range(n):
        if taller_count[person] == count:

            current_index = len(results)
            results.insert(current_index, person)

            checked = checking(person, count, current_index)
            while checked == False:
                # print("다시 검사한다.")
                # 넣은 값 빼고 다시 넣기
                results.remove(person)
                current_index -= 1
                results.insert(current_index, person)
                checked = checking(person, count, current_index)

for i in range(n):
    print(results[i] + 1, end= " ")