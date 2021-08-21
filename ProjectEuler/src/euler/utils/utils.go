package utils

import (
	"math"
)

func GetPrimes( N int ) []int {
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

func MaxInt( a, b int ) int {
	if a > b { return a }
	return b
}

func MinInt( a, b int ) int {
	return -MaxInt(-a,-b)
}

func GcdInt(a, b int ) int {
	if b == 0 {
		return a
	} else {
		return GcdInt(b, a%b)
	}
}

func GetDigit(n int64) int64 {
	// 몇자리 수 인가 ?
	if n < 0 {
		n = -n
	}
	if n < 10 {
		return 1
	} else {
		return GetDigit(n/10) + 1
	}
}