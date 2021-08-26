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

func P140() int64 {
	// A_G(x)=x * G_1 + x^2 * G_2 + x^3 * G_3 + ... 에서 Gk는 2차 점화식 Gk=Gk−1+Gk−2, G1=1, G2=4
	// G_k = G_(k-1) + G_(k-2)
	// G_1 = 1, G_2 = 4

	// T = A_G(x) = sum ( x^i * G_i ) for all i>=1
	//            = x + 4 * x^2 + sum ( x^i * G_i ) for all i>=3
	//            = x + 4 * x^2 + x(T-x) + x^2 * T
	//
	// [x]
	// ( T + 3 ) * x^2 + ( T + 1 ) * x - T = 0
	//
	// x = [ -(T+1) +- SQRT( (T+1)^2 + 4T*(T+3) ) ] / ( 2 * T + 6 )
	// x = [ -(T+1) +- SQRT( 5 * T^2 + 14 * T + 1 ) ] / ( 2 * T + 6 )


	// https://www.alpertron.com.ar/QUAD.HTM
	// K^2 = 5*T^2 + 14 * T + 1
	// T_(n+1) = -9 * T_n +- 4 * K_n - 14
	// K_(n+1) = -20 * T_n - 9 * K_n +- 28
	type DATA struct {
		t int64
		k int64
		x float64
	}

	//var T, K int64
	//var X1, X2 float64
	var S int64
	var data [1000]DATA

	var nData int

	var nextT = func(t, k int64) (int64, int64) {
		t1 := -9 * t - 4 * k - 14
		k1 := -20 * t - 9 * k - 28
		return t1, k1
	}
	var nextK = func(t, k int64) (int64, int64) {
		t2 := -9 * t + 4 * k - 14
		k2 := 20 * t - 9 * k + 28
		return t2, k2
	}
	var add = func (t, k int64) bool {
		for i := 0 ; i < nData ; i ++ {
			if data[i].t == t && data[i].k == k {
				return false
			}
		}
		x := float64(-(t+1) + k)
		x /= float64(2*(t+3))
		data[nData] = DATA{t, k, x}
		nData++
		return  true
	}

	add(0, 1)
	add(0, -1)
	add(2, -7)
	add(2, 7)
	add(-3, -2)
	add(-3, 2)
	add(-4, -5)
	add(-4, 5)

	var t1, k1 int64
	var i, j int

	for i = 0 ; i < nData ; i ++ {
		for j = 0 ; j < 30 ; j ++ {
			t1, k1 = nextT(data[i].t, data[i].k)
			if t1 > 0 && add(t1, k1) {
				fmt.Printf("%d^2 = %d = 5*%d^2 + 14*%d + 1 = %d\n", k1, k1*k1, t1, t1, 5*t1*t1 + 14*t1+1 )
			}

			t1, k1 = nextK(data[i].t, data[i].k)
			if t1 > 0 && add(t1, k1) {
				fmt.Printf("%d^2 = %d = 5*%d^2 + 14*%d + 1 = %d\n", k1, k1*k1, t1, t1, 5*t1*t1 + 14*t1+1 )
			}
		}
	}
	return S
}