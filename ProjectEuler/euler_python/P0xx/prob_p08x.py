from queue import PriorityQueue


def P82():
    dx = [0, 1, 0]
    dy = [1, 0, -1]

    D = {}
    Q = PriorityQueue()
    N = 80
    A = []

    with open('p0xx/p82.in', 'rt') as fin:
        i = 0
        for line in fin:
            A.append(list(map(int, line.strip().split(','))))

    x = 0
    for y in range(N):
        Q.put((y, x, A[y][x]))
        D.setdefault((y, x), A[y][x])

    while not Q.empty():
        y, x, dist = Q.get()

        for ty, tx in zip(dy, dx):
            new_y, new_x = y + ty, x + tx

            if 0 <= new_y < N and 0 <= new_x < N:
                key = new_y, new_x
                new_dist = A[new_y][new_x] + dist

                D.setdefault(key, -1)
                if D[key] < 0 or D[key] > new_dist:
                    D[key] = new_dist
                    Q.put((new_y, new_x, new_dist))

    return min([D[i,N-1] for i in range(N)])

def P83():
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]

    D = {}
    Q = PriorityQueue()
    N = 80
    A = []

    with open('p0xx/p83.in', 'rt') as fin:
        i = 0
        for line in fin:
            A.append(list(map(int, line.strip().split(','))))

    x, y = 0, 0
    Q.put((y, x, A[y][x]))

    D.setdefault((y, x), A[y][x])

    while not Q.empty():
        y, x, dist = Q.get()

        for ty, tx in zip(dy, dx):
            new_y, new_x = y + ty, x + tx

            if 0 <= new_y < N and 0 <= new_x < N:
                key = new_y, new_x
                new_dist = A[new_y][new_x] + dist

                D.setdefault(key, -1)
                if D[key] < 0 or D[key] > new_dist:
                    D[key] = new_dist
                    Q.put((new_y, new_x, new_dist))

    return D[ (N-1, N-1) ]