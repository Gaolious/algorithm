package utils

import (
	"bytes"
	"testing"
)

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
		ret := GcdInt2( p.a, p.b )

		if ret != p.expected {
			t.Fatalf("GcdInt2( %d, %d )=%d != %d\n", p.a, p.b, ret, p.expected)
		}
	}
}

func Test64Digit(t *testing.T) {

	for i := 72 ; i <= 10000 ; i ++ {
		s := ConvertNto64Str(i)
		v := Convert64StrToN([]byte(s))
		if i != v {
			t.Fatalf("ConvertNto64Str(%d) = %s; Convert64StrToN(%s) = %d\n",i, s, s, v)
		}
	}
}

func TestNtoByte(t *testing.T) {
	params := []struct {
		a     int
		expected []byte
	} {
		{ a: 1, expected: []byte{1 } },
		{ a: 11, expected: []byte{1, 1 } },
		{ a: 123, expected: []byte{3, 2, 1} },
		{ a: 1234, expected: []byte{4, 3, 2, 1} },
		{ a: 12345, expected: []byte{5, 4, 3, 2, 1} },
	}

	for _, param := range params {
		ret := NtoByte(param.a)
		if bytes.Compare(ret, param.expected) != 0 {
			t.Fatal("NtoByte(param.a) =", ret, " / Expected : ", param.expected)
		}
	}
}

func TestInverseByte(t *testing.T) {
	params := []struct {
		in []byte
		expected []byte
	} {
		{ in: []byte{1, 2, 3, 4, 5}, expected: []byte{5, 4, 3, 2, 1} },
		{ in: []byte{1}, expected: []byte{1} },
		{ in: []byte{}, expected: []byte{} },
	}

	for _, param := range params {
		ret := InverseByte(param.in)
		if bytes.Compare(ret, param.expected) != 0 {
			t.Fatal("InverseByte(param.in) =", ret, " / Expected : ", param.expected)
		}
	}
}

func TestIsPalindromeByte(t *testing.T) {
	params := []struct {
		in []byte
		expected bool
	} {
		{ in: []byte{1, 2, 3, 4, 5}, expected: false },
		{ in: []byte{1, 2, 1}, expected: true },
		{ in: []byte{1, 1}, expected: true },
		{ in: []byte{1}, expected: true },
		{ in: []byte{1, 2, 2}, expected: false },
		{ in: []byte{1, 2}, expected: false },
	}

	for _, param := range params {
		ret := IsPalindromeByte(param.in)
		if ret != param.expected {
			t.Fatal("IsPalindromeByte(", param.in, ") =", ret, " / Expected : ", param.expected)
		}
	}
}


func TestSumTwoByteInteger(t *testing.T) {
	params := []struct {
		in1 []byte
		in2 []byte
		expected []byte
	} {
		{ []byte{0}, []byte{0}, []byte{0} },
		{ []byte{1}, []byte{}, []byte{1} },
		{ []byte{}, []byte{1}, []byte{1} },
		{ []byte{1}, []byte{0}, []byte{1} },
		{ []byte{0}, []byte{1}, []byte{1} },
		{ []byte{5}, []byte{5}, []byte{0, 1} },
		{ []byte{1, 1}, []byte{2, 2}, []byte{3, 3} },
		{ []byte{5, 5}, []byte{1, 5}, []byte{6, 0, 1} },
	}

	for _, param := range params {
		ret := SumTwoByteInteger(param.in1, param.in2)
		if bytes.Compare(ret, param.expected) != 0 {
			t.Fatal("IsPalindromeByte(", param.in1, ", ", param.in2, ") =", ret, " / Expected : ", param.expected)
		}
	}
}