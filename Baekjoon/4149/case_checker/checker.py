import sys

N = 0
K = 0

def readInput():
    with open('input.txt', 'rt') as fin:
        N = int(fin.readline())
        assert N >= 0

def readOutput():

    with open('output.txt', 'rt') as fin:
        K = 1
        for line in fin:
            t = int(line)
            assert K >= 1
            K *= t
    
def check():
    assert N == K
if __name__ == "__main__":
    readInput()
    readOutput()
    check()
