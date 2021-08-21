package main

import (
	"euler/io"
	"euler/p0xx"
	"fmt"
	"time"
)

func main() {
	defer finish()

	ret := p0xx.P87()
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