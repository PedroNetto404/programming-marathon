n = int(input())
l, u = map(int, input().split())
seq = [l < int(input()) < u for _ in range(n)]

sqrt = int(n**.5)
blocks = [sum(seq[i:i+sqrt]) for i in range(0, n, sqrt)]

try:
    while True:
        x, y = map(int, input().split())
        # print(sum(seq[x:y+1]))

        # sum, i = 0, x
        # while i <= y:
        #     if i % sqrt == 0 and i + sqrt - 1 <= y:
        #         sum += blocks[i // sqrt]
        #         i += sqrt
        #     else:
        #         sum += seq[i]
        #         i += 1
        # print(sum)

        x_int, x_res = x.__divmod__(sqrt)
        y_int, y_res = (y+1).__divmod__(sqrt)

        soma = 0
        if x_int < y_int:
            soma += sum(blocks[x_int : y_int])
        if x_res:
            soma += sum(seq[x : (x_int+1)*sqrt])
        if y_res:
            soma += sum(seq[y_int*sqrt : y+1])

        print(soma)

except EOFError:
    pass
