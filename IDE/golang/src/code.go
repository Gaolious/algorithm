package main

import (
	// "bufio"
	"bufio"
	"fmt"
	"os"
	"strings"
)

var (
	fin  *bufio.Reader
	fout *bufio.Writer
)

func process() {

	n, a, b := 0, 0, 0
	fmt.Read()
	fmt.Fscanln(fin, &n)

	for i := 0; i < n; i++ {
		fmt.Fscanln(fin, &a, &b)
		fmt.Fprintln(fout, a, b)
	}
}

func main() {

	process()

	fout.Flush()
}

func init() {

	c, _ := os.Getwd()

	// fake stdin
	if strings.HasPrefix(c, "/home/ajava/work/") {
		r, _ := os.Open("input/input.txt")
		os.Stdin = r
	}

	fin = bufio.NewReader(os.Stdin)
	fout = bufio.NewWriter(os.Stdout)
}
