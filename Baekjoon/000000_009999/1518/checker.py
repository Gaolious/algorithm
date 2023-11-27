import sys

A = [
    list(map(int, sys.stdin.readline().split())) for _ in range(5)
]
B = [True] + [False] * 25

for i in range(5):
    for j in range(1,5):
        assert A[i][j] > A[i][j-1]
    for j in range(5):
        assert B[ A[i][j] ] == False
        B[ A[i][j] ] = True

assert all(B)        
