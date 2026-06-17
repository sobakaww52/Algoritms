def merge_sort(a):
    if len(a) <= 1:
        return a, 0
    
    m = len(a) // 2
    l, inv_l = merge_sort(a[:m])
    r, inv_r = merge_sort(a[m:])
    
    res = []
    i = j = 0
    inv = inv_l + inv_r
    
    while i < len(l) and j < len(r):
        if l[i] <= r[j]:
            res.append(l[i])
            i += 1
        else:
            res.append(r[j])
            inv += len(l) - i
            j += 1
    
    res.extend(l[i:])
    res.extend(r[j:])
    return res, inv

n = int(input())
a = list(map(int, input().split()))
print(merge_sort(a)[1])