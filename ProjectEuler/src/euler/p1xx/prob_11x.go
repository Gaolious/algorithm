package p1xx

import (
	"euler/utils"
	"fmt"
	"math/big"
)

func P110() string {
	// In the following equation x, y, and n are positive integers.
	// 1/x + 1/y = 1/n
	// For n = 4 there are exactly three distinct solutions:
	// What is the least value of  for which the number of distinct solutions exceeds four million?

	// 1/x + 1/y = 1/n
	// yn + xn = xy
	// xn = y(x-n)
	// n^2 = y(x-n) - xn + n^2
	// n^2 = y(x-n) - n(x-n)
	// n^2 = (x-n)(y-n)

	// divisors of [n^2] = (x-n) and (y-n)
	// and distinct .

	const CUT = 4000000
	const MAX_N = 100
	var primes = utils.GetPrimes(MAX_N)
	var nPrimes = len(primes)

	var F func (prime_idx int, count , N *big.Int)
	var bestN = big.NewInt(-1)
	var b1 = big.NewInt(1)
	var b0 = big.NewInt(0)
	var b4000000 = big.NewInt(4000000)

	F = func (prime_idx int, count *big.Int, N *big.Int) {

		var i int64
		if prime_idx >= nPrimes { return }
		if bestN.Cmp(b0) > 0 && N.Cmp(bestN) > 0 { return }

		check_cnt := big.NewInt(0).Sub(count, big.NewInt(1))
		check_cnt = big.NewInt(0).Div(check_cnt, big.NewInt(2))
		if check_cnt.Cmp(b4000000) > 0 {
			if bestN.Cmp(b0) < 0 || bestN.Cmp(N) > 0 {
				fmt.Printf("updated best N = %d / cnt = %d\n", N, count)

				bestN.Set(N)
			}
			return
		}

		var next_n = big.NewInt(0).Set(N)
		var next_c = big.NewInt(0).Set(count)
		var prime = big.NewInt( int64(primes[prime_idx]) )

		for i = 1 ; i <= 10 ; i ++ {
			next_n = big.NewInt(0).Mul( next_n, prime)
			next_c = big.NewInt(0).Mul( count, big.NewInt( 2*i+1))
			F( prime_idx + 1 ,next_c, next_n)

		}
	}
	F(0, b1, b1)

	return bestN.String()
}