package p1xx

import "fmt"

func P161() uint64 {
	const ROW = 12
	const COLUMN = 9
	const N = 1 << COLUMN

	type Point struct {
		y, x int
	}
	var Shape =[6][3]Point{
		// o o
		// o
		{ {0,0}, {0,1}, {1,0} },
		// o o
		//   o
		{ {0,0}, {0,1}, {1,1} },
		// o
		// o o
		{ {0,0}, {1,0}, {1,1} },
		//   o
		// o o
		{ {0,0}, {1,0}, {1,-1} },
		// o
		// o
		// o
		{ {0,0}, {1,0}, {2,0} },
		// o o o
		{ {0,0}, {0,1}, {0,2} },
	}
	var A [N][N]map[uint32]uint64
	var can = func(sy, sx int, idx int, l1, l2, l3 uint32) bool {
		for i := 0 ; i < 3 ; i ++ {
			x := sx + Shape[idx][i].x
			y := sy + Shape[idx][i].y
			if x < 0 || x >= COLUMN || y < 0 || y >= ROW { return false }

			switch y {
			case 0:
				if (1 << x) & l1 > 0 { return false }
			case 1:
				if (1 << x) & l2 > 0 { return false }
			case 2:
				if (1 << x) & l3 > 0 { return false }
			}
		}
		return true
	}
	var setShape = func(sy, sx int, idx int, l1, l2, l3 uint32) (uint32, uint32, uint32){
		for i := 0 ; i < 3 ; i ++ {
			x := sx + Shape[idx][i].x
			y := sy + Shape[idx][i].y
			switch y {
			case 0:
				l1 |= 1 << x
			case 1:
				l2 |= 1 << x
			case 2:
				l3 |= 1 << x
			}
		}
		return l1, l2, l3
	}

	var Find func(sx int, initA, initB uint32, l1, l2, l3 uint32)
	Find = func(sx int, initA, initB uint32, l1, l2, l3 uint32) {
		if l1 == N-1 {
			key := (l2 << COLUMN) | l3
			if _, ok := A[initA][initB][key]; !ok {
				A[initA][initB][key] = 0
			}
			A[initA][initB][key]++
			return
		}
		if l1 & ( 1 << sx) > 0 {
			Find(sx+1, initA, initB, l1, l2, l3)
			return
		}

		for i := 0 ; i < 6 ; i ++ {
			if can( 0, sx, i, l1, l2, l3) {
				newL1, newL2, newL3 := setShape(0, sx, i, l1, l2, l3)
				Find(sx+1, initA, initB, newL1, newL2, newL3)
			}
		}
	}

	var y, i, j uint32
	var D [ROW+2][N][N]uint64

	for i = 0 ; i < N ; i ++ {
		for j = 0 ; j < N ; j ++ {
			A[i][j] = make(map[uint32]uint64)
			Find(0, i, j, i, j, 0)
		}
	}

	D[0][0][0] = 1
	for y = 0 ; y <= ROW ; y ++ {
		for i = 0 ; i < N ; i ++ {
			for j = 0 ; j < N ; j ++ {
				for key, cnt := range A[i][j] {
					nextL1 := (key>>COLUMN) & (N-1)
					nextL2 := (key) & (N-1)
					D[y+1][nextL1][nextL2] += D[y][i][j] * cnt
				}
			}
		}

		fmt.Printf("Y=%d / cnt=%d\n", y, D[y][0][0])
	}
	return 0
}