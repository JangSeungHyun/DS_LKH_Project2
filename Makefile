CC = g++-11 --std=c++17
RD = rm -f
PriorityQueue.o: PriorityQueue.hpp PriorityQueue.cpp
	$(CC) -c PriorityQueue.cpp

part1_main.o: part1_main.cpp PriorityQueue.hpp
	$(CC) -c part1_main.cpp

part1_main.out: PriorityQueue.o part1_main.o
	$(CC) PriorityQueue.o part1_main.o -o part1_main.out

part2_main.o: part2_main.cpp PriorityQueue.hpp
	$(CC) -c part2_main.cpp

part2_main.out: PriorityQueue.o part2_main.o
	$(CC) PriorityQueue.o part2_main.o -o part2_main.out

clean:
	$(RD) *.o
