package p1xx

import (
	"euler/utils"
	"fmt"
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