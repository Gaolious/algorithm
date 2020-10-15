 
# STDIN Benchmark for C/C++
`출력을 제외`한 표준 입력에서 `정수 입력` 과 관련하여 각 함수별 속도 비교

## 입력

- 첫 줄에 자연수 N (=300,000,000)
- 두번째 줄 부터 N+1 번째 줄까지 자연수 N개가 주어짐.
(함수 generate 참고)

## 테스트

- 3억개의 데이터를 읽는 속도를 101회 테스트
- 단, 특정 시간대에 max값이 몰려 있어서 2번의 test 차수를 삭제 함.

### Source
- `src/src.cpp`

### Compile
```bash
$ gcc --version
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ gcc -lm -lcrypt -O3 -std=c++11 -pipe src/src.cpp -o bin/UVA

# 입력 데이터 생성
$ ./bin/UVA -1 > input/input.txt
```

### Test
```bash
#!/bin/bash

BIN=./bin/UVA
IN=./input/input.txt
REPEAT=100

for idx in `seq 0 12`
do
	[ -f ./output_${idx}.txt ] && rm -rf ./output_${idx}.txt
done

for r in `seq 0 $REPEAT`
do	
	for idx in `seq 0 12`
	do	
		echo ""
		echo "[`date`] idx=$idx / Repeat : $r "

		s=`/bin/date +"%s.%N"`
		$BIN $idx < $IN
		e=`/bin/date +"%s.%N"`
		t=$( echo "$e - $s" | bc )
		echo "$t" >> ./output/output_${idx}.txt
	done
done

```

## 결과 
- 1위 : mmap
- 2위 : 1위와 거의 비슷한 read/fread
- 3위 : read/fread와 약간의 차이가 나는 getchar/getc/fgetc
- 4위 : mmap대비 약 8배 차이가 나는 scanf/fscanf/cin(sync_studio=false)
- 5위 : cin

| | scanf | fscanf | getchar | getc | fgetc | read | fread | fread(setbuf) | mmap | cin | cin(sync_studio=false) | cin(sync_studio=false, tie=null) | cin(tie=null)
|--:|--:|--:|--:|--:|--:|--:|--:|--:|--:|--:|--:|--:|--:|
RANK | 10 | 11 | 7 | 6 | 5 | 2 | 3 | 4 | 1 | 13 | 9 | 8 | 12
RUNs | 99 | 99 | 99 | 99 | 99 | 99 | 99 | 99 | 99 | 99 | 99 | 99 | 99
AVG | 19.197807 | 19.337918 | 4.344876 | 4.210954 | 4.139443 | 2.749011 | 2.759442 | 2.759605 | 2.438443 | 37.022340 | 16.172294 | 15.722102 | 34.239831
STD | 0.143990 | 0.137324 | 0.017288 | 0.039913 | 0.030239 | 0.013412 | 0.019817 | 0.022413 | 0.007444 | 0.920965 | 0.098607 | 0.085265 | 0.336654
MIN | 19.077663 | 19.212073 | 4.328532 | 4.186755 | 4.119828 | 2.740236 | 2.748117 | 2.749555 | 2.430122 | 36.618240 | 16.093704 | 15.566273 | 34.051221
MAX | 20.046244 | 20.182420 | 4.437444 | 4.425462 | 4.268344 | 2.835945 | 2.892102 | 2.942405 | 2.480686 | 41.356617 | 16.673058 | 16.096288 | 36.143189

<br/>

### 각 함수별 평균 수행속도

<image src=./result/chart1.png>

### 테스트 차수별 함수들의 수행 속도

<image src=./result/chart2.png>


