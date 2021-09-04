package p0xx

import (
	"euler/utils"
	"fmt"
	"math"
	"math/big"
	"os"
	"sort"
)

func P20() int {
	b0 := big.NewInt(0)
	ret := big.NewInt(1)
	for i := 100 ; i > 0 ; i -- {
		ret = b0.Mul( big.NewInt( int64(i) ), ret)
	}
	s := ret.Text(10)
	sum := 0
	for _, v := range s {
		sum += int(v - '0')
	}
	return sum
}

func P21() int {
	var D [10000 + 1]int
	var i, j int
	var s int

	for i = 1 ; i <= 10000 ; i ++ {
		for j = 1 ; j < i ; j ++ {
			if i % j == 0 {
				D[ i ] += j
			}
		}
	}
	for i = 1 ; i <= 10000 ; i ++ {
		if D[ i ] <= 10000 && D[ i ] != i && D[ D[i] ] == i {
			s += i
		}
	}
	return s
}

func P22() uint64 {
	var buffer = make([]byte, 50000)
	var names = make([]string, 0, 50000)
	var i, j int
	var ret uint64
	fin, _ := os.Open("src/euler/p0xx/p22.in")
	defer fin.Close()

	n, _ := fin.Read(buffer)
	for i = 0 ; i < n ; i ++ {
		if buffer[i] == '"' {
			for j = i + 1 ; j < n && buffer[j] != '"' ; j ++ {}
			names = append(names, string( buffer[i+1:j]))
			i = j
		}
	}

	sort.Strings(names)
	for idx, name := range names {
		var s int
		for i = len(name) - 1 ; i >= 0 ; i -- {
			if name[i] >= 'A' {
				s += int(name[i] - 'A' + 1)
			} else {
				s += int(name[ i ] - 'a' + 1)
			}
		}
		ret += uint64( (idx + 1 ) * s )
	}
	return ret
}

func P23() int {
	// var primes = utils.GetPrimes(30000)
	var S = func(n int ) int {
		var ret int

		for i := 2 ; i * i <= n ; i ++ {
			if n % i == 0 {
				if i * i == n {
					ret += i
				} else {
					ret += i + (n/i)
				}
			}
		}
		return ret + 1
	}
	var numbers = make([]int, 0)
	var i int
	var find_number = func(n int) bool {
		var l, r int
		l = 0
		r = len(numbers) - 1
		for l <= r {
			if numbers[l] + numbers[r] == n {
				return true
			} else if numbers[l] + numbers[r] < n {
				l++
			} else {
				r--
			}
		}
		return false
	}
	for i = 2 ; i < 30000 ; i ++ {
		number := S(i)
		if i < number {
			numbers = append(numbers, i)
		}
	}

	var s int
	for i = 1 ; i < 30000 ; i ++  {
		if !find_number(i) {
			fmt.Println(i)
			s += i
		}
	}
	return s
}

func P24() string {
	var F = func(n int) int {
		ret := 1
		for i := 2 ; i <= n ; i ++ {
			ret *= i
		}
		return ret
	}
	var check = make([]bool, 10)
	var result = make([]byte, 10)
	var total = 10
	var nth = 1000000
	var i int
	var factorial int

	for idx := 0 ; idx < total ; idx ++ {
		factorial = F(total-idx-1)

		for i = 0 ; i < 10 ; i ++ {
			if check[i] {
				continue
			}
			if factorial < nth {
				nth -= factorial
				continue
			}
			result[ idx ] = byte( '0' + i )
			check[i] = true
			break
		}
	}
	return string(result)
}

func P25() int {
	// F(n) ~ 1 / sqrt(5) *  [ ( (1+s5)/2 )^n ]

	// 1000Digit F(n) <= 1/sqrt(5) * [ ( (1+s5)/2 )^n ]
	// 999digit * sqrt(5) <  ( (1+s5)/2 )^n
	// 999 + log10( s5 ) < n * log10( (1+s5)/2 )

	var s5 = math.Sqrt(5.0)
	var p = ( 1.0 + s5 ) / 2.0

	var n = ( math.Log10(s5) + 999 ) / math.Log10(p)

	return int( math.Ceil(n) )
}

func P26() int {
	var i, max_n int
	var max_cnt, cnt int
	var L = func(n int) int {
		var t, repeat int
		var check = make([]int, 10001)

		for n % 10 == 0 {
			n /= 10
		}

		t = 1
		repeat = 1
		check[t] = repeat
		for t != 0 {
			t *= 10
			repeat ++
			if t > n {
				t %= n
			}

			if check[t] != 0 {
				return repeat - check[t]
			}
			check[t] = repeat
		}
		return 0
	}

	for i = 2 ; i <= 1000 ; i ++ {
		cnt = L(i)
		if cnt > max_cnt {
			max_cnt = cnt
			max_n = i
			fmt.Printf("Number : %d (count:%d)\n", max_n, max_cnt)
		}
	}
	return max_n
}

func P27() int {
	var primes = utils.GetPrimes(1000000)
	var isPrime = func(n int) bool {
		var i int
		if n < 2 {
			return false
		}
		for i = 0 ; primes[i] * primes[i] <= n && i < len(primes) ; i ++ {
			if n % primes[i] == 0 {
				return false
			}
		}
		if i == len(primes) && primes[i] * primes[i] < n {
			panic("over")
		}
		return true
	}
	var findPrimes = func(a, b int) int {
		var ret int

		for i := 0 ; isPrime( i*i + i*a + b) ; i ++ {
			ret ++
		}
		return ret
	}

	var max_cnt, A, B int

	for a := -999 ; a <= 999 ; a ++ {
		for b := -999 ; b <= 999 ; b ++ {
			cnt := findPrimes(a, b)
			if cnt > max_cnt {
				max_cnt = cnt
				A = a
				B = b
				fmt.Printf("n^2 + %d*n + %d => count : %d\n", A, B, max_cnt)
			}
		}
	}
	return A*B
}

func P28() uint64 {

	var ret uint64
	var i uint64
	var n uint64

	for i = 1 ; i <= 500 ; i ++ {
		n = 2 * i + 1
		ret += 4 * n * n - 6 * (n-1)
	}

	return ret + 1
}

func P29() int {
	var primes = utils.GetPrimes(150)
	type DATA struct {
		N [25]int
	}
	var data_list = make([]DATA, 0)

	var a, b, n, i, j int
	var found, diff bool

	for a = 2 ; a <= 100 ; a ++ {
		d := DATA{}
		n = a
		for i = 0 ; primes[i] <= n && i < 25 ; i ++ {
			for n % primes[i] == 0 {
				d.N[i]++
				n /= primes[i]
			}
		}

		for b = 2 ; b <= 100 ; b ++ {
			found = false
			for i = 0 ; i < len(data_list) ; i ++ {
				diff = false
				for j = 0 ; j < 25 ; j ++ {
					if data_list[i].N[j] != d.N[j] * b {
						diff = true
						break
					}
				}
				if diff == false {
					found = true
					break
				}
			}

			if found == false {
				data_list = append(data_list, d)
				for j = 0 ; j < 25 ; j ++ {
					data_list[len(data_list)-1].N[j] *= b
				}
			}
		}
	}
	return len(data_list)
}
