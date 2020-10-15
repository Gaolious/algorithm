 
# STDIN Benchmark for C/C++
`출력을 제외`한 표준 입력에서 `정수 입력` 과 관련하여 각 함수별 속도 비교

## 테스트

- 3억개의 데이터를 읽는 속도를 101회 테스트
- 단, 특정 시간대에 max값이 몰려 있어서 2번의 test 차수를 삭제 함.

### Source
- `src/src.cpp`

### Input

- 첫 줄에 자연수 N (=300,000,000)
- 두번째 줄 부터 N+1 번째 줄까지 자연수 N개가 주어짐.

### Compile & generate input
```bash
$ g++ --version
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ g++ -lm -lcrypt -O3 -std=c++11 -pipe src/src.cpp -o bin/UVA

# 입력 데이터 생성 (약 1G)
$ ./bin/UVA -1 > ./input/input.txt
$ ls -al ./input
drwxr-xr-x 2 ajava ajava       4096 10월 14 23:25 .
drwxr-xr-x 9 ajava ajava       4096 10월 15 15:02 ..
-rw-r--r-- 1 ajava ajava 1169306290 10월 15 01:49 input.txt 
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

 | func | RANK | RUNs | AVG | STD | MIN | MAX
 |--:|--:|--:|--:|--:|--:|--:|
mmap | 1 | 99 | 2.438443 | 0.007444 | 2.430122 | 2.480686
read | 2 | 99 | 2.749011 | 0.013412 | 2.740236 | 2.835945
fread | 3 | 99 | 2.759442 | 0.019817 | 2.748117 | 2.892102
fread(setbuf) | 4 | 99 | 2.759605 | 0.022413 | 2.749555 | 2.942405
fgetc | 5 | 99 | 4.139443 | 0.030239 | 4.119828 | 4.268344
getc | 6 | 99 | 4.210954 | 0.039913 | 4.186755 | 4.425462
getchar | 7 | 99 | 4.344876 | 0.017288 | 4.328532 | 4.437444
cin(sync_studio=false, tie=null) | 8 | 99 | 15.722102 | 0.085265 | 15.566273 | 16.096288
cin(sync_studio=false) | 9 | 99 | 16.172294 | 0.098607 | 16.093704 | 16.673058
scanf | 10 | 99 | 19.197807 | 0.14399 | 19.077663 | 20.046244
fscanf | 11 | 99 | 19.337918 | 0.137324 | 19.212073 | 20.18242
cin(tie=null) | 12 | 99 | 34.239831 | 0.336654 | 34.051221 | 36.143189
cin | 13 | 99 | 37.02234 | 0.920965 | 36.61824 | 41.356617

<br/>

### 각 함수별 평균 수행속도

<image src=./result/chart1.png>

### 테스트 차수별 함수들의 수행 속도

<image src=./result/chart2.png>


