#include "PriorityQueue.hpp"


// Part 1: Basic operations of priority queue (40 pts)
PriorityQueue::PriorityQueue(int direction) {   // Constructor.
    // TO-DO
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