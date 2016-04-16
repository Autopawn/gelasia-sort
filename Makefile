clean:
	rm -rf build 2> /dev/null || true
	mkdir build
compile: clean
	gcc src/*.c -std=c11 -lm -Wall -Werror -o build/gelasia_sort.out -D INTEGER_TYPE=int -D NDEBUG
compile_cpp: clean
	g++ src/*.c -std=c++11 -lm -Wall -Werror -o build/gelasia_sort.out -D INTEGER_TYPE=int -D NDEBUG -D INCPP
run: compile_cpp
	./build/gelasia_sort.out
