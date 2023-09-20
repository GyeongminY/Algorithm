import sys
import heapq

#가방 용량이 가장 작은 것부터, 가능한 보석 중 가장 비싼 것을 담는다.
jew = []
bag = []
t = list(map(int, (sys.stdin.readline().split())))
n = t[0]
k = t[1]
for i in range(n):
    t = list(map(int, (sys.stdin.readline().split()))) #첫 번째 원소가 무게, 두 번째가 가격.
    jew.append(t)
jew.sort(key=lambda x: x[0])
for i in range(k):
    bag.append(int(sys.stdin.readline()))
bag.sort()
heap = []
ans = 0
i = 0
for b in bag:
    while(i < n and b >= jew[i][0]):
            heapq.heappush(heap, -jew[i][1]) #최대힙으로 만들기 위해 음수로 만듦
            #print(f"heapq.heappush(heap, {-jew[i][1]})")
            i += 1
    if heap:
        ans += heapq.heappop(heap)
        #print(f"ans = {ans}")

print(-ans)