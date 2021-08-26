package p0xx

import (
	"euler/utils"
	"fmt"
	"math/big"
)

func P80() int {
	const PREC = 1000
	var i int
	var j int
	var found bool
	var ret int

	var s *big.Float

	s = new(big.Float).SetPrec(PREC).SetInt64(0)

	for i = 1 ; i <= 100 ; i ++ {
		found = false
		for j = 1 ; j * j <= i ; j ++ {
			if j*j == i {
				found = true
			}
		}
		if found { continue }

		sqrt_val := s.SetPrec(PREC).Sqrt( big.NewFloat( float64(i)) )
		sqrt_str := fmt.Sprintf("%.105f\n", sqrt_val)

		for j = 0 ; j <= 100 ; j ++ {
			if sqrt_str[j] != '.' {
				ret += int(sqrt_str[j] - '0')
			}
		}
	}
	return ret
}

func P87() int {
	const CUT = 50000000
	var check[CUT + 1]byte
	var primes = utils.GetPrimes(30000)
	var i, j, k int
	var nPrime = len(primes)
	var cnt = 0
	var p2, p3, p4 [] uint64

	p2 = make([]uint64, nPrime)
	p3 = make([]uint64, nPrime)
	p4 = make([]uint64, nPrime)
	for i = 0 ; i < nPrime ; i ++ {
		t := uint64(primes[i])
		p2[i] = t * t
		p3[i] = p2[i] * t
		p4[i] = p3[i] * t
	}

	for i = 0 ; i < nPrime ; i ++ {
		for j = 0 ; j < nPrime ; j ++ {
			for k = 0 ; k < nPrime && p2[i] + p3[j] + p4[k] < CUT ; k ++ {
				if check[p2[i] + p3[j] + p4[k]] != 1 {
					//fmt.Printf("%d = %d^2 + %d^3 + %d^4\n", p2[i] + p3[j] + p4[k], primes[i], primes[j], primes[k])
					check[p2[i] + p3[j] + p4[k]] = 1
					cnt ++
				}
			}
		}
	}

	return (cnt)
}