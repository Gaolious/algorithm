package main

import "fmt"

func main() {
	const MaxN = 50_000
	var D [MaxN+1]int
	var n int
	var i, j int

	for i = 1 ; i <= MaxN ; i ++ {
		D[i] = i
		for j = 1 ; j * j <= i ; j ++ {
			if D[ i ] > D[i - j*j] + 1 {
				D[ i ] = D[ i - j*j ] + 1
			}
		}
	}

	fmt.Scanf("%d", &n)
	fmt.Printf("%d\n", D[n])

}
