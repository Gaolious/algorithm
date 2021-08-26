package p3xx

import (
	"euler/utils"
)

func P351() int64 {

	const (
		N = 100
	)
	var ret int64
	var x, y, g int
	var Hash map[int64]byte
	Hash = make(map[int64]byte)

	Key := func (x, y int ) int64 {
		t := int64(x) * 1000000000
		t += int64(y)
		return t
	}

	for x = 1 ; x <= N ; x ++ {
		for y = x - 2 ; y > 0 ; y -= 2 {
			g = utils.GcdInt(x, y)
			key := Key(x/g, y/g)
			_, ok := Hash[key]

			if ok {
				ret ++
			} else {
				Hash[key] = '1'
			}
		}
	}

	ret *= 2

	ret += (N) - 1
	ret += (N/2) - 1
	ret *= 6
	return ret
}