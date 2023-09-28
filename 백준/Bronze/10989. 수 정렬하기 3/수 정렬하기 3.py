import sys

n = int(sys.stdin.readline().rstrip()) #rstrip()은 오른쪽 공백, 즉 개행문자 제거
L = [0 for i in range(10001)]
for i in range(n):
    e = int(sys.stdin.readline().rstrip())
    L[e] += 1
for i in range(10001):
    for j in range(L[i]):
        print(i)