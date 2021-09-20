package p1xx

import (
	"euler/utils"
	"fmt"
	"math"
)

func P141() uint64 {
	// N = D * Q + R
	//    R < max(D, Q)

	// a, ar, ar^2 = geometric sequence

	// if R = a,
	//      D, Q = a*r, a*r^2 or a*r^2, a*r
	// if R = a*r,
	//      D, Q = a, a*r^2 or a*r^2, a

	// r = p / q

	// a, a * (p/q) , a*(p^2 / q^2)
	// a = t * (q^2)
	// => t * (q^2), t * (q^2) * (p/q) , t * (q^2)*(p^2/q^2)
	// => t * (q^2), t * q * p , t * p^2

	// if R = t * (q^2)
	//      N = [t * q * p] * [t * p^2] + [t * q^2]
	//      if t=1, p=1 => Limit : q + q*q
	//      if t=1,     => Limit : q*p*p*p + q*q
	// if R = t * q * p
	//      N = [t * q^2] * [t * p^2] + [t * q * p]
	//      if t=1, p=1, => Limit : q*q + q
	//      if t=1,      => Limit : q*q*p*p + q*p

	const MaxN = uint64(1_000_000_000_000)
	// const MaxN = uint64(100_000)
	var  t, q, p, N1, N2, ret uint64
	var sol = make(map[uint64]bool)
	var isSquare = func(n uint64) bool {
		a := uint64(math.Sqrt(float64(n)))
		return a * a == n
	}

	for q = 1 ; q + q * q <= MaxN ; q ++ {
		for p = 1 ; q*q*p*p + q*p <= MaxN ; p ++ {
			if utils.GcdUInt64(p, q) != 1 { continue }
			for t = 1 ; ; t ++ {
				N1 = (t*q*p) * (t*p*p) + t*q*q
				// t^2*q*p^3 + t*q^2
				N2 = (t*q*q) * (t*p*p) + t*q*p
				// t^2 *q^2 * p^2
				if N1 > MaxN && N2 > MaxN { break }
				if (t*q*p) < t*q*q && (t*p*p) < t*q*q { break }
				if (t*q*q) < t*q*p && t*p*p < t*q*p { break }

				if N1 <= MaxN && isSquare(N1){
					if _, ok:=sol[N1]; !ok {
						ret += N1
						sol[N1] = true
						fmt.Printf("N = %d == %d * %d + %d\n", N1, (t*q*p), (t*p*p), t*q*q)
					}
				}
				if N2 <= MaxN && isSquare(N2){
					if _, ok:=sol[N2]; !ok {
						ret += N2
						sol[N2] = true
						fmt.Printf("N = %d == %d * %d + %d\n", N1, (t*q*q), (t*p*p), t*q*p )
					}
				}
			}
		}
	}
	return ret
}
