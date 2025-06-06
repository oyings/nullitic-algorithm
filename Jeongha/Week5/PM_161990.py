def solution(wallpaper):
    row = len(wallpaper)
    col = len(wallpaper[0])

    min_row = row
    min_col = col
    max_row = 0
    max_col = 0

    for i in range(row):
        for j in range(col):
            if wallpaper[i][j] == '#':
                min_row = min(min_row, i)
                min_col = min(min_col, j)
                max_row = max(max_row, i + 1)
                max_col = max(max_col, j + 1)
    answer = []

    answer.append(min_row)
    answer.append(min_col)
    answer.append(max_row)
    answer.append(max_col)

    return answer