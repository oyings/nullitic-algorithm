"""
1920번 - 수 찾기
O(LOGN + MLOGN)
N와 M은 범위가 같으니 최악의 경우에는
O(NLOGN)
"""

N = int(input())
arr = list(map(int, input().split()))
M = int(input())
find_arr = list(map(int, input().split()))
#O(logN)
arr.sort()

def bs(arr, start, end, target):

    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return 1
        elif arr[mid] < target:
            start = mid + 1
        else:
            end = mid - 1

    return 0

#O(logM)
for target in find_arr:
    print(bs(arr, 0, N - 1, target))
