package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var in = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func init() {
	in.Split(bufio.ScanWords)
}

func readInt() int {
	in.Scan()
	n, _ := strconv.Atoi(in.Text())
	return n
}
func readFloat() float64 {
	in.Scan()
	n, _ := strconv.ParseFloat(in.Text(), 64)
	return n
}
func readWord() string {
	in.Scan()
	return in.Text()
}
func readInt2() (int, int) {
	return readInt(), readInt()
}
func readInt3() (int, int, int) {
	return readInt(), readInt(), readInt()
}
func readInt4() (int, int, int, int) {
	return readInt(), readInt(), readInt(), readInt()
}
func sum(args ...int) int {
	var ret int
	ret = 0
	for _, n := range args {
		ret += n
	}
	return ret
}
func min(args ...int) int {
	var ret int
	var first bool
	first = true
	for _, n := range args {
		if first || ret > n {
			ret, first = n, false
		}
	}
	return ret
}

func max(args ...int) int {
	var ret int
	var first bool
	first = true
	for _, n := range args {
		if first {
			ret, first = n, false
		} else if ret < n {
			ret = n
		}
	}
	return ret
}
func gcd(a, b int) int {
	if b > 0 {
		return gcd(b, a%b)
	} else {
		return a
	}
}
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func ceil(a, b int) int {
	// ceil(a/b)
	m := a / b
	if a%b != 0 {
		m++
	}
	return m
}
func ymd(y, m, d int) int {
	return y*10000 + m*100 + d
}
func main() {
	defer out.Flush()
	cx, cy := readInt2()
	r := readInt()

	sx := cx - r
	sy := cy - r
	ex := cx + r
	ey := cy + r

	fmt.Fprintf(out, "%d %d\n", sx, sy)
	fmt.Fprintf(out, "%d %d\n", sx, ey)
	fmt.Fprintf(out, "%d %d\n", ex, ey)
	fmt.Fprintf(out, "%d %d\n", ex, sy)

}
