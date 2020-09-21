def binary_search(target, data):
    while start <= end:
        mid = (start + end) // 2

        if data[mid] == target:
            return mid
        elif data[mid] < target:
            start = mid + 1드
        else:
            end = mid - 1

    return None