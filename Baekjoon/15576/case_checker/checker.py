import sys

N, M = 0, 0

def readInput():
    with open('input.txt', 'rt') as fin:
        global N, M
        N, M = list(map(int, fin.readline().split()))
        assert N >= 0
        assert M >= 0

def readOutput():
    with open('output.txt', 'rt') as fin:
        K = int(fin.readline())
        assert N * M == K, f"{N} * {M} = {N*M} != {K}"
    
def check():
    pass

if __name__ == "__main__":
    readInput()
    readOutput()
    check()
