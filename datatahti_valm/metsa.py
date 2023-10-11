# https://cses.fi/dt/task/349, 11.10.2023

n, m, q = map(int, input().split())

sums = [[0]*(m + 1) for _ in range(n + 1)]

output = ""

for row in range(1, n + 1):
    line = input()

    for col in range(1, m + 1):
        sums[row][col] = sums[row][col-1] \
            + sums[row-1][col] \
            - sums[row-1][col-1] \
            + (1 if line[col-1] == "*" else 0)


for _ in range(q):
    y1, x1, y2, x2 = map(int, input().split())
    
    print(
        sums[y2][x2]\
        - sums[y2][x1-1]\
        - sums[y1-1][x2]\
        + sums[y1-1][x1-1]
        )
 
