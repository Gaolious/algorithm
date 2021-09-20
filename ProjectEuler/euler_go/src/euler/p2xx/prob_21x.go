package p2xx

import (
	"euler/utils"
	"fmt"
	"math"
)

func P211() uint64 {
	// σ2(10) = 1 + 4 + 25 + 100 = 130.
	//        = 1 + 2^2 + 5^2 + 2^2 * 5^2 = 130
	//        = (1+2^2) * ( 1 + 5^2) = 5 * 26
	//        = (p^0 + p^2 + p^4 + p^8 + ... -1) * (q^0 + q^2 + ... -)

	// σ2(12) = 1^2 + 2^2 + 3^2 + 4^2 + 2^2*3^2 + (2^2*3)^2 = 1+4+9+16+36+144 = 210
	//        = 1^2 + 2^2 + 3^2 + 4^2 + 6^2 + 12^2 = 210
	//        = 1^2 + 2^2 + 3^2 + 2^4 + 2^2*3^2 + 2^4*3^2
	//        = ( 1 + 2^2 + 2^4) * ( 1 + 3^2  )
	//        = 21 * 10
	// σ2(20) = 1^2 + 2^2 + 4^2 + 5^2 + 10^2 + 20^2 = 546
	//        = ( 2^0 + 2^2 + 2^4 ) * ( 5^0 + 5^2 ) = 21 * 26
	const MaxN = uint64(64_000_000)

	var Primes = utils.GetUint64Primes(100000)
	var cache[100000000+1]uint64
	var SumDivisorFactor func(n uint64) uint64

	fmt.Printf("Primes : %d\n", len(Primes))

	SumDivisorFactor = func(n uint64) uint64 {
		var s, t, ret, p, tmpN uint64
		var i int
		if n <= uint64(len(cache)) && cache[n] > 0 {
			return cache[n]
		}
		ret = 1
		for i = 0 ; i < len(Primes) && Primes[i] * Primes[i] < n && n % Primes[i] != 0 ; i ++ { }

		if i < len(Primes) && n % Primes[i] == 0 {
			tmpN, s = n, 1
			p = Primes[i]
			for t = p ; tmpN % p == 0 ; t *= p {
				tmpN /= p
				s += t*t
			}
			ret *= s * SumDivisorFactor(tmpN)
		} else if n > 1 {
			ret += n*n
		}

		if n <= uint64(len(cache)) && cache[n] == 0 {
			cache[n] = ret
		}
		return ret
	}

	var IsSquareNumber = func(n uint64) bool {
		t := uint64(math.Sqrt( float64(n) ) + 0.000001)
		return t * t == n
	}
	var n uint64
	var s, ret uint64

	for n = MaxN ; n > 0; n -- {
		if n % 1000000 == 0 {
			fmt.Printf("n=%d, ret=%d\n", n, ret )
		}

		s = SumDivisorFactor(n)
		if ! IsSquareNumber(s) {
			continue
		}
		ret += n

	}
	return ret
}