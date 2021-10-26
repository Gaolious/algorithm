package petc

func PQuiz4() string {
	var n uint64
	var ret []byte

	var F func (n uint64, ret *[]byte)

	F = func (n uint64, ret *[]byte) {
		if n > 26 {
			F(n / 26, ret)
			n %= 26
		}
		if 1 <= n && n <= 26 {
			*ret = append(*ret, byte(n-1+'A'))
		}
	}

	n = 100000000
	F(n, &ret)
	return string(ret)
}
