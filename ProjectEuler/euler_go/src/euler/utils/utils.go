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

		for j = i ; j <= N ; j += i {
			check[ j ] = 1
		}
		primes = append(primes, i)
	}

	return primes
}

func MaxInt( a, b int ) int {
	return int(MaxInt64( int64(a), int64(b) ))
}

func MaxInt64( a, b int64 ) int64 {
	if a > b { return a }
	return b
}
func AbsInt64(a int64) int64 {
	if a < 0 { return -a}
	return a
}
func MaxUint64( a, b uint64 ) uint64 {
	if a > b { return a }
	return b
}

func MinInt( a, b int ) int {
	if a < b { return a }
	return b
}

func MinInt64( a, b int ) int {
	if a < b { return a }
	return b
}

func MinUint64( a, b uint64 ) uint64 {
	if a < b { return a }
	return b
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

func PowInt64(n, p int64 ) int64{
	// n^p
	switch p {
	case 0: return 1
	case 1: return n
	default:
		if p % 2 == 0 {
			ret := PowInt64(n, p/2)
			return ret*ret
		} else {
			ret := PowInt64(n, p-1)
			return ret * n
		}
	}
}

func PowInt64_Mod(n, p, m int64 ) int64{
	// n^p
	switch p {
	case 0: return 1 % m
	case 1: return n % m
	default:
		if p % 2 == 0 {
			ret := PowInt64_Mod(n, p/2, m)
			return (ret * ret) % m
		} else {
			ret := PowInt64_Mod(n, p-1, m)
			return (ret * n) % m
		}
	}
}

func GetDivisorCount(primes []int, n int) int {
	var ret, r, i int
	var length = len(primes)
	ret = 1

	for i = 0 ; i < length && primes[i] * primes[i] <= n ; i ++ {
		if n % primes[i] != 0 { continue }
		r = 1
		for n >= primes[i] && n % primes[i] == 0 {
			r += 1
			n /= primes[i]
		}
		ret = ret * r
	}

	return ret
}


func GetDivisorCountSquare(primes []int, n int) int {
	var ret, r, i int
	var length = len(primes)
	ret = 1

	for i = 0 ; i < length && primes[i] <= n ; i ++ {
		if n % primes[i] != 0 { continue }
		r = 1
		for n >= primes[i] && n % primes[i] == 0 {
			r += 2
			n /= primes[i]
		}
		ret = ret * r
	}

	return ret
}
