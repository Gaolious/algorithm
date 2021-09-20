package p2xx

import (
	"euler/utils"
)

func P231() int {
	var Primes = utils.GetPrimes(20000000)
	var cache[20000000+1] int

	var S func(n int) int
	S = func(n int) int {
		if cache[n] == 0 {
			var i int
			for i = 0 ; i < len(Primes) && n >= Primes[i] ; i ++ {
				if n % Primes[i] == 0 {
					cache[n] = Primes[i] + S(n / Primes[ i ])
					return cache[ n ]
				}
			}
			cache[n] = n
		}
		return cache[n]
	}

	var j, s int
	var ret int
	var N, M int

	N = 20_000_000
	M = 15_000_000

	for j = 0 ; j < len(Primes) ; j ++ {
		s = 0
		for i := Primes[j] ; i <= N ; i *= Primes[j] {
			s += Primes[j]
			cache[i] = s
		}
	}
	for j = N - M + 1 ; j <= N ; j ++ {
		ret += S(j)
	}
	for j = 2 ; j <= M ; j ++ {
		ret -= S(j)
	}

	return ret
}
