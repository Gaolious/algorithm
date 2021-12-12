package main

import (
	"fmt"
	"math/rand"
	"sort"
)

const (
	MaxX = 14
	MaxY = 8
)
var (
	dx = []int { 0, 1, 1, 1, 0, -1, -1, -1}
	dy = []int { -1, -1, 0, 1, 1, 1, 0, -1}
)
type MAP struct {
	data [MaxY][MaxX]byte
	score int
}

func isRange(y, x int ) bool {
	return 0 <= y && y < MaxY && 0 <= x && x < MaxX
}

func (m *MAP)find(y, x int, n int) bool {
	var d int
	var target = byte(n%10)
	if n < 1 {
		return true
	}
	for d = 0 ; d < 8 ; d ++ {
		tx := x + dx[ d ]
		ty := y + dy[ d ]
		if ! isRange(ty, tx) {
			continue
		}
		if m.data[ty][tx] == target {
			if n < 10 {
				return true
			} else {
				return m.find(ty, tx, n/10)
			}
		}
	}
	return false
}

func (m *MAP)isEqual( other *MAP) bool {
	if m.score != other.score { return false }
	var y, x int
	for y = 0 ; y < MaxY; y ++ {
		for x = 0; x < MaxX ; x++ {
			if m.data[y][x] != other.data[y][x] {
				return false
			}
		}
	}
	return true
}
func (m *MAP)updateScore() {
	var digit, n, y, x, pow, d int
	var check [100000]byte

	m.score = 0
	var available [MaxY][MaxX][5] map[int]byte

	// for y = 0 ; y < MaxY; y++ {
	// 	for x = 0; x < MaxX; x++ {
	// 		fmt.Printf("%c ", m.data[y][x] + '0')
	// 	}
	// 	fmt.Println()
	// }
	for y = 0 ; y < MaxY; y++ {
		for x = 0; x < MaxX; x++ {
			for digit = 0 ; digit < 5 ; digit ++ {
				available[y][x][digit] = make(map[int]byte)
			}
		}
	}

	for digit, pow = 0, 1 ; digit < 5 ; digit ++ {
		for y = 0 ; y < MaxY; y++ {
			for x = 0; x < MaxX; x++ {

				if digit == 0 {
					val := int(m.data[y][x])
					available[y][x][digit][val] = 1
					check[val] = 1
				} else {
					for d = 0 ; d < 8 ; d ++ {
						tx := x + dx[ d ]
						ty := y + dy[ d ]
						if ! isRange(ty, tx) {
							continue
						}
						for prev_val := range available[ty][tx][digit-1] {
							val := prev_val * 10 + int(m.data[y][x])
							available[y][x][digit][val] = 1
							check[val] = 1
						}
					}
				}
			}
		}
		for n = pow ; n < pow*10 ; n ++ {
			if check[n] == 0 {
				m.score = n - 1
				return
			}
		}
		pow = pow * 10
	}
}

func main() {
	const MaxRepeat = 1000
	var y, x, bit int

	var sol, best MAP
	for y = 0; y < MaxY; y++ {
		for x = 0; x < MaxX; x++ {
			sol.data[y][x] = byte( rand.Int() % 10 )
		}
	}
	sol.updateScore()

	for repeat := 0 ; repeat < MaxRepeat ; repeat ++ {
		var next = make([]*MAP, 0)
		for i := 0 ; i < len(candidates) ; i +=2 {
			choice := 0 // rand.Int()%10
			switch choice {
			case 0 :
				bit = rand.Int() % ( 1 << MaxY )
				next1 := *candidates[i]
				next2 := *candidates[i+1]
				x = rand.Int() % MaxX
				for y = 0 ; y < MaxY ; y ++ {
					if bit & ( 1 << y ) == 0 { continue }
					next1.data[y][x], next2.data[y][x] = next2.data[y][x], next1.data[y][x]
				}
				next1.updateScore()
				next2.updateScore()
				next = append(next, &next1)
				next = append(next, &next2)
			}
		}
		sort.Slice( next, func(i, j int) bool { return next[i].score > next[j].score })

		if next[0].score > best.score {
			best = *next[0]
		}
		if repeat % 1000 == 0 {
			fmt.Printf("Best : %d / Repeat : %d / %d \n", best.score, repeat + 1, MaxRepeat)
		}
	}
	fmt.Printf("Best : %d\n", best.score)
	fmt.Println(best.data)
}
