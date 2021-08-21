package io

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

func End() {
	wr.Flush()
}


type DATA_INPUT struct {
	s string
	length int
	offset int
}
func GetStringInput(s string) *DATA_INPUT {
	var p DATA_INPUT
	p.s = s
	p.length = len(s)
	p.offset = 0
	return &p
}
func (p *DATA_INPUT) ReadInt() int {
	var ret int
	var sign bool
	for p.offset < p.length && p.s[p.offset] <= ' ' { p.offset ++ }

	if p.offset < p.length && p.s[p.offset] == '-' {
		sign = true
	} else {
		sign = false
	}

	for ret = 0 ; p.offset < p.length && '0' <= p.s[p.offset] && p.s[ p.offset ] <= '9' ; p.offset ++ {
		ret = ret * 10 + int( p.s[ p.offset ] - '0' )
	}
	if sign {
		return -ret
	} else {
		return ret
	}
}
