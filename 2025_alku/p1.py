n, m, k = map(int, input().split(" "))
if m * k % n == 0:
    print(f"{m * k // n} " * 2)
else:
    print(f"{m * k // n} {m * k // n + 1}")
