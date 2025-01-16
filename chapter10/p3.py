def f(n):
    if n == 0: return 0
    if n % 2 == 0: return n.bit_count() + f(n-1)
    return 2 * f(n//2) + n//2 + 1

print(f(int(input())))