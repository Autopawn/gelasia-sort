clean:
	rm -rf build 2> /dev/null || true
	mkdir build
compile: clean
	gcc src/*.c -std=c11 -lm -Wall -Werror -o build/gelasia_sort.out
run: compile
	./build/gelasia_sort.out
