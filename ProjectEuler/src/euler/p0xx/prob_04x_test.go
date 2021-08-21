package p0xx

import (
	"fmt"
	"testing"
)
func Test_find_ndigit(t *testing.T) {
	type PARAM struct {
		a int64
		expected int
	}
	var s string
	var params []PARAM
	var i int

	for i = 1 ; i <= 10000 ; i ++ {
		s += fmt.Sprintf("%d", i)
	}

	params = make([]PARAM, len(s))

	for i = 0 ; i < len(s) ; i ++ {
		params[i].a = int64(i + 1)
		params[i].expected = int(s[ i ] - '0')
	}

	for _, p := range params {
		ret := find_ndigit( p.a )

		if ret != p.expected {
			t.Fatalf("find_ndigit( %d, '' ) = %d != %d\n", p.a, ret, p.expected)
		}
	}
}
