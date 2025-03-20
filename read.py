def read():
    n_calles = int(input())
    n_inters = int(input())
    m = [[0] * n_calles for i in range(n_calles)]
    for i in range(n_calles):
        line = input().split(" ")
        m[int(line[0]) - 1][int(line[1]) - 1] += 1
        m[int(line[1]) - 1][int(line[0]) - 1] += 1
    return m
