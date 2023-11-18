#include <iostream>
#include <string>
#include "PriorityQueue.hpp"



int main() {
    
    int T = 0;
    std::cin >> T;

    for (int i = 0; i < T; i++){
        Printer printer;

        int N = 0;
        std::cin >> N;

        for (int j = 0; j < N; j++){
            char instruction;
            std::cin >> instruction;

            if (instruction == 'I') {
                std::string id;
                std::string title;
                int priority;

                std::cin >> id >> title >> priority;

                printer.insertDoc(id, title, priority);
                

            } else if(instruction == 'P') {

                Document popped_doc = printer.topDoc();
                if (popped_doc.getPriority() != 0) {
                    std::cout << popped_doc.getId() << " " << popped_doc.getTitle() << std::endl;
                    printer.popDoc();
                }

            } else if(instruction == 'T') {
                
                Document popped_doc = printer.topDoc();

                if (popped_doc.getPriority() != 0) {
                    std::cout << popped_doc.getId() << " " << popped_doc.getTitle() << std::endl;
                }
                
            } else if (instruction == 'S') {

                std::cout << printer.sizePrinter() << std::endl;

            } else if (instruction == 'E') {

                std::cout << printer.emptyPrinter() << std::endl;

            }
            
        }

        // Need to print M-th Document 
        int M = 0;
        std::cin >> M;
        // breadth traversal로 M 번째 찾으면 되지 않을까?
        if (M > printer.sizePrinter()) {
            std::cout<<"M > printer.size()"<<std::endl;

            break;
        } else {
            printer.heapSort(printer, printer.sizePrinter());
            for (int k = 0; k < M-1; k++) {
                printer.popDoc();
            }
            std::cout << printer.topDoc().getId() << " "<< printer.topDoc().getTitle() << std::endl;
        }
    }

    //test cases가 뜻하는 것이 무엇일까?

    //우선순위가 0인 document 받으면 프린트하지 않도록. 
}

