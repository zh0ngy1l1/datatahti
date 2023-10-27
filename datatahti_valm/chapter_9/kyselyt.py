# https://cses.fi/dt/task/359, 1.10.2023

import time
import sys

def main():
    input = sys.stdin.readline
    n, q = tuple(input().split(" ")) # constant
    taulukko = [int(i) for i in input().split(" ")] # O(n)
    sums = taulukko[:] # O(n)
    for i in range(1,  int(n)): # O(n^2) but small
        sums[i] = sums[i] + sums[i-1]

    output = ""
    for _ in range(int(q)): 
        line = input()
        space = line.find(" ")
        a = int(line[:space])
        b = int(line[space+1:])
        if a == 1:
            output = output + str(sums[b - 1]) + "\n"
        else:
            output = output + str(sums[b - 1] - sums[a - 2]) + "\n"
    #print(output[:-1])
    print("success")

start = time.time()

main()

print(time.time() - start)