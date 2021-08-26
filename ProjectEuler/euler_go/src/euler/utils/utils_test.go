package utils

import "testing"

func TestGetPrimes(t *testing.T) {
	params := []struct {
		a, b     int
		expected int
	} {
		{ 1, 2, 1},
		{ 2, 1, 1},
		{ 2, 2, 2},
		{ 2, 4, 2},
		{ 4, 2, 2},
		{ 2, 3, 1},
		{ 3, 2, 1},
	}

	for _, p := range params {
		ret := GcdInt( p.a, p.b )

		if ret != p.expected {
			t.Fatalf("GcdInt( %d, %d )=%d != %d\n", p.a, p.b, ret, p.expected)
		}
	}

	//} {
	//	{2, }, {3, },
	//}
	//t.Fatalf("Error ret=%d", ret)
}
