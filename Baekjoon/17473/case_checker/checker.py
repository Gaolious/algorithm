import sys

MaxN = 200_000
MaxA = 2**20 - 1
MaxM = 200_000

N = 0
M = 0
A = []
cmd_list=[]
def readInput():
    global A
    with open('input.txt', 'rt') as fin:
        N = int(fin.readline())
        assert 1 <= N <= 200_000

        A = list(map(int, fin.readline().split(' ') ))
        assert len(A) == N
        for a in A:
            assert 0 <= a <= MaxA

        M = int(fin.readline())
        assert 1 <= M <= MaxM

        for _ in range(M):
            cmd = list(map(int, fin.readline().split()))
            assert 3 <= len(cmd) <=4
            if cmd[0] in [ 1, 2 ]:
                assert len(cmd) == 4
                assert 1 <= cmd[1] <= cmd[2] <= N
                assert 0 <= cmd[3] <= MaxA

            if cmd[0] in [3]:
                assert len(cmd) == 3
                assert 1 <= cmd[1] <= cmd[2] <= N
            
            cmd_list.append(cmd)


BOJ_OUTPUT = []
VALID_OUTPUT = []

def readOutput():
    with open('output.txt', 'rt') as fin:
        for row in fin:
            BOJ_OUTPUT.append( int(row) )
    
def check():
#    print("Init A = ", A)
    for cmd in cmd_list:
        op = cmd[0]
        if op == 1:
            for i in range(cmd[1]-1, cmd[2]):
                A[ i ] = A[ i ] & cmd[3]
        elif op == 2:
            for i in range(cmd[1]-1, cmd[2]):
                A[ i ] = A[ i ] | cmd[3]
        elif op == 3:
            VALID_OUTPUT.append( max( A[ cmd[1] - 1 : cmd[2] ] ) )
#        print(f"after {cmd}", A)


    assert len(BOJ_OUTPUT) == len(VALID_OUTPUT)
    for x, y in zip(BOJ_OUTPUT, VALID_OUTPUT):
        assert x == y, f"BOJ={x}, VALID={y}"

if __name__ == "__main__":
    readInput()
    readOutput()
    check()
