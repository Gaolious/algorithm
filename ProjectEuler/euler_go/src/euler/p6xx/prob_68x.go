package p6xx

import "fmt"

func P684() int {
	var s func(n int) int
	var S func(n int) int
	var M = 1000000007
	var Cache = make(map[int]int )

	s = func(n int) int {
		if n >= 10 {
			return s(n-9) * 10 + 9
		} else {
			return n
		}
	}

	S = func(n int) int {
		if n == 0 {
			return 0
		}
		if _, ok := Cache[n]; !ok {
			Cache[n] = ( S(n-1) + s(n) ) % M
		}
		return Cache[n]
	}

	var F = make([]int, 91)
	var i, ret int
	for i = 0 ; i <= 20 ; i ++ {
		fmt.Printf("i=%d, s(%d)=%d\n", i, i, s(i))
	}
	F[0] = 0
	F[1] = 1
	for i = 2; i <= 90 ; i ++ {
		F[i] = F[i-2] + F[i-1]
		fmt.Printf("i=%d, F(i) = %d\n", i, F[i])
		// ret = ( ret + S(F[i]) ) % M
	}

	return ret
}
