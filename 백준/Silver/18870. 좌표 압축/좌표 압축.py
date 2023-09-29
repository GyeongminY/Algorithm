import sys

def binary_search(array, start, end, target):
    while(start <= end):
        mid = (start + end) // 2
        if(array[mid] == target):
            return mid
        elif(array[mid] > target):
            end = mid - 1
        else:
            start = mid + 1

    return None

n = int(sys.stdin.readline().rstrip())
L = list(sys.stdin.readline().rstrip().split())
L = list(map(int, L))
M = sorted(set(L))
for i in range(n):
    L[i] = binary_search(M, 0, len(M), L[i])
print(*L)