def power(base, exponent, modulus):
    result = 1
    while exponent > 0:
        if exponent % 2 == 1:
            result = (result * base) % modulus
        base = (base * base) % modulus
        exponent //= 2
    return result

def rabin_karp(text, pattern, prime):
    n = len(text)
    m = len(pattern)
    p = 0  # Hash value for pattern
    t = 0  # Hash value for text
    h = power(10, m-1, prime)  # Hash multiplier for digits

    result = []

    # Calculate initial hash values for pattern and text
    for i in range(m):
        p = (10 * p + int(pattern[i])) % prime
        t = (10 * t + int(text[i])) % prime

    for i in range(n-m+1):
    
        if p == t:
            match = True
            for j in range(m):
                if pattern[j] != text[i+j]:
                    match = False
                    break
            if match:
                result.append(i)

        if i < n-m:
            t = (10 * (t - int(text[i]) * h) + int(text[i+m])) % prime
            if t < 0:
                t = t + prime

    return result


text = "3141592653589793"
pattern = "26"
prime = 101  
# A prime number to prevent collisions

matches = rabin_karp(text, pattern, prime)
print("Pattern found at indices:", matches)


