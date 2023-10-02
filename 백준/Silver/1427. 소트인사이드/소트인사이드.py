import sys
str = sys.stdin.readline().rstrip()
L = list(str[0:])
L.sort(reverse = True)
for i in range(len(L)):
    print(L[i], end='')