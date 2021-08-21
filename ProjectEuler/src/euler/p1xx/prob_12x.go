package p1xx

import "fmt"

func P120() int64 {
	// Let r be the remainder when (a−1)^n + (a+1)^n is divided by a^2.
	//
	// For example, if a = 7 and n = 3, then r = 42: 6^3 + 8^3 = 728 ≡ 42 mod 49.
	// And as n varies, so too will r, but for a = 7 it turns out that rmax = 42.
	//
	// For 3 ≤ a ≤ 1000, find ∑ rmax.

	// (a-1)^(2k) MOD a^2 = 1   for k >= 0
	// (a+1)^(2k) MOD a^2 = 1   for k >= 0

	// (a-1)^(2k+1) MOD a^2 = (2k+1) * a   for k >= 0
	// (a+1)^(2k+1) MOD a^2 = (2k+1) * a   for k >= 0

	// find Max( (2 * n * a) MOD (a^2) )

	var a, n, r, rmax, M, S int64

	rmax = 2
	for a = 3 ; a <= 1000 ; a ++ {
		M = a*a
		for n = 1 ; n <= 2 * a + 1 ; n += 2 {
			//r = utils.PowInt64_Mod(a-1, n, M) + utils.PowInt64_Mod(a+1, n, M)
			r = 2 * n * a
			r %= M
			//fmt.Printf("a=%d, n=%d, r=%d, rmax=%d\n", a, n, r, rmax)
			if r > rmax {
				rmax = r
			}
		}
		fmt.Printf("a=%d, rmax=%d\n", a, rmax)
		S += rmax
	}
	return S
}