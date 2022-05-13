def MergeSort(list):
    if len(list) > 1:
        mid = len(list)//2
        left = list[:mid]
        right = list[mid:]

        MergeSort(left)
        MergeSort(right)

        a = 0
        b = 0
        c = 0

        while a < len(left) and b < len(right):
            if left[a] < right[b]:
                list[c] = left[a]
                a = a + 1

            else:
                list[c] = right[b]
                b = b + 1

            c = c + 1

        while a < len(left):
            list[c] = left[a]
            a = a + 1
            c = c + 1

        while b < len(right):
            list[c] = right[b]
            b = b + 1
            c = c + 1

    return list



example = [45, 654, 132, 8981, 48, 654, 13, 8967, 51, 687, 320, 48, 64, 61, 6542]
print(MergeSort(example))
