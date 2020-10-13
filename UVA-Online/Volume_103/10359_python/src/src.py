import sys
"""
1
O
O


1 2
o x
o x

1 2
ooo
xxx

1 2
o o
o o

"""

D = [0]*251

D[1] = 1
D[2] = 3
for i in range(3, 250+1):
    """
        i-1 에서 세로(1x2) 막대 하나 추가 
        i-1 에서 가로(2x1) 두줄 추가 ,  2x2 1개 추가
    """
    D[i] = D[i-1] + D[i-2]*2

for i in range(0,250+1):
    print("\"{}\",".format(D[i]))

# for l in sys.stdin.readline():
#     print(l)