package p1xx

import "fmt"

func P191() int {
	const DAY = 30

	var D[DAY+1][3+1][2+1] int
	var i, absent, late int

	D[0][0][0] = 1
	for i = 0 ; i < DAY ; i ++ {
		for absent = 0 ; absent < 3 ; absent++ {
			for late = 0 ; late < 2 ; late++ {
				// On time
				D[i+1][0][late] += D[i][absent][late]
				// Absent
				D[i+1][absent+1][late] += D[i][absent][late]
				// Late
				D[i+1][0][late+1] += D[i][absent][late]
			}
		}
	}
	var ret = 0
	for absent = 0 ; absent < 3 ; absent++ {
		for late = 0 ; late < 2 ; late++ {
			fmt.Printf("absent=%d, late=%d, D[%d][%d][%d] = %d\n", absent, late, DAY, absent, late, D[DAY][absent][late])
			ret += D[DAY][absent][late]
		}
	}
	return ret
}
