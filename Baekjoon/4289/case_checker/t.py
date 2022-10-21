N, K, D = 21, 100, 9
print(N, K)
for i in range(1, N+1):
    for j in range(i+1, N+1):
        for k in range(K):
            if i == 1 and j == 2 and k < D:
                print(i, 'paper', j, 'rock')
            else:
                print(i, 'rock', j, 'paper')
print(0)
