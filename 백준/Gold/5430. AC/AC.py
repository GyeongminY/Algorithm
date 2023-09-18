import sys
from collections import deque

t = int(sys.stdin.readline())

for i in range(t):
    dq = deque()
    cmd = sys.stdin.readline()
    length = int(sys.stdin.readline())
    str = sys.stdin.readline()
    front = True
    #print(str[1:-2])
    if length == 0:
        if('D' in cmd):
            dq = "error"
    else:
        L = list(map(int, str[1:-2].split(',')))
        #print(L)
        for i in range(len(L)):
            dq.append(L[i])
        for i in range(len(cmd)-1):
            #print(cmd[i])
            if(cmd[i] == 'R'):
                front = not front
            else:
                if not dq:
                    #print("empty")
                    dq = "error"
                    break
                if front:
                    dq.popleft()
                else:
                    dq.pop()
                #print("pop")               
   
    if dq == "error":
        print(dq)
    else:
        if not front:
            #print("not front")
            dq.reverse()
        print("[", end = "")
        for i in range(len(dq)):
            if(i < len(dq)-1):
                print(dq[i], end = ",")
            else:
                print(dq[i], end = "")
        print("]")