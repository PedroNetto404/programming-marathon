def retangulom(L, C, QL, QC, memo={}):
    if L==1:  return 0
    if C==QC: return 1
    if L==QL: return 2
    if C==1:  return 3
    if (L, C, QL, QC) not in memo:
        memo[(L, C, QL, QC)] = retangulom(L-1, C,   QL, QC) + \
                               retangulom(L-1, C-1, QL, QC) + \
                               retangulom(L,   C-1, QL, QC)
    return memo[(L, C, QL, QC)]

QL, QC = input().split()
QL = int(QL)
QC = int(QC)
L, C = input().split()
L = int(L)
C = int(C)
print(retangulom(L, C, QL, QC))
