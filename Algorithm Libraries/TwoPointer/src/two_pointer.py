# https://www.acmicpc.net/problem/1806
# 합이 s 이상인 최소 구간을 찾는 경우이다.

MAX = 987654321
MIN = -987654321

n, s = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

l, r = 0, 0
min_len = MAX
sum_n = 0

# [l, r) 로 작동
while True:
    if sum_n > s:
        sum_n -= arr[l]
        l += 1

    # r증가 시킬 수 없는 경우 바로 종료
    elif r >= len(arr):
        break
    else:
        sum_n += arr[r]
        r += 1
    if sum_n >= s:
        min_len = min(min_len, r - l)