#include "PriorityQueue.hpp"
#include <iostream>

// Part 1: Basic operations of priority queue (40 pts)
PriorityQueue::PriorityQueue(int direction) {   // Constructor.
    // TO-DO

    // root_index 설정 부분
    root_index = 0;
    heap_size = 0;
    // 초기에 direction이 1, -1이 아닌 경우를 걸러내는 작업 필요할 듯
    if (direction != 1 && direction != -1) {
        std::cout << "Wrong direction." << std::endl;
    }

    this->direction = direction;
    
    // heap_size 멤버변수는 처음에 0으로 초기화하고 연산마다 트래킹하는게 좋을까? 아니면 필요할 때마다 vector의 메서드를 이용하여 구하는 것이 좋을까?
    // 후자가 안정적이라고 생각. 하지만 원하는 것은 전자 같음. -> 전자로 진행
    
}


PriorityQueue::~PriorityQueue() {   // Destructor.
    // TO-DO
    // PriorityQueue에서 동적으로 할당된 요소는 없는데 무엇을 삭제해줘야 할까? - 명시적으로 해주어야 할 것은 없는 듯 한데,,,
}


void PriorityQueue::swapPQ(int idx1, int idx2) {    // Swaps the elements at the specified indices in the heap.
    // TO-DO
    // idx1과 idx2에 있는 elements를 swap하는 함수
    // heap property를 유지하기 위한 heap operations 도중에 종종 사용된다. --> upHeap, downHeap을 의미하는 듯

    // 벡터의 두 원소를 교환
    // vector의 두 elements를 교환할 때 인덱스범위 초과의 기준을 array의 크기로 잡아야할까? 아니면 현재 element가 들어있는 것을 기준으로 해야할까?
    // swapPQ가 언제 호촐되지? - heap property를 유지하기 위해서 사용됨. --> upHeap, downHeap에서 호출이 될 것 같은데 여기서는 element가 실제 array 안에 존재할 때만 swap을 하지
    // 않을까? - 우선 array안에 있는 element의 수를 기준으로 구현을 해보려고 함
    
    int temp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = temp;
    // if (idx1 < heap_size && idx2 < heap_size) {
        
    //     int temp = heap[idx1];
    //     heap[idx1] = heap[idx2];
    //     heap[idx2] = temp;

    // } else if (idx1 >= heap_size) {
        
    //     std::cout << "idx1 is out of heap range" << std::endl;


    // } else if (idx2 >= heap_size) {

    //     std::cout << "idx2 is out of heap range" << std:: endl;

    // } else {
    //     // 여기에 해당하는 상황은 없을 것 같은데?
    //     std::cout << "idx1 or idx2 is out of heap range" << std::endl;
    // }

    return ;
}


void PriorityQueue::upHeap(int idx) {   // Adjust the heap by moving the specified element upwards.
    // TO-DO
    // idx에 있는 element를 parent의 priority가 높을 때까지 위로 이동시키는 메서드
    // 주로 insert operation 이후에 호출된다고 함
    // 현재 insert operation에서 upHeap 부분까지 수행하고 있음. array implementation이기 때문에 pointer로 조정하지는 않음
    // 기존에 구현한 방식을 어떻게 잘 이용할 수 있을까? - "swapPQ" 메서드도 todo로 있는 것을 보면 hole을 비워두고 이동시키는 것이 아니라 값의 swap을 원하는 듯 하다.
    // for 부문 + index 0 move 부분만을 떼오면 되나? -> for 부문의 조건 판단은 그대로 이용하되 swapPQ를 활용할 예정

    // perfect binary tree의 array implementation에서 부모노드는 자식노드 인덱스의 절반을 가짐을 이용. -> 부모노드가 현재 insertion 대상값보다 클 때까지 반복(max heap?)
    // 실행할 반복문을 member variables, "direction"을 이용하여 판단해야 함.
    if (direction == 1) {
        // min heap!
        // hole을 올려보내면서(부모 노드에 있는 값을 hole로 move 시키면서)
        // 따라서 부모노드가 현재 갖고 올라가는 값보다 클 때까지만 반복문을 실행해야 함.
        for ( ; heap[idx] < heap[(idx-1)/2]; idx=(idx-1)/2) {
            // 부모노드에 있는 값을 hole의 위치로 보냄 -> 자연스럽게 부모노드가 hole의 역할을 하게 됨.
            swapPQ(idx, (idx-1)/2);
        }

    } else if(direction == -1) {
        // max heap!
        // 부모노드가 현재 갖고 올라가는 값보다 작을 때까지만 반복문을 실행할 것
        for ( ; heap[idx] > heap[(idx-1)/2]; idx=(idx-1) / 2) {
            swapPQ(idx, (idx-1)/2);
        }

    } else {
        // 둘 다 아니라면? 리턴?
    }

}


void PriorityQueue::downHeap(int idx) { // Adjust the heap by moving the specified element downwards.
    // TO-DO
    // pop operation이 호출되고 주로 함께 호출됨 - 양 자식노드의 값이 더 작을 때까지 - maxheap (혹은 . 더 클 때까지 - minheap) 노드를 내려보냄

    // base case
    // 끝에 다다른 경우
    if (idx >= heap_size) {
        return;
    }

    if (direction == 1) {
        int child;
        for (; idx * 2 + 1 <= heap_size - 1; idx = child) {

            child = idx * 2 + 1;
            if (child != heap_size - 1 && heap[child + 1] < heap[child]) {
                ++child;
            }
            if(heap[child] < heap[idx]){
                swapPQ(idx, child);        
            } else {
                break;
            }

        }

    } else if(direction == -1) {

        int child;
        for (; idx * 2 + 1 <= heap_size - 1; idx = child) {

            child = idx * 2 + 1;
            if (child != heap_size - 1 && heap[child + 1] > heap[child]) {
                ++child;
            }
            if(heap[child] > heap[idx]){
                swapPQ(idx, child);
            } else {
                break;
            }
        }

    } 


}


void PriorityQueue::insertHeap(int e) { // Insert a new entry to the queue.
    // TO-DO
    // heap 끝자락에 새로운 element를 붙이는 범위로 국한시킬 예정

    // First, Check if we can use only one space.
    if (heap_size == heap.size() - 1) {
        heap.resize(heap.size() * 2);
    }

    // // Percolate up hole
    // // hole의 인덱스는 제일 큰 수부터 시작 -> tree의 아랫쪽부터 시작
    // // heap_size는 현재 priority queue에 있는 element의 수
    // int hole = ++heap_size;
    // int copy = e;

    // // heap[0]에는 root가 있지 않나? -> ㄴㄴ. 인덱스 0은 비어있음
    // // 그럼 우선 집어넣을 integer를 array의 비어있는 곳에 집어놓고
    // heap[0] = std::move(copy);
    // // perfect binary tree의 array implementation에서 부모노드는 자식노드 인덱스의 절반을 가짐을 이용. -> 부모노드가 현재 insertion 대상값보다 클 때까지 반복(max heap?)
    // // 실행할 반복문을 member variables, "direction"을 이용하여 판단해야 함.
    // if (direction == 1) {
    //     // min heap!
    //     // hole을 올려보내면서(부모 노드에 있는 값을 hole로 move 시키면서)
    //     // 따라서 부모노드가 현재 갖고 올라가는 값보다 클 때까지만 반복문을 실행해야 함.
    //     for ( ; e < heap[hole / 2]; hole /= 2) {
    //         // 부모노드에 있는 값을 hole의 위치로 보냄 -> 자연스럽게 부모노드가 hole의 역할을 하게 됨.
    //         heap[hole] = std::move(heap[ hole / 2 ]);
    //     }
    //     // 왜 하는 거지? - 위에서 비어있는 array의 자리에 집어넣었던 insertion 대상을 move 시켜주는 작업
    //     heap[hole] = std::move(heap[0]);

    // } else if(direction == -1) {
    //     // max heap!
    //     // 부모노드가 현재 갖고 올라가는 값보다 작을 때까지만 반복문을 실행할 것
    //     for ( ; e > heap[hole / 2]; hole /= 2) {
    //         heap[hole] = std::move(heap[ hole / 2 ]);
    //     }
    //     // 왜 하는 거지? - 위에서 비어있는 array의 자리에 집어넣었던 insertion 대상을 move 시켜주는 작업
    //     heap[hole] = std::move(heap[0]);
    // } else {
    //     // 둘 다 아니라면? 리턴?
    // }

    // return ;

    // 만약 Heap의 끝자락에 붙이는 기능만 구현할 것이라면?
    // First, Check if we can use only one space.
    if (heap_size == heap.size() - 1) {
        heap.resize(heap.size() * 2);
    } 

    // define new node
    // heap_size늘리기
    int curr_idx = (++heap_size) - 1; // new element idx를 기억해두고 이를 upHeap 하는데 사용할 수 있지 않으려나? - ㅇㅇ 맞음.
    int copy_e = e;

    // enqueue part
    heap.push_back(e);

    // upHeap을 호출해야 하지 않을까? 따로 호출해야하나?
    upHeap(curr_idx);

    return ;
}


int PriorityQueue::popHeap() {  // Pop its top entry. If the queue is empty, then print "Empty queue.".
    // TO-DO
    // queue에서 highest priority를 가진 element를 pop하는 함수 - index 1에 있는 element를 pop하고 이후에 앞으로 하나씩 땡겨와야 하나?
    // runtime이 많이 들어갈 것 같은데 여기서 circular array의 개념을 도입한다면? - root_index가 미리 정의되어 있음. 
    // 부모노드/자식노드를 인덱싱할 때 heap_size로 나눈 나머지를 이용해야 하나?
    if (emptyHeap()) {
        std::cout<<"Empty queue."<<std::endl;
        return 0;
    }

    // root에 있는 element를 떼와서 따로 저장하기
    // root 인덱스를 변화시키기 -> 누구를 root로? right node의 가장 작은 값(leaf node)을 root로. 이렇게 되면 root_index가 변화해야하나? 1번 index에 새로운 root_node의 값 또는 데이터를 옮겨 놓으면 되는거 아닌가
    
    // root 노드가 어떤 자식 노드 유형을 갖는지 파악해야 함. - 인덱스로 파악해야겠지?
    // 만약 존재하지 않는 노드면 null이라고 표시할 것을 가정하고 코드 작성
    int top_element = heap[root_index];
    // remove the element to be deleted
    // Move last element
    //heap[root_index] = heap[heap_size - 1]; // 근데 top_element의 type을 int로 임의로 지정해도 되나? ㅇㅇ 나중에 printer tree를 따로 구현함
    // last_node를 교환
    swapPQ(root_index, heap_size-1);
    
    // 기존 last node의 값을 지워주는 과정
    heap.pop_back();

    heap_size--;

    // Restore Heap properties
    downHeap(root_index);

    // return하기
    return top_element;

}


int PriorityQueue::topHeap() const {    // Return its top entry. If the queue is empty, then print "Empty queue.".
    // TO-DO
    // heap의 top entry는 tree 모형의 root이고 이는 heap의 1번 인덱스에 위치
    if(emptyHeap()) {
        std::cout << "Empty queue." << std::endl;
        // return 0 하면 0이 출력되는데?
        return 0;
    }
    return heap[root_index];
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
        return true;
    } else {
        return false;
    }
}



// Part 2: Document printer implementation with priority queue (60 pts)
Document::Document(std::string id, std::string title, int priority) {   // Constructor.
    // TO-DO
    if (id.length() > 10) {
        std::cout << "Wrong id."<<std::endl;
        return ;
    }
    this->id = id;
    this->title = title;
    this->priority = priority;

}

Document::Document() {
    
    this->id = "";
    this-> priority = 0;
    this->title = "";

}


std::string Document::getId() const {   // Getter.
    // TO-DO
    return id;
}


std::string Document::getTitle() const {    // Getter.
    // TO-DO
    return title;
}


int Document::getPriority() const { // Getter.
    // TO-DO
    return priority;
}


Printer::Printer() {    // Constructor.
    // TO-DO
    // Printer는 minheap이다.

    root_index = 0;
    heap_size = 0; // 얘 무작정 0으로 해놔도 되나?

    return ;
}


Printer::~Printer() {   // Destructor.
    // TO-DO
    return ;
}


void Printer::swapDoc(int idx1, int idx2) { // Swaps the elements at the specified indices in the printer.
    // TO-DO
    // PQ에서와 달리 id, title, priority를 모두 바꾸어야 한다. -> Document 클래스 자체를 swap하는 게 낫지
    // custom class를 swap하는 방법은?
    Document temp_docu = docs[idx1];
    docs[idx1] = docs[idx2];
    docs[idx2] = temp_docu;

    return ;
}


void Printer::upHeap(int idx) { // Adjust the heap by moving the specified element upwards.
    // TO-DO
    // min heap!
    // hole을 올려보내면서(부모 노드에 있는 값을 hole로 move 시키면서)
    // 따라서 부모노드가 현재 갖고 올라가는 값보다 클 때까지만 반복문을 실행해야 함.
    for ( ; docs[idx].getPriority() < docs[(idx-1)/2].getPriority(); idx=(idx-1)/2) {
        // 부모노드에 있는 값을 hole의 위치로 보냄 -> 자연스럽게 부모노드가 hole의 역할을 하게 됨.
        swapDoc(idx, (idx-1)/2);
    }
}


void Printer::downHeap(int idx) {   // Adjust the heap by moving the specified element downwards.
    // TO-DO
    int child;
    for (; idx * 2 + 1 <= heap_size - 1; idx = child) {

        child = idx * 2 + 1;
        if (child != heap_size - 1 && docs[child + 1].getPriority() < docs[child].getPriority()) {
            ++child;
        }
        if(docs[child].getPriority() < docs[idx].getPriority()){
            swapDoc(idx, child);        
        } else {
            break;
        }

    }
}


void Printer::insertDoc(std::string id, std::string title, int priority) {  // Insert a new doc. (modifiable)
    // TO-DO
    // 문서를 인서트하기 전에 여유공간이 있는지 판단하고 없다면 기존 용량의 두배로 늘리기
    if (heap_size == docs.size() - 1) {
        docs.resize(docs.size() * 2);
    } 
    // define new node
    // heap_size늘리기
    int new_idx = (++heap_size) - 1; // new element idx를 기억해두고 이를 upHeap 하는데 사용할 수 있지 않으려나? - ㅇㅇ 맞음.
    Document new_docu = Document(id, title, priority);

    docs.push_back(new_docu);

    Printer::upHeap(new_idx);

    return ;
}


void Printer::popDoc() {    // Pop its top doc. (modifiable)
    // TO-DO
    if (emptyPrinter()) {
        std::cout << "Empty queue." << std::endl;
    }

    Document top_docu = docs[root_index];
    Printer::swapDoc(root_index, (this->heap_size) -1 );
    docs.pop_back();

    (this->heap_size)--;

    downHeap(root_index);

    return ;
}


Document Printer::topDoc() const {  // Returns the document with the highest priority.
    // TO-DO
    if(emptyPrinter()) {
        std::cout << "Empty queue." << std::endl;
        // return 0 하면 0이 출력되는데?
        return Document();
    }
    return docs[root_index];
}


int Printer::sizePrinter() const {  // Returns the size of the queue.
    // TO-DO
    return heap_size;
}


bool Printer::emptyPrinter() const {    // Check if the queue is empty. `1` for empty queue.
    // TO-DO
    if(heap_size == 0) {
        return true;
    } else {
        return false;
    }
}

// 배열에서 Min Heap을 유지하도록 하는 함수
void Printer::heapify(std::vector<Document> docs, int size, int rootIndex) {
    int smallest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    // 왼쪽 자식이 루트보다 작다면 smallest 갱신
    if (leftChild < size && docs[leftChild].getPriority() < docs[smallest].getPriority()) {
        smallest = leftChild;
    }

    // 오른쪽 자식이 루트보다 작다면 smallest 갱신
    if (rightChild < size && docs[rightChild].getPriority() < docs[smallest].getPriority()) {
        smallest = rightChild;
    }

    // smallest가 변경되면 루트와 smallest의 값을 교환하고 재귀적으로 heapify 호출
    if (smallest != rootIndex) {
        swapDoc(smallest, rootIndex);
        heapify(docs, size, smallest);
    }
}

void Printer::heapSort(Printer printer, int size) {
    // 초기 Min Heap 구성
    for (int i = size / 2 - 1; i >= 0; --i) {
        Printer::downHeap(i);
        //heapify(printer.docs, size, i);
    }

    // 힙 정렬 수행
    for (int i = size - 1; i >= 0; --i) {
        swapDoc(0, i); // 최소값(루트)을 배열 끝으로 이동
        Printer::downHeap(0);
        //heapify(printer.docs, i, 0); // 남은 부분을 Min Heap으로 만듬
    }
}