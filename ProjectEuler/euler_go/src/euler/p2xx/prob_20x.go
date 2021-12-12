package p2xx

func P201() uint64 {
	const MaxN = 100
	const subsetN = 50
	const MaxSum = 295425

	var D[MaxN+1][subsetN+1][MaxSum+1] int
	var A = [MaxN+1]int {
		0, 1,3,6,8,10,11,
	}
	var ret uint64
	var n, i, s int

	for n = 0 ; n <= MaxN ; n ++ {
		A[n] = n*n
		D[n][0][0] = 1
	}

	for n = 1 ; n <= MaxN ; n ++ {
		for i = 1 ; i <= subsetN ; i ++ {
			for s = 1 ; s <= MaxSum ; s++ {
				D[n][i][s] = D[n-1][i][s]
				if s >= A[n] {
					D[n][i][s] += D[n-1][i-1][s - A[n]]
				}
			}
		}
	}
	for s = 0; s <= MaxSum; s++ {
		if D[MaxN][subsetN][s] == 1 {
			ret += uint64(s)
		}
	}
	return ret
}
