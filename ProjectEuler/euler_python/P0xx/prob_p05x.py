from utils.help import Number


def P57():
    n1 = Number(1)
    n2 = Number(2)
    n1_2 = Number(1, 2)

    prev_t = n1 + n1_2
    cnt = 0

    for i in range(2, 1000+1):
        n1_2 = prev_t + n1
        next_t = n1 + (n1 / n1_2)

        if next_t.len_child > next_t.len_parent:
            cnt += 1

        print(f"T_{i} = {next_t} / cnt : {cnt}")

        prev_t = next_t
