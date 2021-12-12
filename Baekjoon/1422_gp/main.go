package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type FIO struct {
	in *bufio.Scanner
	out *bufio.Writer
}
func (fio *FIO) readInt() (int, string) {
	fio.in.Scan()
	txt := fio.in.Text()
	n, _ := strconv.Atoi(txt)
	return n, txt
}
func (fio *FIO) Close() {
	fio.out.Flush()
}
func newFIO() *FIO {
	t := FIO{
		in: bufio.NewScanner(os.Stdin),
		out : bufio.NewWriter(os.Stdout),
	}
	t.in.Split(bufio.ScanWords)
	return &t
}
func max(a, b int ) int {
	if a > b {
		return a
	}
	return b
}
func main() {
	var N, K int
	var i int
	var maxN, t int
	var Numbers []string
	var strMaxN string

	fio := newFIO()
	defer fio.Close()

	K, _ = fio.readInt()
	N, _ = fio.readInt()

	Numbers = make([]string, K)

	for i = 0 ; i < K ; i ++ {
		t, Numbers[i] = fio.readInt()
		if t > maxN {
			maxN = t
			strMaxN = Numbers[i]
		}
	}
	sort.Slice(Numbers, func(a, b int) bool {
		var l1, l2, T, i int
		l1 = len(Numbers[a])
		l2 = len(Numbers[b])
		T = l1 * l2
		for i = 0 ; i < T ; i ++ {
			if Numbers[a][ i % l1 ] < Numbers[b][ i % l2 ] {
				return false
			} else if Numbers[a][ i % l1 ] > Numbers[b][ i % l2 ] {
				return true
			}
		}
		return false
	})

	for i = 0 ; i < K ; i ++ {
		fmt.Print(Numbers[i])
		for ; strMaxN == Numbers[i] && N > K; N-- {
			fmt.Print(Numbers[i])
		}
	}
}
