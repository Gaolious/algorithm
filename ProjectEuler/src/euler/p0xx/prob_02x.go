package p0xx

import "math/big"

func P20() int {
	b0 := big.NewInt(0)
	ret := big.NewInt(1)
	for i := 100 ; i > 0 ; i -- {
		ret = b0.Mul( big.NewInt( int64(i) ), ret)
	}
	s := ret.Text(10)
	sum := 0
	for _, v := range s {
		sum += int(v - '0')
	}
	return sum
}