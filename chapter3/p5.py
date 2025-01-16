n=int(input())
s=[*map(int,input().split()),n+1]
m=x=n
for i in range(n):
    if m < s.index(n-i):
        break
    m = s.index(n-i)
    x-=1
print(x)