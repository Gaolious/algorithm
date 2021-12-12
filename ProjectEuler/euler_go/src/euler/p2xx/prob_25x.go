package p2xx

import "fmt"

func P251() int64 {
	// a+b+c ≤ 110,000,000
	// (2a-1)^3 = -27(a^2 - b^2*c)
	// (2a-1)^3 + 27 * a^2 = 27 * b^2 * c

	// 3k+2 = a
	// 2a-1 = 6k+4-1 = 6k+3
	// (6k+3)^3 + 27 * a^2 = 27 * b^2 * c
	// 27*(2k+1)^3 + 27 * a^2 = 27 * b^2 * c
	// (2k+1)^3 + a^2 = b^2 * c

	const MaxN = int64(110_000_000)
	var k, b, cnt , a int64
	for k = 0 ; k <= MaxN / 3 ; k ++ {
		a = 3 * k + 2
		a21 := 2 * k + 1
		k2a2 := a21 * a21 * a21 + a * a

		for b = 1 ; b * b <= k2a2 ; b++ {
			c := ( k2a2 ) / b / b
			if a + b + c > MaxN { continue }
			if k2a2 != b * b * c { continue }
			fmt.Printf("a=%d, b=%d, c=%d\n", a, b, c)
			cnt++
		}
	}

	return cnt
}
