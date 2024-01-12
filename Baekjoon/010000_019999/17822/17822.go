package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type FIO struct {
	in *bufio.Scanner
	out *bufio.Writer
}
func (fio *FIO) readInt() int {
	fio.in.Scan()
	txt := fio.in.Text()
	n, _ := strconv.Atoi(txt)
	return n
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

var D[50][50]int
var (
	T          int
	M          int
	N          int
	TotalCount int
	TotalSum   int
)

func spin(x, d, k int ) {
	var i, j int
	var offset int
	var tmp[50] int

	for i = x - 1 ; i < N ; i += x {
		switch d {
		case 0:
			offset = ( M - k ) % M
		case 1:
			offset = ( M + k ) % M
		}

		for j = 0 ; j < M ; j ++ {
			tmp[j] = D[i][ (offset+j)%M ]
		}
		for j = 0 ; j < M ; j ++ {
			D[i][j] = tmp[j]
		}

	}
}
type Point struct {
	y, x int
}

func (p *Point) isNeighbor( other *Point ) bool {
	if p.y == other.y {
		if (M + p.x + 1) % M == other.x % M {
			return true
		}
		if (M + p.x - 1) % M == other.x % M {
			return true
		}
	}
	if p.x == other.x {
		if p.y + 1 == other.y || other.y + 1 == p.y {
			return true
		}
	}
	return false
}

func remove() int {
	var y, x, d int
	var dx = []int{ 0, 1, 0, -1 }
	var dy = []int{ 1, 0, -1, 0 }
	var Check [50][50]bool
	var curr, next Point
	var ret, val int

	for y = 0 ; y < N ; y ++ {
		for x = 0 ; x < M ; x ++ {
			if Check[y][x] || D[y][x] == 0 {
				continue
			}

			Check[y][x] = true

			var Queue = make([]Point, 0)
			var head int
			Queue = append(Queue, Point{y, x})
			val = D[y][x]

			for head < len(Queue) {
				curr = Queue[head]
				head += 1
				for d = 0 ; d < 4 ; d ++ {
					next = Point{y: curr.y + dy[d], x: (M + curr.x + dx[d]) % M }
					if next.y < 0 || next.y >= N { continue }
					if !curr.isNeighbor(&next) { continue }
					if Check[next.y][next.x] { continue }
					if val != D[next.y][next.x] { continue}

					Queue = append(Queue, next)
					Check[ next.y ][ next.x ] = true
					TotalCount -= 1
					TotalSum -= D[y][x]
					D[next.y][next.x] = 0
					dump("test")
					ret += 1
				}
			}

			if len(Queue) > 1 {
				TotalCount -= 1
				TotalSum -= D[y][x]
				D[y][x] = 0
				ret += 1
			}
		}
	}
	return ret
}

func adjust() {
	var i, j int
	var inc int

	for i = 0 ; i < N ; i ++ {
		for j = 0 ; j < M ; j ++ {
			if D[i][j] == 0 {
				continue
			}
			if D[i][j] * TotalCount < TotalSum {
				D[i][j] += 1
				inc += 1
			} else if D[i][j] * TotalCount > TotalSum {
				D[i][j] -= 1
				inc -= 1
			}
		}
	}
	TotalSum += inc
}

func dump(title string ) {
	// var i, j int
	//
	// fmt.Printf("------\n => %s\n", title)
	// for i = 0 ; i < N ; i ++ {
	// 	for j = 0; j < M; j++ {
	// 		fmt.Printf("%d ", D[i][ j ])
	// 	}
	// 	fmt.Println()
	// }
}

func main() {
	var i, j int
	var x, d, k int

	fio := newFIO()
	defer fio.Close()

	N = fio.readInt()
	M = fio.readInt()
	T = fio.readInt()

	for i = 0 ; i < N ; i ++ {
		for j = 0 ; j < M ; j ++ {
			D[i][j] = fio.readInt()
			TotalSum += D[i][j]
			TotalCount += 1
		}
	}

	dump("init")

	for i = 0 ; i < T ; i ++{

		x = fio.readInt()
		d = fio.readInt()
		k = fio.readInt()

		spin(x, d, k)
		dump("after spin")

		removed := remove()
		if TotalSum == 0 || TotalCount == 0 {
			break
		} else if removed == 0 {
			adjust()
		}
		dump("remove or adjust")
	}

	fmt.Println(TotalSum)
}

