from math import sqrt

t = int(input())
v1, v2 = [int(x) for x in input().split(' ')]
ipt = []
for i in range(t):
    ipt.append(int(input()))

n = len(ipt)
blk_idx = - 1
blk_sz = sqrt(n)

block = [0 for _ in range(100)]
arr = []
for i in range(n):
    arr.append(ipt[i])
    if i % blk_sz == 0:
        blk_idx += 1
    if arr[i] >= v1 and arr[i] <= v2:
        block[blk_idx] += 1

while True:
    try:
        sum_ = 0
        l, r = [int(x) for x in input().split(' ')]
        if l>0:
            l -= 1
        r -= 1
        while l<r and l%blk_sz!=0 and l!=0:
            if arr[l] >= v1 and arr[l] <= v2:
                sum_ += 1
            l += 1
        while l+blk_sz-1 <= r:
            sum_ += block[l//blk_sz]
            l += blk_sz

        while l<=r:
            if arr[l] >= v1 and arr[l] <= v2:
                sum_ += 1
            l += 1

        print(sum_)
    except:
        break;
