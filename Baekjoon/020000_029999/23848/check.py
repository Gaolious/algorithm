import sys

S = 0
with open('./input.txt', 'rt') as fin:
    S = int(fin.readline())

with open('./output.txt', 'rt') as fin:
    N = int(fin.readline())
    A = list(map(int, fin.readline().split()))

assert N >= 3
a = A[0]
r = A[1] // A[0]

for i in range(1, N):
    assert A[i] % A[i-1] == 0
    assert A[i] // A[i-1] == r
    assert A[i-1] * r == A[i]


assert sum(A) == S

print( f"success a={a}, r={r}" )
