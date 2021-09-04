package p0xx

import "fmt"

func P30() int {
	var P [10]int
	var i int
	var S = func(n int) int {
		var ret int
		for n > 0 {
			ret += P[ n%10 ]
			n/=10
		}
		return ret
	}
	var ret int

	for i = 0 ; i < 10 ; i ++ {
		P[ i ] = i*i*i*i*i
	}

	for i = 10 ; i <= 1000000 ; i ++ {
		if i == S(i) {
			fmt.Printf("i : %d\n", i)
			ret += i
		}
	}
	return ret
}

func P31() int {
	var C = []int{ 1, 2, 5, 10, 20, 50, 100, 200}
	var D [201]int
	var i, j int

	D[0] = 1
	for i = 0 ; i < len(C) ; i ++ {
		for j = C[i] ; j<=200 ; j++ {
			D[ j ] += D[ j - C[i] ]
		}
	}
	return D[200]
}