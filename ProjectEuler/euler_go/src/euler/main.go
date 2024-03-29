package main

import (
	"euler/io"
	"euler/p6xx"
	"fmt"
	"time"
)

func main() {
	defer finish()
	ret := p6xx.P684()
	fmt.Println("Answer : ", ret )
}

func init() {
	startTime = time.Now()
}

var startTime time.Time
var elapsedTime time.Duration
func finish() {
	io.End()
	elapsedTime = time.Since(startTime)
	fmt.Printf("elapsedTime: %f seconds.\n", elapsedTime.Seconds())
}
