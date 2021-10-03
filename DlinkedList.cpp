//cpp for doubly linked list 

#include "DLinkedList.hpp" 

DLinkedList::DLinkedList() { //constructor 

    header = new DequeNode; //allocated memory for header 
    trailer = new DequeNode; //allocate memory for trailer 
    header->next=trailer; //link the header to the trailer
    trailer->prev=next; //link the trailer to the header 
    size = 0; //initialize the size to 0 

}

DLinkedList::~DLinkedList() { //deconstructor 
    while(!empty()) { 
        remvoeFront(); //remove the front value until the list is empty 
    }
    delete trailer; //finally remove the trailer  
    delete header; //remov the header 
}

 std::string front() const  //returns the element at the front of the list
    return header->next->data; 

std::string back() const //returns the elemetn at the end of the list 
    return trailer->prev->data; 


void DLinkedList::addEmpty(DequeNode* newNode) { //function to add a node to an empty list. 
    header->next=newNode; //pointer from head to newNode 
    newNode->next=trailer; //pointer from newNode to trailer
    newNode->prev=header;  //pointer from newNode to head 
    trailer->prev=newNode; //pointer from trailer to newNode  
} 

void DLinkedList::addFront(const std::String& data) {
    
}