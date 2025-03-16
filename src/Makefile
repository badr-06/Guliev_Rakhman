CC = g++
CFLAGS = -Wall -Wextra -Werror

all: build

build:
	$(CC) $(CFLAGS) main.cpp -o main.out

test:
	$(CC) $(CFLAGS) test.cpp -o test.out -lgtest -lgmock -pthread

clean:
	rm *.out

clang:
	clang-format -n *.cpp *.h
	clang-format -i *.cpp *.h