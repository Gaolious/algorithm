package utils

import (
	"math/big"
	"testing"
)

func TestContinuedFraction(t *testing.T) {
	//   b * root(c) + d
	//  -----------------
	//        e

	params := []struct {
		b, c, d, e int64 // in
		A, B, C, D, E int64 // out
	} {
		{
			b:1, c:23, d:0, e:1, // sqrt(23)
			A:4, B:1, C:23, D:4, E:7, // [ sqrt(23) + 4 ] / 7
		},
	}

	for _, param := range params {
		f := Fraction{
			b:big.NewInt(param.b),
			c:big.NewInt(param.c),
			d:big.NewInt(param.d),
			e:big.NewInt(param.e),
		}
		a, next := f.ContinuedFraction()

		ret := true
		ret = ret && (big.NewInt(param.A).Cmp(a) == 0)
		ret = ret && (big.NewInt(param.B).Cmp(next.b) == 0)
		ret = ret && (big.NewInt(param.C).Cmp(next.c) == 0)
		ret = ret && (big.NewInt(param.D).Cmp(next.d) == 0)
		ret = ret && (big.NewInt(param.E).Cmp(next.e) == 0)

		if ! ret {
			t.Fatalf(
				"ContinuedFraction( [ %s * sqrt(%s) + %s ] / %s ) = %s + [ %s * sqrt(%s) + %s ] / %s, expected : %d + [ %d * sqrt(%d) + %d ] / %d",
				f.b.String(), f.c.String(), f.d.String(), f.e.String(),
				a.String(), next.b.String(), next.c.String(), next.d.String(), next.e.String(),
				param.A, param.B, param.C, param.D, param.E,
			)
		}
	}

}