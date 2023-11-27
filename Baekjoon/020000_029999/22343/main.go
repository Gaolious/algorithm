package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
)

type FIO struct {
	in *bufio.Reader
	out *bufio.Writer
}
func (fio *FIO) readInt() int {
	bytes, _, _ := fio.in.ReadLine()
	n, _ := strconv.Atoi(string(bytes))
	return n
}
func (fio *FIO) Close() {
	fio.out.Flush()
}
func newFIO() *FIO {
	return &FIO{
		in: bufio.NewReader(os.Stdin),
		out : bufio.NewWriter(os.Stdout),
	}
}

var (
	b0 = big.NewInt(0)
	b1 = big.NewInt(1)
	b2 = big.NewInt(2)
)
func F(line []byte) ([]int, int) {
	var Sol = make([]int, len(line) + 1)
	var i int
	var openCount, length int
	length = len(line)

	for i = 0 ; i < length ; i ++ {
		switch line[i] {
		case '(':
			openCount++
		case ')':
			if line[i-1] == '(' {
				Sol[openCount]++
				openCount--
			} else {
				openCount--
			}
		}
	}
	max_pos := 0
	for i = 0 ; i < length ; i ++ {
		Sol[i + 1 ] += Sol[ i ] / 2
		Sol[ i ] %= 2
		if Sol[i] == 1 {
			max_pos = i
		}
	}
	return Sol, max_pos
}

func main() {
	var line string
	fio := newFIO()
	defer fio.Close()

	for T := fio.readInt() ; T > 0 ; T -- {
		ret := ""

		line, _ = fio.in.ReadString('\n')
		v1, p1 := F([]byte(line))
		line, _ = fio.in.ReadString('\n')
		v2, p2 := F([]byte(line))
		if p1 > p2 {
			ret = ">"
		} else if p1 < p2 {
			ret = "<"
		} else {
			for i := p1 ; i >= 0 ; i -- {
				if v1[i] > v2[i] {
					ret = ">"
					break
				}
				if v1[i] < v2[i] {
					ret = "<"
					break
				}
			}
		}
		if ret == "" { ret = "="}
		fmt.Println(ret)
	}
}
