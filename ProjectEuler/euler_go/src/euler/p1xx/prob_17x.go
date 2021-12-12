package p1xx

import (
	"euler/utils"
)

func P171() uint64 {
	const MOD = uint64(1_000_000_000)
	const N = uint64(20)
	const MaxSum = 9*9*N

	var digitCount [ N+1 ][ MaxSum + 1 ]uint64
	var digitSum   [ N+1 ][ MaxSum + 1 ]uint64

	var nDigit, sum, n uint64

	digitCount[0][0] = 1

	for nDigit = 0 ; nDigit < N ; nDigit++ {
		for sum = 0 ; sum <= 9 * 9 * nDigit; sum ++ {
			for n = 0 ; n < 10 ; n ++ {

				digitCount[ nDigit+ 1 ][ sum + n*n ] += digitCount[nDigit][ sum ]
				digitCount[ nDigit+ 1 ][ sum + n*n ] %= MOD

				digitSum[ nDigit+ 1 ][ sum + n*n ] += digitSum[nDigit][ sum ]
				digitSum[ nDigit+ 1 ][ sum + n*n ] += (n * utils.PowUInt64_Mod(10, nDigit, MOD) * digitCount[nDigit][ sum ]) % MOD
				digitSum[ nDigit+ 1 ][ sum + n*n ] %= MOD
			}
		}
	}

	var ret uint64
	for n = 1 ; n * n <= MaxSum ; n ++ {
		ret = ( ret + digitSum[N][n*n] ) % MOD
	}
	return ret
}
