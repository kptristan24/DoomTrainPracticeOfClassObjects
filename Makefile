all:
	g++ final.cpp -o prog
doomtrain:
	g++ final.cpp -o prog
	./prog
clean:
	rm prog *.out
