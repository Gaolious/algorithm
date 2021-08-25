package p0xx

import (
	"math/big"
	"os"
	"sort"
)

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
func P21() int {
	var D [10000 + 1]int
	var i, j int
	var s int

	for i = 1 ; i <= 10000 ; i ++ {
		for j = 1 ; j < i ; j ++ {
			if i % j == 0 {
				D[ i ] += j
			}
		}
	}
	for i = 1 ; i <= 10000 ; i ++ {
		if D[ i ] <= 10000 && D[ i ] != i && D[ D[i] ] == i {
			s += i
		}
	}
	return s
}

func P22() uint64 {
	var buffer = make([]byte, 50000)
	var names = make([]string, 0, 50000)
	var i, j int
	var ret uint64
	fin, _ := os.Open("src/euler/p0xx/p22.in")
	defer fin.Close()

	n, _ := fin.Read(buffer)
	for i = 0 ; i < n ; i ++ {
		if buffer[i] == '"' {
			for j = i + 1 ; j < n && buffer[j] != '"' ; j ++ {}
			names = append(names, string( buffer[i+1:j]))
			i = j
		}
	}

	sort.Strings(names)
	for idx, name := range names {
		var s int
		for i = len(name) - 1 ; i >= 0 ; i -- {
			if name[i] >= 'A' {
				s += int(name[i] - 'A' + 1)
			} else {
				s += int(name[ i ] - 'a' + 1)
			}
		}
		ret += uint64( (idx + 1 ) * s )
	}
	return ret
}