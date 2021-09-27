n = int(input())
lines = [tuple(map(int, input().split())) for _ in range(n)]
lines.sort()
dp = [1]*n

for i in range(1, n):
    target = 1
    for j in range(i):
        if lines[i][1] > lines[j][1]:
            target = max(target, dp[j]+1)
    dp[i] = target

print(n-max(dp))
