package p1xx

import "fmt"

func P151() string {
	var P func(int, int, int, int, int) float64

	P = func (a1 int, a2 int, a3 int, a4 int, a5 int) float64{
		s := a1 + a2 + a3 + a4 + a5
		var ret float64
		if s == 1 {
			ret = float64(1)
		}
		if a1 > 0 {
			ret += P(a1-1, a2+1, a3+1, a4+1, a5+1) * float64(a1) / float64(s)
		}
		if a2 > 0 {
			ret += P(a1, a2-1, a3+1, a4+1, a5+1) * float64(a2) / float64(s)
		}
		if a3 > 0 {
			ret += P(a1, a2, a3-1, a4+1, a5+1) * float64(a3) / float64(s)
		}
		if a4 > 0 {
			ret += P(a1, a2, a3, a4-1, a5+1) * float64(a4) / float64(s)
		}
		if a5 > 0 {
			ret += P(a1, a2, a3, a4, a5-1) * float64(a5) / float64(s)
		}
		return ret
	}

	return fmt.Sprintf("%.6g", P(1, 0, 0, 0, 0) - 2.0)
}
