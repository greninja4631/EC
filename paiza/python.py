def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break  # 途中で入れ替えがなければソート済み
    return arr

# 実行例
arr = [3, 1, 4, 2]
print(bubble_sort(arr))