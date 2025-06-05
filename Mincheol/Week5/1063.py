"""
1063번 - '킹'
열 A-H J
행 1-8 I
1 <= N <= 50
입력 A1 A2 -> 반전 그리고 행값도 반전
8 - 1 = 7(맨 아래) 1= 맨 아래
REVERSE 8 - 7 = 1(화자 기준 맨 아래)
"""

# 방향 딕셔너리
direction = {'R': (0, 1),
             'L': (0, -1),
             'B': (1, 0),
             'T': (-1, 0),
             'RT': (-1, 1),
             'LT': (-1, -1),
             'RB': (1, 1),
             'LB': (1, -1)}


king, stone, n = input().split()
n = int(n)
# 각 단위를 0-BASED 정수로 통일, 반전된 행과 열 순서도 변경, 행 순서 반전
# A1 -> 1A 70으로 변환
ki, kj = 8 - int(king[1]), ord(king[0]) - ord('A')
si, sj = 8 - int(stone[1]), ord(stone[0]) - ord('A')

# 킹 이동 방향에 stone이 있으면 같은 방향으로 한 칸 민다, 범위를 벗어나면 우선 이동 무시
for _ in range(n):
    dirs = input()
    nki = ki + direction[dirs][0]
    nkj = kj + direction[dirs][1]

    # k가 유효범위 내라면
    if 0 <= nki < 8 and 0 <= nkj < 8:
        # 밀었는데 같은 위치면 동등하게 밀어줌
        if nki == si and nkj == sj:
            nsi = si + direction[dirs][0]
            nsj = sj + direction[dirs][1]
            # 모두 out of index가 아니면 k, s 갱신
            if 0 <= nsi < 8 and 0 <= nsj < 8:
                ki, kj = nki, nkj
                si, sj = nsi, nsj
        # 밀었는데 같은 위치가 아니라면 k만 갱신
        else:
            ki, kj = nki, nkj


# 마지막으로 행과 열 순서 반전시키고 결합하여 출력
print(chr(kj + ord("A")) + str(8-ki))
print(chr(sj + ord("A")) + str(8-si))
