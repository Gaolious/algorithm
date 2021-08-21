package p0xx

import "fmt"

func find_ndigit(n int64) int {
	const MAX_DIGIT = 10

	var POW10 [MAX_DIGIT + 1 ] int64

	var ten, digits int64
	var i int64
	var number string

	if n < 10 {
		return int(n)
	}
	ten = 1
	for digits = 0 ; digits <= MAX_DIGIT ; digits ++ {
		POW10[digits] = ten
		ten = ten * 10
	}

	for digits = 1 ; digits <= MAX_DIGIT ; digits ++ {
		cnt := POW10[digits-1] * digits * 9
		if n <= cnt {
			break
		} else {
			n -= cnt
		}
	}

	var t int64
	for i = digits ; i > 0 ; i -- {
		if n <= digits-i {
			t = 0
		} else {
			t = ( n - 1 ) / (digits * POW10[i - 1])
			n -= t * ( digits * POW10[i - 1])
		}
 		if i == digits { t ++ }
		number += fmt.Sprintf("%d", t)
	}

	return int( number[ n-1 ] - '0' )
}
func P40() int {
	var s, i int
	s = 1
	for i = 1 ; i <= 1000000 ; i *= 10 {
		s = s * find_ndigit( int64(i) )
	}
	return s
}