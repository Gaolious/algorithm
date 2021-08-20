package main

import (
	"fmt"
	"time"
)

var startTime time.Time
var elapsedTime time.Duration
func finish() {
	wr.Flush()
	elapsedTime = time.Since(startTime)
	fmt.Printf("elapsedTime: %f seconds.\n", elapsedTime.Seconds())
}
func main() {
	defer finish()

	ret := problem_17()
	fmt.Println("Answer : ", ret )

}
func init() {
	startTime = time.Now()

}