n, m = map(int, input().split())
arr = [[-1 for _ in range(m+1)] for i in range(n+1)]

def nCr(a, b):
    if a == 1:
        return 1
    elif a == b or b == 0:
        return 1
    else:
        if arr[a][b] == -1:
            arr[a][b] = nCr(a-1, b) + nCr(a-1, b-1)
        return arr[a][b]
    
print(nCr(n, m))