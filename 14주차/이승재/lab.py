#https://www.acmicpc.net/problem/14502
import sys
from itertools import combinations
from collections import deque
from copy import deepcopy
input = sys.stdin.readline

def bfs(board):
    count = len(empty) - 3
    visited = [[-1] * M for _ in range(N)]
    for y, x in virus:
        dq = deque([(y, x)])
        visited[y][x] = 0
        while dq:
            ty, tx = dq.popleft()
            for i in range(4):
                ny, nx = ty + moves[i][0], tx + moves[i][1]
                if 0 <= ny < N and 0 <= nx < M and visited[ny][nx] == -1 and board[ny][nx] == 0:
                    if board[ny][nx] == 0:
                        count -= 1
                    visited[ny][nx] = visited[ty][tx] + 1
                    board[ny][nx] = 2
                    dq.append((ny, nx))
    return count # 남은 공간 수

moves = [[0, -1], [0, 1], [1, 0], [-1, 0]]
N, M = map(int, input().split())
board, virus, empty = [], [], []
for i in range(N):
    tmp = list(map(int, input().split()))
    for idx, val in enumerate(tmp):
        if val == 2:
            virus.append((i, idx))
        elif val == 0:
            empty.append((i, idx))
    board.append(tmp)

answer = 0
for i in combinations(empty, 3):
    tmp = deepcopy(board)
    for y, x in i:
        tmp[y][x] = 1
    answer = max(answer, bfs(tmp))
print(answer)
