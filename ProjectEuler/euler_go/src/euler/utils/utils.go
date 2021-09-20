package utils

import (
	"bufio"
	"os"
	"path/filepath"
)

const (
	n64_M = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	N64_MOD = 62
)

func ConvertNto64Str( n int ) string {
	var Reverse = func (s string) string {
		r := []rune(s)
		for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
		return string(r)
	}
	var ret string

	for n > 0 {
		ret += string( n64_M[ n % N64_MOD ])
		n /= N64_MOD
	}

	return Reverse(ret)
}
func Convert64StrToN( s []byte  ) int {
	var ret int
	for i := 0 ; i < len(s) ; i ++ {
		if '0' <= s[i] && s[i] <= '9' {
			ret = ret * N64_MOD + int(s[i] - '0')
		} else if 'a' <= s[i] && s[i] <= 'z' {
			ret = ret * N64_MOD + int(s[i] - 'a') + 10
		} else if 'A' <= s[i] && s[i] <= 'Z' {
			ret = ret * N64_MOD + int(s[i] - 'A') + 10 + 26
		}
	}
	return ret
}

func GetPrimes( N int) []int {
	// N 이하 소수
	var primes = make([]int, 0, 0)
	// var i, j int
	var line []byte
	var n int

	var is = func(p int ) bool {
		length := len(primes)
		for i := 0 ; i < length && primes[i] * primes[i] <= N ; i ++ {
			if p % primes[ i ] == 0 {
				return false
			}
		}
		return true
	}

	var ReadPrimes = func(filename string, maxN int){
		fin, err := os.Open(filename)
		if err != nil {
			return
		}
		defer fin.Close()
		bin := bufio.NewReader(fin)

		for {
			line, _, err = bin.ReadLine()
			if err != nil { return }
			n = Convert64StrToN(line)
			if n > maxN {
				return
			}
			primes = append(primes, n)
		}
	}

	ex, _ := os.Executable()
	exPath := filepath.Dir(ex)
	filename := filepath.Join(exPath, "primes.txt")

	ReadPrimes(filename, N)

	fout, _ := os.OpenFile(filename, os.O_RDWR|os.O_APPEND|os.O_CREATE, 0644)
	defer fout.Close()
	bout := bufio.NewWriter(fout)
	defer bout.Flush()

	if len(primes) < 1 {
		primes = append(primes, 2)
		bout.WriteString(ConvertNto64Str(2))
		bout.WriteString("\n")
	}
	n = primes[ len(primes) - 1] + 1
	if n % 2 == 0 { n ++ }
	for  ; n <= N ; n += 2 {
		if is(n) {
			primes = append(primes, n)
			bout.WriteString(ConvertNto64Str(n))
			bout.WriteString("\n")
		}
	}
	return primes
}

func GetUint64Primes( N uint64) []uint64 {
	// N 이하 소수
	var primes = make([]uint64, 0, 0)
	// var i, j int
	var line []byte
	var n uint64

	var is = func(p uint64 ) bool {
		length := len(primes)
		for i := 0 ; i < length && primes[i] * primes[i] <= N ; i ++ {
			if p % primes[ i ] == 0 {
				return false
			}
		}
		return true
	}

	var ReadPrimes = func(filename string, maxN uint64){
		fin, err := os.Open(filename)
		if err != nil {
			return
		}
		defer fin.Close()
		bin := bufio.NewReader(fin)

		for {
			line, _, err = bin.ReadLine()
			if err != nil { return }
			n := uint64(Convert64StrToN(line))
			if n > maxN {
				return
			}
			primes = append(primes, uint64(n))
		}
	}

	ex, _ := os.Executable()
	exPath := filepath.Dir(ex)
	filename := filepath.Join(exPath, "primes.txt")

	ReadPrimes(filename, N)

	fout, _ := os.OpenFile(filename, os.O_RDWR|os.O_APPEND|os.O_CREATE, 0644)
	defer fout.Close()
	bout := bufio.NewWriter(fout)
	defer bout.Flush()

	if len(primes) < 1 {
		primes = append(primes, 2)
		bout.WriteString(ConvertNto64Str(2))
		bout.WriteString("\n")
	}
	n = primes[ len(primes) - 1] + 1
	if n % 2 == 0 { n ++ }
	for  ; n <= N ; n += 2 {
		if is(n) {
			primes = append(primes, n)
			bout.WriteString(ConvertNto64Str(int(n)))
			bout.WriteString("\n")
		}
	}
	return primes
}

func GetPrimesPanDigital( N int) []int {
	// N 이하 소수
	var primes = make([]int, 0, 0)
	// var i, j int
	var line []byte
	var n int
	var PD = func(n int) bool {
		var check [10]byte
		for n > 0 {
			if n % 10 == 0 { return false }
			if check[ n%10 ] == 1 { return false }
			check[ n % 10 ] = 1
			n /= 10
		}
		return true
	}

	var ReadPrimes = func(filename string, maxN int){
		fin, err := os.Open(filename)
		if err != nil {
			return
		}
		defer fin.Close()
		bin := bufio.NewReader(fin)

		for {
			line, _, err = bin.ReadLine()
			if err != nil { return }
			n = Convert64StrToN(line)
			if n > maxN {
				return
			}
			if PD(n) {
				primes = append(primes, n)
			}
		}
	}

	ex, _ := os.Executable()
	exPath := filepath.Dir(ex)
	filename := filepath.Join(exPath, "primes.txt")

	ReadPrimes(filename, N)

	return primes
}

func MaxInt( a, b int ) int {
	return int(MaxInt64( int64(a), int64(b) ))
}

func MaxInt64( a, b int64 ) int64 {
	if a > b { return a }
	return b
}
func AbsInt64(a int64) int64 {
	if a < 0 { return -a}
	return a
}
func MaxUint64( a, b uint64 ) uint64 {
	if a > b { return a }
	return b
}

func MinInt( a, b int ) int {
	if a < b { return a }
	return b
}

func MinInt64( a, b int ) int {
	if a < b { return a }
	return b
}

func MinUint64( a, b uint64 ) uint64 {
	if a < b { return a }
	return b
}

func GcdInt2(a, b int ) int {
	if b == 0 {
		return a
	} else {
		return GcdInt2(b, a%b)
	}
}

func LcdUint64_2(a, b uint64) uint64 {
	g := GcdUInt64_2(a, b)
	return a / g * b
}

func GcdUInt64_2(a, b uint64 ) uint64 {
	if b == 0 {
		return a
	} else {
		return GcdUInt64_2(b, a%b)
	}
}

func GcdUint64_3(a, b, c uint64) uint64 {
	return LcdUint64_2(a, LcdUint64_2(b, c) )
}

func LcdUint64_3(a, b, c uint64) uint64 {
	g := GcdUInt64_2(a, b)
	return a / g * b
}

func GetDigit(n int64) int64 {
	// 몇자리 수 인가 ?
	if n < 0 {
		n = -n
	}
	if n < 10 {
		return 1
	} else {
		return GetDigit(n/10) + 1
	}
}

func PowInt64(n, p int64 ) int64{
	// n^p
	switch p {
	case 0: return 1
	case 1: return n
	default:
		if p % 2 == 0 {
			ret := PowInt64(n, p/2)
			return ret*ret
		} else {
			ret := PowInt64(n, p-1)
			return ret * n
		}
	}
}

func PowInt64_Mod(n, p, m int64 ) int64{
	// n^p
	switch p {
	case 0: return 1 % m
	case 1: return n % m
	default:
		if p % 2 == 0 {
			ret := PowInt64_Mod(n, p/2, m) % m
			return (ret * ret) % m
		} else {
			ret := PowInt64_Mod(n, p-1, m) % m
			return (ret * n) % m
		}
	}
}

func PowUInt64_Mod(n, p, m uint64 ) uint64{
	// n^p
	switch p {
	case 0: return 1 % m
	case 1: return n % m
	default:
		if p % 2 == 0 {
			ret := PowUInt64_Mod(n, p/2, m) % m
			return (ret * ret) % m
		} else {
			ret := PowUInt64_Mod(n, p-1, m) % m
			return (ret * n) % m
		}
	}
}
func GetDivisorCount(primes []int, n int) int {
	var ret, r, i int
	var length = len(primes)
	ret = 1

	for i = 0 ; i < length && primes[i] * primes[i] <= n ; i ++ {
		if n % primes[i] != 0 { continue }
		r = 1
		for n >= primes[i] && n % primes[i] == 0 {
			r += 1
			n /= primes[i]
		}
		ret = ret * r
	}

	return ret
}


func GetDivisorCountSquare(primes []int, n int) int {
	var ret, r, i int
	var length = len(primes)
	ret = 1

	for i = 0 ; i < length && primes[i] <= n ; i ++ {
		if n % primes[i] != 0 { continue }
		r = 1
		for n >= primes[i] && n % primes[i] == 0 {
			r += 2
			n /= primes[i]
		}
		ret = ret * r
	}

	return ret
}
