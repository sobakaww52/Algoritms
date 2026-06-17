n, k = map(int, input().split())
a = list(map(int, input().split()))

def backtrack(i, s):
    if s == k:
        return True
    if i == n or s > k:
        return False
    if backtrack(i + 1, s + a[i]):
        return True
    if backtrack(i + 1, s):
        return True
    return False

print("YES" if backtrack(0, 0) else "NO")