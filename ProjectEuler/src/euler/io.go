package main

import (
	"bufio"
	"os"
	"strconv"
)

var (
	sc *bufio.Scanner
	wr *bufio.Writer
)

func init()  {
	sc = bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	wr = bufio.NewWriter(os.Stdout)
}

func readInt() int {
	sc.Scan()
	ret, _  := strconv.Atoi(sc.Text())
	return ret
}

func readString() string {
	sc.Scan()
	return sc.Text()
}

func writeInt(val int) {
	s := strconv.Itoa(val)
	wr.WriteString(s + "\n")
}