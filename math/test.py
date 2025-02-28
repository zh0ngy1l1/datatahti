from func import *

N = 1000
totient = [0] * (N+1)
sigma = [0] * (N+1)

with open("totient_and_sigma.txt") as h:
    for line in h.read().split("\n"):
        a, b, c = map(int, line.split(" "))
        totient[a] = b
        sigma[a] = c

def main():
    print(totient[100])
    

    
if __name__ == "__main__":
    main()
