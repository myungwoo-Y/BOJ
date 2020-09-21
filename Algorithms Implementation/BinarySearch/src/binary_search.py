def binary_search(target, data):
    l = 0
    r = len(data) - 1
    while l <= r:
        mid = (l + r) // 2

        if data[mid] == target:
            return mid
        elif data[mid] < target:
            l = mid + 1
        else:
            r = mid - 1

    return None
