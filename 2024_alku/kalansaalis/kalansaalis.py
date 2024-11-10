n, m, k = map(int, input().split())
price = {"K": 10, "H": -1}

width = m + n // 2

original_arr = [[0]*(width + 1) for _ in range(n + 1)]

for _ in range(k):
    a, b, c = tuple(input().split())
    original_arr[int(a)][int(b) + int(a) // 2] = price[c]
    
for row in range(1, n + 1):
    for col in range(1, width + 1):
        if (col <= row//2) or (col > row//2 + m):
            original_arr[row][col] = 1j


v = [[0]*(width + 1) for _ in range(n + 1)]
r = [[0]*(width + 1) for _ in range(n + 1)]

for row in range(1, n + 1):
    for col in range(1, width + 1):
        this_col_sum = r[row-1][col]\
            - r[row-1][col-1]\
            + original_arr[row][col]
        
        r[row][col] = r[row][col-1] + this_col_sum
            
        v[row][col] = v[row-1][col-1] + this_col_sum


def rsum(y1, x1, y2, x2):
    return r[y2][x2]\
        - r[y2][x1-1]\
        - r[y1-1][x2]\
        + r[y1-1][x1-1]

def vsum(y: int, x: int, size: int):
    return v[y][x]\
        - v[y-size][x-size]\
        - rsum(1, x-size+1, y-size, x)
        
def asum(y: int, x: int, size: int):
    return rsum(y-size, x-size+1, y, x+1)\
        - vsum(y, x + 1, size + 1)

print(original_arr)
print(r)

largest_asum = -500
largest_vsum = -500
for row in range(1, n + 1):
    for col in range(1, width + 1):
        max_size = max(n + 1 - row, width + 1 - col)
        for size in range(1, max_size + 1):
            c_vsum = vsum(row, col, size)
            c_asum = asum(row, col, size)
            
            largest_vsum = max((c_vsum.imag == 0)*c_vsum.real, largest_vsum)
            largest_asum = max((c_asum.imag == 0)*c_asum.real, largest_asum)

            print("row, col, size:", row, col, size)
            print("current asum, current vsum:", c_asum, c_vsum)
            print("largesr sums:",largest_asum, largest_vsum, "\n")
print(max(largest_asum, largest_vsum))