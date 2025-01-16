import math
import random

N = 100000 #N=100000

print(N)

xmin=0
xmax=2**27

s=[0]

for i in range(N//4):
    s.append(round(random.random()**0.5 * random.randint(xmin, xmax)))

for i in range(N//4):
    s.append(round(random.random()**2 * random.randint(xmin, xmax)))

xmin=2**29+2**27
xmax=2**29+2**28

for i in range(N//4):
    s.append(round(random.random()**0.5 * random.randint(xmin, xmax)))

for i in range(N//4):
    s.append(round(random.random()**2 * random.randint(xmin, xmax)))

for i in range(1, len(s)):
    print(s[i-1] ^ s[i], end=" ")
print()