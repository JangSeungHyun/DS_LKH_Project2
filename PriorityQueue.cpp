#include "PriorityQueue.hpp"
#include <iostream>

// Part 1: Basic operations of priority queue (40 pts)
PriorityQueue::PriorityQueue(int direction) {   // Constructor.
    // TO-DO

    // 초기에 direction이 1, -1이 아닌 경우를 걸러내는 작업 필요할 듯
}


PriorityQueue::~PriorityQueue() {   // Destructor.
    // TO-DO
}


void PriorityQueue::swapPQ(int idx1, int idx2) {    // Swaps the elements at the specified indices in the heap.
    // TO-DO
}


void PriorityQueue::upHeap(int idx) {   // Adjust the heap by moving the specified element upwards.
    // TO-DO
}


void PriorityQueue::downHeap(int idx) { // Adjust the heap by moving the specified element downwards.
    // TO-DO
}


void PriorityQueue::insertHeap(int e) { // Insert a new entry to the queue.
    // TO-DO

    // First, Check if we can use only one space.
    if (heap_size == heap.size() - 1) {
        heap.resize(heap.size() * 2);
    }

    // Percolate up hole
    // hole의 인덱스는 제일 큰 수부터 시작 -> tree의 아랫쪽부터 시작
    // heap_size는 현재 priority queue에 있는 element의 수
    int hole = ++heap_size;
    int copy = e;

    // heap[0]에는 root가 있지 않나? -> ㄴㄴ. 인덱스 0은 비어있음
    // 그럼 우선 집어넣을 integer를 array의 비어있는 곳에 집어놓고
    heap[0] = std::move(copy);
    // perfect binary tree의 array implementation에서 부모노드는 자식노드 인덱스의 절반을 가짐을 이용. -> 부모노드가 현재 insertion 대상값보다 클 때까지 반복(max heap?)
    // 실행할 반복문을 member variables, "direction"을 이용하여 판단해야 함.
    if (direction == 1) {
        // min heap!
        // hole을 올려보내면서(부모 노드에 있는 값을 hole로 move 시키면서)
        // 따라서 부모노드가 현재 갖고 올라가는 값보다 클 때까지만 반복문을 실행해야 함.
        for ( ; e < heap[hole / 2]; hole /= 2) {
            // 부모노드에 있는 값을 hole의 위치로 보냄 -> 자연스럽게 부모노드가 hole의 역할을 하게 됨.
            heap[hole] = std::move(heap[ hole / 2 ]);
        }
        // 왜 하는 거지? - 위에서 비어있는 array의 자리에 집어넣었던 insertion 대상을 move 시켜주는 작업
        heap[hole] = std::move(heap[0]);

    } else if(direction == -1) {
        // max heap!
        // 부모노드가 현재 갖고 올라가는 값보다 작을 때까지만 반복문을 실행할 것
        for ( ; e > heap[hole / 2]; hole /= 2) {
            heap[hole] = std::move(heap[ hole / 2 ]);
        }
        // 왜 하는 거지? - 위에서 비어있는 array의 자리에 집어넣었던 insertion 대상을 move 시켜주는 작업
        heap[hole] = std::move(heap[0]);
    } else {
        // 둘 다 아니라면? 리턴?
    }
    
}


int PriorityQueue::popHeap() {  // Pop its top entry. If the queue is empty, then print "Empty queue.".
    // TO-DO
}


int PriorityQueue::topHeap() const {    // Return its top entry. If the queue is empty, then print "Empty queue.".
    // TO-DO
}


int PriorityQueue::sizeHeap() const {   // Return size of queue.
    // TO-DO
}


bool PriorityQueue::emptyHeap() const { // Check if the queue is empty. `1` for empty queue.
    // TO-DO
}



// Part 2: Document printer implementation with priority queue (60 pts)
Document::Document(std::string id, std::string title, int priority) {   // Constructor.
    // TO-DO
}


std::string Document::getId() const {   // Getter.
    // TO-DO
}


std::string Document::getTitle() const {    // Getter.
    // TO-DO
}


int Document::getPriority() const { // Getter.
    // TO-DO
}


Printer::Printer() {    // Constructor.
    // TO-DO
}


Printer::~Printer() {   // Destructor.
    // TO-DO
}


void Printer::swapDoc(int idx1, int idx2) { // Swaps the elements at the specified indices in the printer.
    // TO-DO
}


void Printer::upHeap(int idx) { // Adjust the heap by moving the specified element upwards.
    // TO-DO
}


void Printer::downHeap(int idx) {   // Adjust the heap by moving the specified element downwards.
    // TO-DO
}


void Printer::insertDoc(std::string id, std::string title, int priority) {  // Insert a new doc. (modifiable)
    // TO-DO
}


void Printer::popDoc() {    // Pop its top doc. (modifiable)
    // TO-DO
}


Document Printer::topDoc() const {  // Returns the document with the highest priority.
    // TO-DO
}


int Printer::sizePrinter() const {  // Returns the size of the queue.
    // TO-DO
}


bool Printer::emptyPrinter() const {    // Check if the queue is empty. `1` for empty queue.
    // TO-DO
}