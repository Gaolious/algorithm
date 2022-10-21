package main

import (
	father "BronzeIV/util"
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

func main() {
	defer out.Flush()
	father.AOFunction()

	a, b, c := readInt3()
	if a+b == c {
		fmt.Println(1)
	} else if a*a+b*b == c*c {
		fmt.Println(2)
	} else {
		fmt.Println(-1)
	}
}
