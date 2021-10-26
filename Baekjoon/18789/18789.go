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
	// neighbor [10][11] byte
	score int
}

func isRange(y, x int ) bool {
	return 0 <= y && y < MaxY && 0 <= x && x < MaxX
}

func (m *MAP)updateNeighbor() {
	// var y, x, d int
	// for y = 0 ; y < 10 ; y ++ {
	// 	for x = 0 ; x < 11 ; x ++ {
	// 		m.neighbor[y][x] = 0
	// 	}
	// }
	//
	// for y = 0 ; y < MaxY ; y ++ {
	// 	for x = 0 ; x < MaxX ; x ++ {
	// 		for d = 0 ; d < 8 ; d ++ {
	// 			tx := x + dx[ d ]
	// 			ty := y + dy[ d ]
	// 			if ! isRange(ty, tx) {
	// 				continue
	// 			}
	// 			if m.neighbor[ m.data[y][x] ][ m.data[ty][tx] ] == 0 {
	// 				m.neighbor[ m.data[y][x] ][ m.data[ty][tx] ] = 1
	// 				m.neighbor[ m.data[y][x] ][ 10 ] ++
	// 			}
	// 		}
	// 	}
	// }
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
	var n, y, x int
	var found bool
	var target byte

	m.score = 0

	for n = 1 ; ; n ++ {
		found = false
		target = byte(n%10)

		for y = 0 ; y < MaxY && !found ; y ++ {
			for x = 0; x < MaxX && !found; x++ {
				if m.data[y][x] == target {
					if m.find(y, x, n/10) {
						found = true
						break
					}
				}
			}
		}

		if found {
			m.score = n
			continue
		} else {
			break
		}
	}
}

func main() {
	const MaxRepeat = 10000
	const CandidateSize = 50
	var candidates = make([]*MAP, 0)
	var y, x int
	var n byte

	for n = 0 ; n < CandidateSize ; n ++ {
		var newD MAP
		for y = 0; y < MaxY; y++ {
			for x = 0; x < MaxX; x++ {
				newD.data[y][x] = byte( rand.Int() % 10 )
			}
		}
		newD.updateScore()
		candidates = append(candidates, &newD)
	}

	for repeat := 0 ; repeat < MaxRepeat ; repeat ++ {
		var next = make([]*MAP, 0)
		for _, curr := range candidates {
			for x = 0; x < MaxX; x++ {
				for bit := 1<<MaxY ; bit > 0 ; bit -- {

					newD := *curr
					for y = 0 ; y < MaxY ; y ++ {
						if bit&(1<<x) == 0 {
							newD.data[y][x] = byte(rand.Int() % 10)
						}
					}
					newD.updateScore()

					found := false
					for k := range next {
						if next[k].isEqual(&newD) {
							found = true
							break
						}
					}
					if !found {
						next = append(next, &newD)
					}
				}
			}
		}
		sort.Slice( next, func(i, j int) bool { return next[i].score > next[j].score })

		fmt.Printf("Current Repeat : %d / %d \n", repeat + 1, MaxRepeat)
		candidates = make([]*MAP, 0)
		maxSize := CandidateSize
		if len(next) < maxSize {
			maxSize = len(next)
		}
		candidates = append(candidates,next[:maxSize]...)

		for idx, curr := range candidates {
			if idx >= 5 { break }
			fmt.Printf("Score[%d] : %d\n", idx, curr.score)
			fmt.Println(curr.data)
		}
	}
}
