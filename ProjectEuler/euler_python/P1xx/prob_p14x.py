
def P142():
    """
    x > y > z > 0

    x + y
    x - y
    x + z
    x - z
    y + z
    y - z


    x + y = a ^ 2
    x - y = b ^ 2
    x + z = c ^ 2
    x - z = d ^ 2
    y + z = e ^ 2
    y - z = f ^ 2

    2 * x = a^2 + b^2
    2 * y = a^2 - b^2

    2 * x = c^2 + d^2 = a^2 + b^2
    2 * z = c^2 - d^2

    :return:
    """
    N = 1000000

    squares = [False] * (N + 1)
    square_list = []
    square_set = []

    i = 1
    while i*i <= N:
        square_list.append(i*i)
        squares[i * i] = True
        i += 1

    cnt = 0

    for xy_idx in range(len(square_list)):
        xy = square_list[xy_idx]

        for x in range(xy//2 + 1, xy):
            y = xy - x
            if not squares[x-y]: continue

            for xz_idx in range(0, xy_idx):
                xz = square_list[xz_idx]
                z = xz - x
                if z < 1: continue

                if not squares[x+z]: continue
                if not squares[x-z]: continue
                if not squares[y+z]: continue
                if not squares[y-z]: continue

                print(x, y, z, x+y+z)

    return cnt