package p1xx

import "fmt"

func P181() uint64 {

	const CountB = 60
	const CountW = 40

	var D[CountB+1][CountW+1]uint64
	var B, W, sb, sw, i int

	D[0][0] = 1
	for sb = 0 ; sb <= CountB ; sb ++ {
		for sw = 0 ; sw <= CountW ; sw ++ {
			if sb == 0 && sw == 0 { continue }
			for B = CountB ; B >= 0 ; B -- {
				for W = CountW ; W >= 0 ; W -- {
					for i = 1 ; sb * i + B <= CountB && sw * i + W <= CountW ; i ++ {
						D[sb*i + B][sw*i + W] += D[B][W]
					}
				}
			}
		}
	}
	for sb = 0 ; sb < CountB ; sb ++ {
		for sw = 0 ; sw < CountW ; sw ++ {
			fmt.Printf("%3d ", D[sb][sw])
		}
		fmt.Println()
	}
	return D[CountB][CountW]
}
