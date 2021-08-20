package main

import "fmt"

func problem_1 () {
	// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	// Find the sum of all the multiples of 3 or 5 below 1000.
	N := 1000
	F := func(val int ) int {
		cnt := (N-1) / val ;

		return cnt * ( cnt + 1 ) / 2 * val
	}
	fmt.Printf("problem 1 : %d\n", F(3) + F(5) - F(15))
}

func problem_2() {
	var a, b, c, s int64
	a = 1
	b = 2
	s = 2
	for b <= 4000000 {
		c = a + b
		if c % 2 == 0 {
			s += c
		}
		a = b
		b = c
	}
	fmt.Printf("problem 2 : %d\n", s)
}

func problem_9(){
	var m, n int
	var a, b, c int

	for m = 1 ; m*m <= 500 ; m ++ {
		for n = 1 ; 500 % m == 0 && m * ( m + n ) <= 500 ; n ++ {
			if m <= n { continue}
			if m*m + m*n != 500 { continue }
			fmt.Printf("m=%d, n=%d\n", m, n);

			a = m*m - n*n
			b = 2 * m * n
			c = m*m + n*n
			fmt.Printf("a=%d, b=%d, c=%d\n", a, b, c)
			fmt.Printf("%d + %d = %d == %d\n", a*a, b*b, a*a+b*b, c*c)

			fmt.Printf("problem 9 : %d\n", a*b*c);
		}

//		a = m - n
//		b = 2 * m * n/
//		c = m + n
//		if a >= b || b >= c || a >=c {
//			//continue
//		}
//		fmt.Print(a, b, c, "\n")
	}
}