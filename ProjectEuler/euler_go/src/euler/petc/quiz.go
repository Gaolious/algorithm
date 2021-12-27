package petc

func PQuiz4() string {
	var n uint64
	var ret []byte

	var F func(n uint64, ret *[]byte)

	F = func(n uint64, ret *[]byte) {
		if n > 26 {
			F(n/26, ret)
			n %= 26
		}
		if 1 <= n && n <= 26 {
			*ret = append(*ret, byte(n-1+'A'))
		}
	}

	n = 100000000
	F(n, &ret)
	return string(ret)
}

package main

func kth(a []int, k int) int {
	var MaxN = 1000000000
	var MaxDiv = 50000

	var radix, order []int
	var i int
	var idx_radix, idx_order int

	radix = make([]int, MaxDiv)
	order = make([]int, MaxDiv)

	for i = len(a) - 1; i >= 0; i-- {
		a[i] += MaxN
		radix[a[i]/MaxDiv]++
	}
	for i = 0; radix[i] < k; i++ {
		k -= radix[i]
	}
	idx_radix = i

	for i = len(a) - 1; i >= 0; i-- {
		if a[i]/MaxDiv == idx_radix {
			order[a[i]%MaxDiv]++
		}
	}
	for i = 0; order[i] < k; i++ {
		k -= order[i]
	}
	idx_order = i

	return idx_order - MaxN + idx_radix*MaxDiv
}
