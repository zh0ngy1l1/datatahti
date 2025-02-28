
with open("primes.txt") as h:
    primes = [int(i) for i in h.read().split(" ")]

def is_prime(i: int) -> bool:
    # Basic divisors test
    if i < 2:
        return False
    if i in primes:  # 2 and 3 are prime
        return True
    if i % 2 == 0:  # Even numbers greater than 2 are not prime
        return False

    # Basic test
    for n in primes:
        if i % n == 0:
            print(f"{n} divides {i}.")
            return False

    # Basic test
    for n in range(primes[-1], int(i**0.5) + 1):
        if i % n == 0:
            print(f"{n} divides {i}.")
            return False

    return True

def is_square(n: int) -> bool:
    if n < 0:
        return False
    sqrt_n = int(n**0.5)
    return sqrt_n**2 == n