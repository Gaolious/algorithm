with open('input.txt', 'rt') as fin:
    m, s, x1, x2 = list(map(int, fin.readline().split()))

with open('output.txt', 'rt') as fin:
    a, c = list(map(int, fin.readline().split()))
    
assert 0 <= a < m
assert 0 <= c < m

ans_x1 = ( a * s + c ) % m
assert ans_x1 == x1 

ans_x2 = ( a * ans_x1 + c ) % m;
assert ans_x2 == x2
