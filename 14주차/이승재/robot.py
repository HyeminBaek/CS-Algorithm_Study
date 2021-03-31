# https://www.acmicpc.net/problem/14503
import sys
input = sys.stdin.readline

move = [[-1, 0], [0, -1], [1, 0], [0, 1]]
N, M = list(map(int, input().split()))
r, c, d = list(map(int, input().split()))  # 청소기 좌표랑 방향. 0이면 북, 1이면 동, 2면남 3이면 서
if d == 1:
    d = 3
elif d == 3:
    d = 1
board = [list(map(int, input().split())) for _ in range(N)]
visited = [[-1] * M for _ in range(N)]
answer = 1
stack = [[r, c, d]]
visited[r][c] = 0
while stack:
    y, x, d = stack.pop()
    i = d
    for _ in range(4):
        i = (i + 1) % 4
        ny, nx = y + move[i][0], x + move[i][1]
        if 0 <= ny < N and 0 <= nx < M and board[ny][nx] == 0 and visited[ny][nx] == -1:
            visited[ny][nx] = visited[y][x] + 1
            stack.append([ny, nx, i])
            answer += 1
            break
    if not stack:
        ny, nx = y - move[d][0], x - move[d][1]
        if 0 <= ny < N and 0 <= nx < M and board[ny][nx] == 0:
            stack.append([ny, nx, i])
print(answer)
