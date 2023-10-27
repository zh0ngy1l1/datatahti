from math import sqrt
n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    print("YES" if b >= (sqrt(a) + 1) * (sqrt(a) + 1) else "NO") 