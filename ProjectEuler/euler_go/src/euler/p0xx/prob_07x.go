package p0xx

import (
	"euler/utils"
	"fmt"
)

func P71() uint64 {
	type Num struct {
		a, b uint64
	}

	var Min = Num{2, 7}
	var Max = Num{3, 7}
	var n uint64
	var IsLarge = func( n1, n2 *Num) bool { // n1 < n2 ?
		// 2  1
		// 7  3
		if n1.a * n2.b < n1.b * n2.a {
			return true
		}
		return false
	}

	for n = 2 ; n <= 1_000_000 ; n ++ {
		//  ?   3            9
		// --- ---  => --- ---
		//  3   7       21  21
		newMax := n * Max.a // 9
		newMin := (newMax / Max.b) * Max.b // 9 / 7 = 1
		if newMax == newMin {
			newMin -= Max.b
		}
		newG := utils.GcdUInt64_2(newMin, n * Max.b)
		cNum := Num{ newMin / newG, n * Max.b / newG}

		if IsLarge(&Min, &cNum) {
			Min = cNum
		}
	}
	fmt.Printf("%d/%d\n", Min.a, Min.b)
	return 0
}
