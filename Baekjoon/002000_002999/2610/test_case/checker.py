import sys

N, M = 0, 0

def readInput():
    with open('input.txt', 'rt') as fin:
        N, M = list(map(int, fin.readline()))
        assert N >= 0
        assert M >= 0

def readOutput():
    with open('output.txt', 'rt') as fin:
        K = int(fin.readline())
        assert K >= 1
    
def check():
    pass

if __name__ == "__main__":
    readInput()
    readOutput()
    check()
