import random, decimal, math

def main():
    min = 1000000
    max = random.getrandbits(24)

    p = findSafePrime(min,max)
    g = findGenerator(p)
    print(p,g)

def findSafePrime(min,max):
    rnd = random.randint(min, max)
    while not isPrimeSafe(rnd):
        rnd = findPrime(min, max)
    return rnd

def findPrime(min, max):
    rnd = random.randint(min, max+1)
    while not isPrime(rnd):
        rnd = random.randint(min, max + 1)
    return rnd

def isPrimeSafe(n):
    return isPrime((n - 1) / 2)

def isPrime(n):
    if (n <= 3):
        return n > 1
    elif n % 2 == 0 or n % 3 == 0:
        return False
    else:
        i = 5
        while (i * i <= n):
            if (n % i == 0 or n % (i + 2) == 0):
                return False
            i += 6
        return True


def findGenerator(p):
    g = random.randint(2, p - 1)
    while not isGenerator(p, g):
        g = random.randint(2, p - 1)

    return g

def isGenerator(p, g):
    decimal.getcontext().prec = 99999999
    result = decimal.Decimal(g) ** decimal.Decimal((p-1)/2) % decimal.Decimal(p)
    if result != 1:
        return True

if __name__ == '__main__':
    main()