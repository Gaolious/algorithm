package p1xx

import (
	"euler/utils"
	"fmt"
)

func P131() int {
	// n^3 + n^2 * p = k^3  ( p is prime number and n, k is natural number and n < k )

	// n^3 * ( 1 + p/n ) = k^3

	// k = n * 3root(n+p) / 3root(n)
	// let
	//      n = a ^ 3
	//  n + p = b ^ 3

	// p = b^3 - a^3
	// p = (b-a) * ( b^2 + ba * a^2)
	//      b-a = 1
	//        b = 1+a

	// p = (1+a)^3 - a^3
	//   = (1+a-a) ( (1+a)^2 + (1*a)*a + a^2 )
	//   = (1+a)^2 + (1*a)*a + a^2
	//   = 1 + 2a + a^2 + a+a^2 + a^2
	//   = 1 + 3a + 3a^2

	const MaxN = 1_000_000
	var ret int
	var a uint64
	var Primes = utils.GetPrimes(MaxN)

	a = 1
	for _, _p := range Primes {
		p := uint64(_p)
		for ; 3*a*a + 3*a + 1 < p; a++ { }

		if p == 3*a*a + 3*a + 1 {
			fmt.Printf("prime : %d\n", p)
			ret++
		}
	}
	return ret
}


func P139() int {
	//
	const MaxDist = 100_000_000
	var a, b, c, n, m, ret int

	for n = 1 ; n*n + n <= MaxDist ; n ++ {
		for m = n+1 ; ; m ++ {
			a = m*m - n*n
			b = 2 * m * n
			c = m*m + n*n
			if a + b + c >= MaxDist { break }
			if utils.GcdInt2(a, b) != 1 || utils.GcdInt2(b, c) != 1 { continue }
			if c % ( utils.MaxInt(a, b) - utils.MinInt(a,b) ) != 0 { continue }

			ret += MaxDist / (a+b+c)
		}
	}
	return ret
}