package p0xx

import (
	"euler/utils"
	"fmt"
	"strconv"
)

func P30() int {
	var P [10]int
	var i int
	var S = func(n int) int {
		var ret int
		for n > 0 {
			ret += P[ n%10 ]
			n/=10
		}
		return ret
	}
	var ret int

	for i = 0 ; i < 10 ; i ++ {
		P[ i ] = i*i*i*i*i
	}

	for i = 10 ; i <= 1000000 ; i ++ {
		if i == S(i) {
			fmt.Printf("i : %d\n", i)
			ret += i
		}
	}
	return ret
}

func P31() int {
	var C = []int{ 1, 2, 5, 10, 20, 50, 100, 200}
	var D [201]int
	var i, j int

	D[0] = 1
	for i = 0 ; i < len(C) ; i ++ {
		for j = C[i] ; j<=200 ; j++ {
			D[ j ] += D[ j - C[i] ]
		}
	}
	return D[200]
}

func P32() int {
	var a, b, c int
	var s int

	var check = func(n1, n2, n3 int ) bool {
		var t [10]int
		var d = []int{ n1, n2, n3 }

		for _, n := range d {
			for n > 0 {
				if n % 10 == 0 { return false }
				if t[ n%10 ] == 1 { return false }
				t[ n % 10 ] ++
				n /= 10
			}
		}
		for i := 1 ; i <= 9 ; i ++ {
			if t[i] != 1 { return false }
		}
		return true
	}

	for c = 1 ; c <= 100000 ; c ++ {
		for a = 1 ; a*a <= c ; a ++ {
			if c % a != 0 { continue }

			b = c / a
			if ! check(a, b, c) { continue }
			s += c
			fmt.Printf("%d * %d = %d (s=%d)\n", a, b, c, s)
			break
		}
	}
	return s
}

func P33() int {
	var a, b, k int
	var c, d int
	var ret1, ret2 int
	ret1 = 1
	ret2 = 1

	for k = 1 ; k <= 9 ; k ++ {

		for a = 1; a < 10; a++ {
			for b = 1; b < 10; b++ {
				// a / b  4 / 8
				c = a * 10 + k
				d = k * 10 + b
				if c >= d {
					continue
				}
				if c * b == d * a {
					fmt.Printf("%d/%d (%d/%d)\n", c, d, a, b)
					ret1 *= a
					ret2 *= b
					m := utils.GcdInt2(ret1, ret2)
					ret1 /= m
					ret2 /= m
				}
			}
		}
	}

	return ret2
}

func P34() int {
	var F[10]int
	var i, n, s, ret int
	F[0] = 1
	for i = 1 ; i <= 9 ; i ++ {
		F[i] = F[i-1] * i
	}

	for i = 10 ; i <= 10000000 ; i ++ {
		s = 0
		for n = i ; n > 0 ; n /= 10 {
			s += F[n%10]
		}
		if s == i {
			fmt.Printf("%d\n", i)
			ret += i
		}
	}
	return ret
}

func P35() int {
	var primes = utils.GetPrimes(1_000_000)
	var exist = func (n int) bool {
		l := 0
		r := len(primes) - 1
		for l <= r {
			m := (l+r) / 2
			if primes[m] == n { return true }
			if primes[m] < n {
				l = m+1
			} else {
				r = m-1
			}
		}
		return false
	}
	var d = 1
	var flag bool
	var ret int

	for _, n := range primes {
		ndigit := int(utils.GetDigit(int64(n)))

		for n > d * 10 { d *= 10 }

		flag = true
		t := n
		for i := 0; i < ndigit ; i ++ {
			t = t/10 + (t%10)*d
			if !exist(t) {
				flag = false
				break
			}
		}
		if flag {
			fmt.Printf("%d\n", n)
			ret ++
		}
	}
	return ret
}

func P36() int64 {
	var n int64
	var cnt int64

	var is = func( s *string) bool {
		var i, length int
		length = len(*s)
		// 1 2 1
		// 0 1
		for i = 0 ; (i+1) * 2 <= length ; i ++ {
			if (*s)[i] != (*s)[ length - 1 - i ] {
				return false
			}
		}
		return true
	}
	for n  = 1 ; n < 1_000_000 ; n ++ {
		s := strconv.FormatInt(n, 10)
		if !is(&s) { continue }

		s = strconv.FormatInt(n, 2)
		if !is(&s) { continue }

		cnt += n
		fmt.Printf("%d : %s\n", n, s)
	}
	return cnt
}

func P37() int {
	var primes = utils.GetPrimes(1000000)
	var is = func(n int ) bool {
		l := 0
		r := len(primes)
		for l <= r {
			m := (l+r)/2
			if primes[m] == n {
				return true
			} else if primes[m] < n {
				l = m + 1
			} else {
				r = m - 1
			}
		}
		return false
	}
	var F = func(n int ) bool {
		var t int
		var n1, n2 int

		for t = 10 ; t <= n ; t *= 10 {
			n1 = n / t
			n2 = n - n1 * t
			if !is(n1) || !is(n2) {
				return false
			}
		}
		return true
	}
	var ret int
	for _, p := range primes {
		if p < 10 { continue }
		if F(p) {
			fmt.Printf("Prime : %d\n", p)
			ret += p
		}
	}
	return ret
}

func P38() int64 {
	var i, n int64
	var is = func(n1 int64 ) bool {
		var t [10]int
		var n, a int64
		var cnt int64

		for a = 1 ; cnt < 9 ; a ++ {
			n = n1 * a
			cnt += utils.GetDigit(n)
			if cnt > 9 { return false }
			for n > 0 {
				if n % 10 == 0 { return false }
				if t[ n%10 ] == 1 { return false }
				t[ n % 10 ] ++
				n /= 10
			}
			if cnt == 9 {
				break
			}
		}
		for i := 1 ; i <= 9 ; i ++ {
			if t[i] != 1 { return false }
		}
		return true
	}
	var max_n int64

	for n = 999999 ; n> 0 ; n -- {
		if is(n) {
			var N, cnt int64
			for i = 1 ; cnt < 9 ; i ++ {
				t := utils.GetDigit(n*i)
				N = N * utils.PowInt64(10, t) + n*i
				cnt += t
				fmt.Printf("%d x %d = %d\n", n, i, n*i)
				if N > max_n {
					max_n = N
				}
			}
		}
	}
	return max_n
}

func P39() int {
	// a^2 + b^2 = c^2
	// a + b + c = p

	// c = m^2 + n^2
	var m, n int
	var a, b, c, k int
	var count [1000+1] int
	for m = 1 ; m * m < 1000 ; m ++ {
		for n = 1 ; n * m + m * m < 1000 ; n ++ {
			a = m*m - n*n
			b = 2*m*n
			c = m*m + n*n
			if utils.GcdInt2(a, b) != 1 { continue }
			if utils.GcdInt2(b, c) != 1 { continue }
			if utils.GcdInt2(a, c) != 1 { continue }
			if a + b + c > 1000 { continue }

			for k = 1 ; k * (a+b+c) <= 1000 ; k ++ {
				count[k * (a+b+c)]++
			}
		}
	}
	var max_idx int
	for k = 0 ; k <= 1000 ; k ++ {
		if count[max_idx] < count[ k ] {
			max_idx = k
		}
	}
	return max_idx
}