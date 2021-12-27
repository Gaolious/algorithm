package p1xx

import (
	"bufio"
	"euler/utils"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func P100() int64 {
	// B + R >= 10^12
	// ( B / (B+R) ) * ( (B-1) / (B+R-1) ) = 1/2
	// S = R+B
	// 2*B^2 - 2B = S^2 - S
	// ( 2B - 1 )^2 = S^2 + (S-1)^2
	// x = S / y = S-1 / z = 2B-1
	// x^2 + y^2 = z^2
	// z : m^2 + n^2
	// y : 2mn  / or y : m^2 - n^2
	// x : m^2 - n^2  / or x : 2mn
	var N int64
	var m, n int64
	var x, y, z int64
	var l, r int64
	var minS, minB int64
	N = 1000000000000

	minS = -1
	for m = 1000000 ; m <= 5000000 ; m ++ {
		l = utils.MaxInt64(N/2/m, N - m*m)
		r = m - 1
		for l <= r {
			n = (l+r) / 2
			z = m*m + n*n
			y = 2*m*n
			x = m*m - n*n

			if (x+1 == y || y+1 == x) && x*x + y*y == z*z {
				fmt.Printf("Found. x=%d, y=%d, z=%d\n", x, y, z)
				B := (z+1)/2
				S := utils.MaxInt64(x, y)
				fmt.Printf("Found. B=%d, R=%d, S=%d\n", B, S-B, S)

				if minS < 0 || minS > S {
					minS = S
					minB = B
				}
				break
			}

			y1 := 2*m*(n-1)
			y2 := 2*m*(n+1)

			x1 := m*m - (n-1)*(n-1)
			x2 := m*m - (n+1)*(n-1)
			d1 := utils.AbsInt64(y1-x1)
			d2 := utils.AbsInt64(y2-x2)
			if d1 < d2 {
				r = n - 1
			} else {
				l = n + 1
			}
		}
	}
	return minB
}

func P101() int64 {
	//  1 − n + n2 − n3 + n4 − n5 + n6 − n7 + n8 − n9 + n10
	//  1 − n(1-n) − n3(1-n) − n5(1-n) − n7(1-n) − n9(1 - n)
	//  1 - n * ( 1 - n ) ( 1 + n^2 + n^4 + n^6 + n^8 )
	//  1 - n * ( 1 - n ) ( 1 + n^2 * ( 1 + n^2) + n^6 * ( 1 + n^2 ) )
	//  1 - n * ( 1 - n ) ( 1 + n^2 * ( 1 + n^4 ) * ( 1 + n^2 ) )
	// a + b = 1
	// 2a + b = 683
	// a = 682
	// b = -681
	var F = func(n int64) int64 {
		var n2 = n * n
		var n4 = n2 * n2

		return 1 - n * ( 1 - n ) * ( 1 + n2 * ( 1 + n4 ) * ( 1 + n2 ) )
	}
	var i int64
	var r int64
	for i = 2 ; i <= 10 ; i ++ {
		fmt.Printf("%d=%d\n", i, F(i))
		r += F(i)
	}

	return r
}

func P102() int {
	var i int
	var count int
	fp, _ := os.Open("/Users/ajava/github/algorithm/algorithm/ProjectEuler/euler_go/src/euler/p1xx/p102.in")
	defer fp.Close()

	fin := bufio.NewReader(fp)

	for {
		buffer, _, err := fin.ReadLine()
		if err != nil {
			break
		}
		tmp := strings.Split(string(buffer),",")
		pos := make([]utils.Vector2d, 3)
		for i = 0 ; i < 3 ; i ++ {
			x, _ := strconv.Atoi(tmp[i*2])
			y, _ := strconv.Atoi(tmp[i*2+1])
			pos[i] = utils.Vector2d{ X:float64(x), Y:float64(y) }
		}
		var cnt[3] int
		for i = 0 ; i < 3 ; i ++ {
			ret := pos[ i % 3 ].Cross(&pos[(i+1)%3])
			if math.Abs(ret) < utils.EPSILON {
				cnt[1] ++
			} else if ret < 0 {
				cnt [0] ++
			} else if ret > 0 {
				cnt[2]++
			}
		}
		if cnt[0] == 3 || cnt[2] == 3 {
			count++
		}
	}
	return count
}

func P108() int {
	// In the following equation x, y, and n are positive integers.
	// 1/x + 1/y = 1/n
	// For n = 4 there are exactly three distinct solutions:
	// What is the least value of n for which the number of distinct solutions exceeds one-thousand?

	// 1/x + 1/y = 1/n
	// yn + xn = xy
	// xn = y(x-n)
	// n^2 = y(x-n) - xn + n^2
	// n^2 = y(x-n) - n(x-n)
	// n^2 = (x-n)(y-n)

	// divisors of [n^2] = (x-n) and (y-n)
	// and distinct .

	const MAX_N = 200000
	var primes = utils.GetPrimes(MAX_N)
	//var l, r, m int
	var ret = 0

	for n :=1 ; n <=MAX_N ; n++ {
		cnt := utils.GetDivisorCountSquare(primes, n) + 1
		cnt /= 2
		if cnt > 1000 {
			fmt.Printf("n=%d, ret=%d\n", n, cnt)
			return n
		}
	}

	return ret
}


func P108_2() uint64 {
	// In the following equation x, y, and n are positive integers.
	// 1/x + 1/y = 1/n
	// For n = 4 there are exactly three distinct solutions:
	// What is the least value of n for which the number of distinct solutions exceeds one-thousand?

	// 1/x + 1/y = 1/n
	// yn + xn = xy
	// xn = y(x-n)
	// n^2 = y(x-n) - xn + n^2
	// n^2 = y(x-n) - n(x-n)
	// n^2 = (x-n)(y-n)

	// divisors of [n^2] = (x-n) and (y-n)
	// and distinct .

	const CUT = 1000
	const MAX_N = 100
	var primes = utils.GetPrimes(MAX_N)
	var nPrimes = len(primes)
	var F func (prime_idx int, count uint64, N uint64)
	var bestN uint64

	F = func (prime_idx int, count uint64, N uint64) {

		var i uint64
		var next_n uint64

		if prime_idx >= nPrimes { return }
		if bestN > 0 && N > bestN { return }

		if ( count + 1 ) / 2 > CUT {
			if bestN == 0 || bestN > N {
				fmt.Printf("updated best N = %d / cnt = %d\n", N, count)
				bestN = N
			}
			return
		}

		next_n = 1
		for i = 1 ; i <=5 ; i ++ {
			next_n *= uint64(primes[prime_idx])
			F( prime_idx + 1 , count * ( 2 * i + 1 ), N * next_n )
		}
	}

	F(0, 1, 1)

	return bestN
}