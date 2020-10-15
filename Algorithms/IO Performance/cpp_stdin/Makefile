CC = g++
CFLAGS = -g  -lm -lcrypt -O3 -std=c++11 -pipe -Wno-unused-result -DONLINE_JUDGE
# CFLAGS = -g  -lm -lcrypt -O0 -std=c++11 -pipe -Wno-unused-result -DONLINE_JUDGE -DAJAVA_DEBUG
LDFLAGS =
LIBS = 
TARGET = ./bin/UVA
.SUFFIXES : .cpp .c .o 

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

$(TARGET): $(OBJ)
	[ -d bin ] || mkdir -p bin
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(OBJ) -o $(TARGET)
	echo "Complete"

obj/%.o: src/%.cpp
	[ -d obj ] || mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET) core bin obj
