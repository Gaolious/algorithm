package main
//
// func sum(args ...int) int {
// 	var ret int
// 	ret = 0
// 	for _, n := range args {
// 		ret += n
// 	}
// 	return ret
// }
// func min(args ...int) int {
// 	var ret int
// 	var first bool
// 	first = true
// 	for _, n := range args {
// 		if first || ret > n {
// 			ret, first = n, false
// 		}
// 	}
// 	return ret
// }
//
// func max(args ...int) int {
// 	var ret int
// 	var first bool
// 	first = true
// 	for _, n := range args {
// 		if first {
// 			ret, first = n, false
// 		} else if ret < n {
// 			ret = n
// 		}
// 	}
// 	return ret
// }
// func gcd(a, b int) int {
// 	if b > 0 {
// 		return gcd(b, a%b)
// 	} else {
// 		return a
// 	}
// }
// func abs(a int) int {
// 	if a < 0 {
// 		return -a
// 	}
// 	return a
// }
// func ceil(a, b int) int {
// 	// ceil(a/b)
// 	m := a / b
// 	if a%b != 0 {
// 		m++
// 	}
// 	return m
// }
// func ymd(y, m, d int) int {
// 	return y*10000 + m*100 + d
// }
