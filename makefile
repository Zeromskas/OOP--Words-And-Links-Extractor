CPPFLAGS = -O3 -std=c++20

main: clean
	g++ $(CPPFLAGS) main.cpp -o main
	./main
	make clean

clean:
	rm -f main *.o