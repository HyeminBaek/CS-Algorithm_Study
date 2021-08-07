from itertools import combinations

N = int(input())
ability_board = []
for _ in range(N):
    ability_board.append(list(map(int, input().split())))

num_list = [i for i in range(N)]
res = float('inf')


def solve():
    global res

    # 조합을 이용하여 각 후보자를 생성함
    for cand in combinations(num_list, N // 2):
        # 선택된 후보와 나머지
        start_member = list(cand)
        link_member = list(set(num_list) - set(cand))

        # 점수 비교는 2명씩 이루어진다.
        start_comb = list(combinations(start_member, 2))
        link_comb = list(combinations(link_member, 2))

        # 점수 구하기
        start_sum = 0
        for x, y in start_comb:
            start_sum += (ability_board[x][y] + ability_board[y][x])

        link_sum = 0
        for x, y in link_comb:
            link_sum += (ability_board[x][y] + ability_board[y][x])

        # 차이를 구하는 것이므로 abs 사용
        if (res > abs(start_sum - link_sum)):
            res = abs(start_sum - link_sum)


solve()
print(res)
