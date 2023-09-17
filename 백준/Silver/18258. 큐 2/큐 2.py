import sys
from collections import deque

dq = deque()

def push(x):
    dq.append(x)

def pop():
    if not dq:
        print(-1)
    else:
        print(dq.popleft()) 

def size():
    print(len(dq))

def empty():
    if not dq:
        print(1)
    else:
        print(0)

def front():
    if not dq:
        print(-1)
    else:
        print(dq[0])

def back():
    if not dq:
        print(-1)
    else:
        print(dq[-1])



t = int(sys.stdin.readline())

for i in range(t):
    cmd = sys.stdin.readline().split()
    if cmd[0] == "push":
        push(int(cmd[1]))
    elif cmd[0] == "pop":
        pop()
    elif cmd[0] == "size":
        size()
    elif cmd[0] == "empty":
        empty()
    elif cmd[0] == "front":
        front()
    elif cmd[0] == "back":
        back()