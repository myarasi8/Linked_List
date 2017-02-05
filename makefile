SHELL:=/bin/bash

a:
	module load gcc
	g++ -o a main_a.cpp LinkedList.cpp

b:
	module load gcc
	g++ -o b main_b.cpp

clean:
	rm a b
