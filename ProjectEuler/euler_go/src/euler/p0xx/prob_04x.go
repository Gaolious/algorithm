package p0xx

import (
	"euler/utils"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

func find_ndigit(n int64) int {
	const MAX_DIGIT = 10

	var POW10 [MAX_DIGIT + 1 ] int64

	var ten, digits int64
	var i int64
	var number string

	if n < 10 {
		return int(n)
	}
	ten = 1
	for digits = 0 ; digits <= MAX_DIGIT ; digits ++ {
		POW10[digits] = ten
		ten = ten * 10
	}

	for digits = 1 ; digits <= MAX_DIGIT ; digits ++ {
		cnt := POW10[digits-1] * digits * 9
		if n <= cnt {
			break
		} else {
			n -= cnt
		}
	}

	var t int64
	for i = digits ; i > 0 ; i -- {
		if n <= digits-i {
			t = 0
		} else {
			t = ( n - 1 ) / (digits * POW10[i - 1])
			n -= t * ( digits * POW10[i - 1])
		}
 		if i == digits { t ++ }
		number += fmt.Sprintf("%d", t)
	}

	return int( number[ n-1 ] - '0' )
}
func P40() int {
	var s, i int
	s = 1
	for i = 1 ; i <= 1000000 ; i *= 10 {
		s = s * find_ndigit( int64(i) )
	}
	return s
}

func P41() int {
	primes := utils.GetPrimes(987654321)
	length := len(primes)
	var is = func (n int) bool {
		var check [10]byte
		var cnt int
		for n > 0 {
			if check[ n % 10 ] == 1 { return false }
			check[ n % 10 ] = 1
			n /= 10
			cnt ++
		}
		if check[0] == 1 { return false }
		for i := 1 ; i <= cnt ; i ++ {
			if check[i] == 0 { return false }
		}
		for i := cnt + 1 ; i <= 9 ; i ++ {
			if check[i] == 1 { return false }
		}
		return true
	}

	for i := length - 1 ; i >= 0 ; i -- {
		if is(primes[i]) {
			return primes[i]
		}
	}
	return 0
}

func P42() int {
	var i, j int
	var buffer = make([]byte, 50000)
	var names = make([]string, 0, 50000)
	fin, _ := os.Open("src/euler/p0xx/p42.in")
	defer fin.Close()

	n, _ := fin.Read(buffer)
	for i = 0 ; i < n ; i ++ {
		if buffer[i] == '"' {
			for j = i + 1 ; j < n && buffer[j] != '"' ; j ++ {}
			names = append(names, string( buffer[i+1:j]))
			i = j
		}
	}
	var F = func(s string) int {
		var ret int
		for Loop1 := 0 ; Loop1 < len(s) ; Loop1 ++ {
			ret += int(s[Loop1] - 'A' + 1)
		}
		return ret
	}
	var is = func(n int) bool {
		for i = 1 ; i * ( i + 1 ) <= n * 2 ; i ++ {
			if i * ( i + 1 ) / 2 == n {
				return true
			}
		}
		return false
	}
	var cnt int
	for _, s := range names {
		v := F(s)
		if is(v) {
			cnt++
		}
	}
	return cnt
}

func P43() int {
	type DATA struct {
		N int
		List []int
	}
	var D = []DATA {
		{N:2, List: make([]int, 0)},
		{N:3, List: make([]int, 0)},
		{N:5, List: make([]int, 0)},
		{N:7, List: make([]int, 0)},
		{N:11, List: make([]int, 0)},
		{N:13, List: make([]int, 0)},
		{N:17, List: make([]int, 0)},
	}
	var i, j int
	for i = 0 ; i < len(D) ; i ++ {
		for j = D[i].N ; j < 1000 ; j += D[i].N {
			if (j/1) % 10 == (j/10) % 10 { continue }
			if (j/1) % 10 == (j/100) % 10 { continue }
			if (j/10) % 10 == (j/100) % 10 { continue }
			D[i].List = append(D[i].List, j)
		}
	}
	var check [10]byte
	var data = make([]byte, 10)
	var Find func(idx, prevVal int )
	var ret int
	Find = func(idx, prevVal int ) {
		if idx < 0 {
			for i := 0 ; i < 10 ; i ++ {
				if check[i] == 0 {
					data[0] = byte('0' + i)
					break
				}
			}
			fmt.Printf("%s\n", string(data))
			t, _ := strconv.Atoi(string(data))
			ret += t
			return
		}
		for i := 0 ; i < len(D[idx].List) ; i ++ {
			if check [ (D[idx].List[i]/100)%10 ] == 1 { continue }

			if D[idx].List[i] % 100 == prevVal/10 {
				data[idx+1] = byte('0' + (D[idx].List[i]/100)%10)
				check [ (D[idx].List[i]/100)%10 ] = 1
				Find(idx-1, D[idx].List[i])
				check [ (D[idx].List[i]/100)%10 ] = 0
			}
		}
	}
	for i = 0 ; i < len(D[6].List) ; i ++ {
		check [ (D[6].List[i]/1)%10 ] = 1
		check [ (D[6].List[i]/10)%10 ] = 1
		check [ (D[6].List[i]/100)%10 ] = 1
		data[9] = byte('0' + (D[6].List[i]/1)%10)
		data[8] = byte('0' + (D[6].List[i]/10)%10)
		data[7] = byte('0' + (D[6].List[i]/100)%10)
		Find(5, D[6].List[i])

		check [ (D[6].List[i]/1)%10 ] = 0
		check [ (D[6].List[i]/10)%10 ] = 0
		check [ (D[6].List[i]/100)%10 ] = 0
	}
	return ret
}

func P45() int {
	type DATA struct {
		N int
		V int
		F func(n int) int
	}
	var d = []DATA {
		{N:1, V:1, F: func(n int ) int { return n * ( n + 1 ) / 2 }},
		{N:1, V:1, F: func(n int ) int { return n * ( 3*n - 1 ) / 2}},
		{N:1, V:1, F: func(n int ) int { return n * ( 2*n - 1 )}},
	}

	for {
		sort.Slice(d, func(i, j int) bool { return d[i].V < d[j].V })
		if d[0].V == d[1].V && d[1].V == d[2].V && d[0].V > 40755 {
			break
		}
		d[0].N++
		d[0].V = d[0].F( d[0].N )
	}
	return d[0].V
}
func P44() int {
	var i int
	var Has = func(a int) bool {
		// P(n) = n * ( 3*n - 1 ) / 2 = a
		// 3n^2 - n = 2a
		// 36n^2 - 12n = 24a
		// (6n-1)^2 = 24a + 1
		// n = 1/6 * [ sqrt(24a + 1) + 1 ]
		fv := math.Sqrt( float64(a) * 24 + 1 )
		iv := int(fv + 0.5)
		if iv * iv != a * 24 + 1 { return false }
		if (iv + 1) % 6 != 0 { return false }
		return true
	}
	var P = func(n int) int {
		return n * ( 3 * n - 1 ) / 2
	}
	var minDiff = -1
	var a, b int
	for i = 1 ; i < 100000000 ; i ++ {
		a = P(i)
		for j := i - 1 ; j > 0 ; j -- {
			b = P(j)
			if Has( a+b ) && Has( a - b) {
				if minDiff < 0 || a - b < minDiff {
					minDiff = a - b
				}
			}
			if minDiff > 0 && a - b > minDiff {
				break
			}
		}
	}

	return minDiff
}
func P46() int {
	var Primes = utils.GetPrimes(100000)
	var isPrime = func (n int) bool {
		l, r := 0, len(Primes)-1
		for l <= r {
			m := (l+r)/2
			if Primes[m] == n {
				return true
			} else if Primes[m] < n {
				l = m + 1
			} else {
				r = m - 1
			}
		}
		return false
	}

	var i, primeIdx int
	var j int

	for i = 9 ; ; i += 2 {
		for ; Primes[primeIdx] < i ; primeIdx++ {}
		if Primes[primeIdx] == i { continue }

		found := false
		for j = 1 ; i - j*j+2 >= 2 ; j ++ {
			if isPrime(i - 2*j*j) {
				found = true
				break
			}
		}
		if !found {
			return i
		}
	}
}
func P47() int {
	var Primes = utils.GetPrimes(1000)
	var D [200000]int
	var i, j int

	for i = 0 ; i < len(Primes) ; i ++ {
		for j = 1 ; Primes[i] * j < len(D) ; j ++ {
			D[ Primes[i] * j ] ++
		}
	}
	for i = 3 ; i < len(D) ; i ++ {
		if D[i-3] == 4 && D[i-2] == 4 && D[i-1] == 4 && D[i] == 4 {
			return i-3
		}
	}
	return -1
}
func P48() uint64 {
	var i, j, s, t uint64
	var MOD uint64

	MOD = 10_000_000_000
	for i = 1 ; i <= 1000 ; i ++ {
		t = 1
		for j = 1 ; j <= i ; j ++ {
			t = ( t * i ) % MOD
		}
		s = ( s + t ) % MOD
	}
	return s
}
func P49() uint64 {
	var Primes = utils.GetPrimes(9999)
	var i, j int
	var check[10000] byte
	for i = 0 ; i < len(Primes) ; i ++ {
		check[Primes[i]] = 1
	}
	var getCheck = func(n int) [10]byte {
		var ret [10]byte
		for n > 0 {
			ret[ n % 10 ]++
			n /= 10
		}
		return ret
	}

	for i = 0 ; i < len(Primes) ; i ++ {
		if Primes[i] < 1000 { continue }
		cI := getCheck(Primes[i])

		for j = i + 1 ; j < len(Primes) ; j ++ {
			k := Primes[j] * 2 - Primes[i]
			if k >= 10000 { break }
			if check[k] == 0 { continue }

			cJ := getCheck(Primes[j])
			cK := getCheck(k)

			if cI != cJ { continue }
			if cK != cJ { continue }

			fmt.Printf("%04d %04d %04d\n", Primes[i], Primes[j], k)
		}
	}
	return 0
}