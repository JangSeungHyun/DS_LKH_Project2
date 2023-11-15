#include "PriorityQueue.hpp"
#include <iostream>

// Part 1: Basic operations of priority queue (40 pts)
PriorityQueue::PriorityQueue(int direction) {   // Constructor.
    // TO-DO

    // 초기에 direction이 1, -1이 아닌 경우를 걸러내는 작업 필요할 듯
    
    // heap_size 멤버변수는 처음에 0으로 초기화하고 연산마다 트래킹하는게 좋을까? 아니면 필요할 때마다 vector의 메서드를 이용하여 구하는 것이 좋을까?
    // 후자가 안정적이라고 생각. 하지만 원하는 것은 전자 같음.
    
}


PriorityQueue::~PriorityQueue() {   // Destructor.
    // TO-DO
    // PriorityQueue에서 동적으로 할당된 요소는 없는데 무엇을 삭제해줘야 할까? - 명시적으로 해주어야 할 것은 없는 듯 한데,,,
}


void PriorityQueue::swapPQ(int idx1, int idx2) {    // Swaps the elements at the specified indices in the heap.
    // TO-DO
    // idx1과 idx2에 있는 elements를 swap하는 함수
    // heap property를 유지하기 위한 heap operations 도중에 종종 사용된다. --> upHeap, downHeap을 의미하는 듯

    // 벡터의 두 원소를 교환합니다.
    if (idx1 < heap_size && idx2 < heap_size) {
        
    } else if (idx1 > heap.size()) {

    } else if (idx1 > heap.size()) {

    } else {
        std::cerr << " << std::endl;
    }

    return 0;
}


void PriorityQueue::upHeap(int idx) {   // Adjust the heap by moving the specified element upwards.
    // TO-DO
    // idx에 있는 element를 parent의 priority가 높을 때까지 위로 이동시키는 메서드
    // 주로 insert operation 이후에 호출된다고 함
    // 현재 insert operation에서 upHeap 부분까지 수행하고 있음. array implementation이기 때문에 pointer로 조정하지는 않음
    // 기존에 구현한 방식을 어떻게 잘 이용할 수 있을까? - "swapPQ" 메서드도 todo로 있는 것을 보면 hole을 비워두고 이동시키는 것이 아니라 값의 swap을 원하는 듯 하다.
    // for 부문 + index 0 move 부분만을 떼오면 되나? -> for 부문의 조건 판단은 그대로 이용하되 swapPQ를 활용할 예정
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

    return ;

    // 만약 Heap의 끝자락에 붙이는 기능만 구현할 것이라면?
    // First, Check if we can use only one space.
    if (heap_size == heap.size() - 1) {
        heap.resize(heap.size() * 2);
    }

    // define new node
    int new_element_idx = ++heap_size;
    int copy_e = e;

    // enqueue part
    heap.push_back(e);
}


int PriorityQueue::popHeap() {  // Pop its top entry. If the queue is empty, then print "Empty queue.".
    // TO-DO
    // queue에서 highest priority를 가진 element를 pop하는 함수 - index 1에 있는 element를 pop하고 이후에 앞으로 하나씩 땡겨와야 하나?
    // runtime이 많이 들어갈 것 같은데 여기서 circular array의 개념을 도입한다면?
    if (emptyHeap()) {

    }
}


int PriorityQueue::topHeap() const {    // Return its top entry. If the queue is empty, then print "Empty queue.".
    // TO-DO
    // heap의 top entry는 tree 모형의 root이고 이는 heap의 1번 인덱스에 위치
    if(emptyHeap()) {
        std::cout << "Empty queue." << std::endl;
        return 0;
    }
    return heap[1];
}


int PriorityQueue::sizeHeap() const {   // Return size of queue.
    // TO-DO
    // 여기서 원하는 size는 현재 heap에 저장되어 있는 elements의 수
    // 여기서 트래킹한 변수를 보낼 것인지, 아니면 계산할 것인지 선택해야 할 듯 -> 후자가 안정적이라고 생각. 메서드마다 heap_size를 수정하는 것은 쉽지 않다. 
    // 하지만 그렇다면 heap_size 멤버변수는 무엇을 위한 것이지? 원하는 바는 직접 트래킹하고 operation 별로 수정하는 것을 원하는 듯 하다.
    return heap_size;
}


bool PriorityQueue::emptyHeap() const { // Check if the queue is empty. `1` for empty queue.
    // TO-DO
    // 어떻게 queue가 비었는지 확인할 수 있을까? - 
    if(heap_size == 0) {

    }
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