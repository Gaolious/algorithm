package p0xx

import (
	"fmt"
	"math/big"
)

func P80() int {
	const PREC = 1000
	var i int
	var j int
	var found bool
	var ret int

	var s *big.Float

	s = new(big.Float).SetPrec(PREC).SetInt64(0)

	for i = 1 ; i <= 100 ; i ++ {
		found = false
		for j = 1 ; j * j <= i ; j ++ {
			if j*j == i {
				found = true
			}
		}
		if found { continue }

		sqrt_val := s.SetPrec(PREC).Sqrt( big.NewFloat( float64(i)) )
		sqrt_str := fmt.Sprintf("%.105f\n", sqrt_val)

		for j = 0 ; j <= 100 ; j ++ {
			if sqrt_str[j] != '.' {
				ret += int(sqrt_str[j] - '0')
			}
		}
	}
	return ret
}
