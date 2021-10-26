package p7xx

func P700() uint64 {
	var num, M, S, lo, hi  uint64
	num = 1_504_170_715_041_707
	M = 4_503_599_627_370_517

	lo = num
	hi = num
	S = num

	for lo > 0 {
		m := ( lo + hi ) % M
		if m < lo {
			lo = m
			S += m
		} else {
			hi = m
		}
	}

	return S
}