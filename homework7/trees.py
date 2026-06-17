import sys

n = int(input())

tree = {}

for _ in range(n):
    idx, value, left, right = input().split()

    tree[int(idx)] = (
        None if left == "None" else int(left),
        None if right == "None" else int(right)
    )

root = 0

def max_depth(v):
    if v is None:
        return 0

    left, right = tree[v]
    return 1 + max(max_depth(left), max_depth(right))

print(max_depth(root))