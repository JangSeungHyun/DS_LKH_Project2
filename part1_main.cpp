#include <iostream>
#include "PriorityQueue.hpp"

int main() {

    // direction을 받는 파트
    int d = 0;
    std::cin >> d;

    // Part of Constructing PQ
    PriorityQueue pq(d);

    // N을 input으로 받는 파트
    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        char instruction;
        std::cin >> instruction;
        if (instruction == 'I') {
            int priority;
            std::cin >> priority;

            pq.insertHeap(priority);
        }

        else if (instruction == 'P') {
            
            int popped_element = pq.popHeap();
            
            if (popped_element != 0){
                std::cout << popped_element << std::endl;
            }
        }

        else if (instruction == 'T') {

            std::cout << pq.topHeap() << std::endl;

        }

        else if (instruction == 'S') {

            std::cout << pq.sizeHeap() << std::endl;

        }

        else if (instruction == 'E') {

            if (pq.emptyHeap()) {
                std::cout << 1 << std::endl;
            } else {
                std::cout << 0 << std::endl;
            }

        }

    }



}