def primeFactors(n):
    factors = []

    while n % 2 == 0:
        factors.append(2)
        n //= 2
    
    i = 3
    while i * i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i

        i += 2

    if n > 2:
        factors.append(n)

    return factors

X = int(input())
print(len(primeFactors(X)))

