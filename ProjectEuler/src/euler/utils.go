package main

import (
	"math"
)

func get_primes( N int ) []int {
	// N 이하 소수 개수
	var primes []int
	var check []byte
	var i, j int
	//var found bool
	//var length int

	if N <= 1 {
		return primes
	}
	check = make([]byte, N+1)
	primes = make([]int, 0, int(math.Sqrt( float64(N)) ) + 1)

	primes = append(primes, 2)
	if N == 2 {
		return primes
	}

	for i = 3 ; i <= N ; i += 2 {
		if check[ i ] == 1 { continue }

		//found = false
		//length = len(primes)

		//for j = 0 ; j < length && primes[j] <= i ; j ++ {
		//	if i % primes[ j ] == 0 {
		//		found = true
		//		break
		//	}
		//}
		//if found { continue }

		for j = i ; j <= N ; j += i {
			check[ j ] = 1
		}
		primes = append(primes, i)
	}

	return primes
}
