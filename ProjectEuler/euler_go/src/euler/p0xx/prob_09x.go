package p0xx

import (
	"euler/utils"
	"math"
)

func P92() int {
	check := make([]byte, 10000000+1)
	check[1] = 2
	check[89] = 1

	var F  func(n int) byte

	// 16 = 37
	// 49 + 9 = 58
	// 25 + 64 = 89

	F = func(n int) byte {
		switch check[n] {
		case 0:
			s := 0
			for t := n ; t > 0 ; t /= 10 {
				s += (t%10) * (t%10)
			}
			check[n] = 2
			check[n] = F(s)
		case 1:
			return 1
		case 2:
			return 2
		}
		return check[n]
	}

	var ret int
	for i := 1 ; i < 10000000 ; i ++ {
		if F(i) == 1 {
			ret ++
		}
	}
	return ret
}

func P97() uint64 {
	// 28433×2^7830457+1

	var M = uint64(utils.PowInt64(10, 10))
	ret := 28433 * utils.PowUInt64_Mod(2, 7830457, M ) + 1
	// for i := uint64(0) ; i < 1000 ; i ++ {
	// 	fmt.Printf("2^%d = %d\n", i, utils.PowUInt64_Mod(2, i, M))
	// }
	return ret % M
}

func P91() int {

	const M = 50
	const M2 = (M+1)*(M+1)
	const epsilon = 0.000001
	var dist = func( dx, dy int ) float64 {
		return math.Sqrt(float64(dx*dx) + float64(dy*dy))
	}

	var isTriangle = func(d1, d2, d3 float64) bool {
		if d1 + d2 <= d3 { return false }
		if d1 + d3 <= d2 { return false }
		if d3 + d2 <= d1 { return false }
		return true
	}
	var rightTriangle = func(d1, d2, d3 float64) bool {
		l1, l2, l3 := d1*d1, d2*d2, d3*d3

		if math.Abs(l1+l2-l3) < epsilon  { return true }
		if math.Abs(l1-l2+l3) < epsilon  { return true }
		if math.Abs(-l1+l2+l3) < epsilon  { return true }
		return false
	}

	var ret int
	for i := 0 ; i < M2 ; i ++ {
		y1, x1 := i / (M+1), i % (M+1)

		d1 := dist(x1, y1)
		for j := i+1 ; j < M2 ; j ++ {
			y2, x2 := j / (M+1), j % (M+1)

			d2 := dist(x2, y2)
			d3 := dist(x1-x2, y1-y2)

			if ! isTriangle(d1, d2, d3) { continue }

			if ! rightTriangle(d1, d2, d3) { continue }

			ret ++
		}
	}

	return ret

}