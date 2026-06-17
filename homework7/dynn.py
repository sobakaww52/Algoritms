n = int(input())
lessons = []

for _ in range(n):
    s, e = input().split()
    
    if '.' in s:
        h, m = s.split('.')
        s = int(h) * 60 + int(m)
    else:
        s = int(s) * 60
    
    if '.' in e:
        h, m = e.split('.')
        e = int(h) * 60 + int(m)
    else:
        e = int(e) * 60
    
    lessons.append((s, e))

lessons.sort(key=lambda x: x[1])

res = []
last = -1

for s, e in lessons:
    if s >= last:
        res.append((s, e))
        last = e

print(len(res))
for s, e in res:
    if s % 60 == 0:
        s = str(s // 60)
    else:
        s = str(s // 60) + '.' + str(s % 60)
    
    if e % 60 == 0:
        e = str(e // 60)
    else:
        e = str(e // 60) + '.' + str(e % 60)
    
    print(s, e)