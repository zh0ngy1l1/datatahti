#https://cses.fi/dt/task/353, 13.10.2023

def p(k: int):
    '''
    largest power of 2 to divide k
    '''
    bk = bin(k)
    for i in range(30):
        if bk[-(i+1)] == "1":
            return 1 << i

n, q = map(int, input().split())

house_array = list(map(int, input().split()))

house_ftree = [0]*n

#construction
for k in range(n):
    pk = p(k+1)
    for j in range(pk):
        house_ftree[k] += house_array[k-j]

print(house_array)
print(house_ftree)


    