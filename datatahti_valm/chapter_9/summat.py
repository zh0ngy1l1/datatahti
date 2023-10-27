# https://cses.fi/dt/task/353, 13.10.2023


def p(k: int):
    """
    largest power of 2 to divide k
    """
    bk = bin(k)
    # try int.bit_length
    for i in range(32):
        if bk[-(i + 1)] == "1":
            return 1 << i


def sum_ab(a: int, b: int):
    if a == 1:
        return sum_one(b)
    return sum_one(b) - sum_one(a - 1)


def sum_one(x: int):
    sum = 0
    ftree_index = 1 << (x.bit_length() - 1)

    for _ in range(32):
        sum += house_ftree[ftree_index - 1]
        if ftree_index == x:
            break

        ftree_index += 1 << ((x - ftree_index).bit_length() - 1)
    return sum



n, q = map(int, input().split())

house_array = list(map(int, input().split()))

house_ftree = [0] * n

# construction
for k in range(n):
    pk = p(k + 1)
    for j in range(pk):
        house_ftree[k] += house_array[k - j]

#print(house_ftree)

for _ in range(q):
    op, aork, borx = tuple(input().split())
    aork, borx = map(int, (aork, borx))
    if op == "!":
        d = borx - house_array[aork - 1]
        house_array[aork - 1] = borx
        
        ftree_index = aork
        for _ in range(32):
            house_ftree[ftree_index - 1] += d
            ftree_index += p(ftree_index)
            if ftree_index > n:
                break
        
        
        house_ftree[aork - 1]
    else:
        #print(f"summing [{aork}, {borx}]: ", end="")
        print(sum_ab(aork, borx))
