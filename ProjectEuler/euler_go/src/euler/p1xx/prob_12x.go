package p1xx

import (
	"euler/utils"
	"fmt"
)

func P120() int64 {
	// Let r be the remainder when (a−1)^n + (a+1)^n is divided by a^2.
	//
	// For example, if a = 7 and n = 3, then r = 42: 6^3 + 8^3 = 728 ≡ 42 mod 49.
	// And as n varies, so too will r, but for a = 7 it turns out that rmax = 42.
	//
	// For 3 ≤ a ≤ 1000, find ∑ rmax.

	// (a-1)^(2k) MOD a^2 = 1   for k >= 0
	// (a+1)^(2k) MOD a^2 = 1   for k >= 0

	// (a-1)^(2k+1) MOD a^2 = (2k+1) * a   for k >= 0
	// (a+1)^(2k+1) MOD a^2 = (2k+1) * a   for k >= 0

	// find Max( (2 * n * a) MOD (a^2) )

	var a, n, r, rmax, M, S int64

	rmax = 2
	for a = 3 ; a <= 1000 ; a ++ {
		M = a*a
		for n = 1 ; n <= 2 * a + 1 ; n += 2 {
			//r = utils.PowInt64_Mod(a-1, n, M) + utils.PowInt64_Mod(a+1, n, M)
			r = 2 * n * a
			r %= M
			//fmt.Printf("a=%d, n=%d, r=%d, rmax=%d\n", a, n, r, rmax)
			if r > rmax {
				rmax = r
			}
		}
		fmt.Printf("a=%d, rmax=%d\n", a, rmax)
		S += rmax
	}
	return S
}

func P121() float64 {
	const N = 16
	var D[N+1][N+1] uint64
	var round, j, total, blue uint64

	D[0][0] = 1
	for round = 0 ; round < N; round ++ {
		for j = 0 ; j < N ; j ++ {
			D[round+1][j] += D[round][j]
			D[round+1][j+1] += D[round][j] * round
		}
	}
	for j = 0 ; j <= N ; j ++ {
		fmt.Println(D[j])
		total += D[N][j]
		if j < N / 2 {
			blue += D[N][j]
		}
	}
	fmt.Printf("Total : %d\n",  total)
	fmt.Printf("blue : %d\n",  blue)
	return float64(total) / float64(blue)
}

func P122() int {
	const N = 15
	var D[N+1]int
	var i, j int
	var P[N+1]int
	for i = 1 ; i <= N ; i ++ {
		D[i] = i - 1
		P[i] = i - 1
		for j = 1 ; j * 2 <= i ; j ++ {
			t := utils.MaxInt(D[j], D[i-j]) + 1
			if t < D[ i ] {
				D[ i ] = t
				P[ i ] = j
			}
		}
	}
	var ret int
	for i = 1 ; i <= N ; i ++ {
		ret += D[i]
	}
	return ret
}