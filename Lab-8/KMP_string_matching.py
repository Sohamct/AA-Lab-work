# KMP Algorithm
def preprocessing(pattern):
    m = len(pattern)
    pi = [0] * m
    k = 0
    for q in range(1, m):
        while k > 0 and pattern[k] != pattern[q]:
            k = pi[k - 1]
            
        if pattern[k] == pattern[q]:
            k += 1
            
        pi[q] = k
    print(pi)
    return pi
    
def kmp(text, pattern):
    n = len(text)
    m = len(pattern)
    pi = preprocessing(pattern)
    
    q = 0
    position = []
    
    for i in range(n):
        while q > 0 and pattern[q] != text[i]:
            q = pi[q - 1]
        
        if text[i] == pattern[q]:
            q += 1
            
        if q == m:
            position.append(i - m + 1)
            q = pi[q - 1]
    
    return position

# Example usage:
text = "ABBABCABABBABBFABBABB"
pattern = "ABBABB"
matches = kmp(text, pattern)
if matches:
    print("Pattern found at positions:", matches)
else:
    print("Pattern not found in the text.")