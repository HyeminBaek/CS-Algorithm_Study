# 골드5-종점
# 힙 or 스위핑


# 처음에 스위핑으로 다가갔으나 실패
# 우선순위큐를 활용한다. -> nlogn에 풀이 가능

import heapq


def convert(time):
    h, m, s = time.split(":")
    s, ms = s.split(".")
    converted = int(h)*3600+int(m)*60+int(s)+int(ms)/1000
    return converted


n = int(input())
times = []
for _ in range(n):
    s, e = input().split()
    times.append((convert(s), convert(e)))

times.sort()  # 입장 시각이 빠른순으로 정렬 -> 그래야 힙에서 입장시각-퇴장시각 계산 순차적으로 가능
# times = [(1,4),(1,6),(1,7),(1,3),(2,9),(4,6),(4,6),(5,10),(5,9),(5,8),(5,12)]
INF = int(1e9)
heap = []

for time in times:
    start, end = time
    if heap and heap[0][2] < start:  # 나가는 시간이 가장 빠른 버스가 지금 들어오는 버스의 입장 시간보다 빠른 경우
        heapq.heappop(heap)  # 겹치지 않으므로 pop
    heapq.heappush(heap, (end, start, end))  # 지금 들어오는 버스 힙에 삽입

print(len(heap))

# 1---4
# 1-----6
# 1------7
# 1--3
#  2--------9
#     4-6      --------> 이 시점에서 3시각에 나가는 버스가 가장 빠르고,  4보다 작으므로 1--3이 pop된다.
#     4-6
#      5----10
#      5---9
#      5--8
#      5------12
