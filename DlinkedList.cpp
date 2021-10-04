//cpp for DLinkedList 

#include "DLinkedList.hpp" 

DLinkedList::DLinkedList() { //constructor 

    header = new DequeNode; //allocated memory for header 
    trailer = new DequeNode; //allocate memory for trailer 
    header->next=trailer; //link the header to the trailer
    trailer->prev=next; //link the trailer to the header 
    size = 0; //initialize the size to 0 

}

DLinkedList::~DLinkedList() { //deconstructor 
    while(!empty()) { //if not empty 
        removeFront(); //remove the front value until the list is empty 
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

bool DLinkedList::empty(){//check if the list is empty 
    return (header->next==trailer);
}

void DLinkedList::addNode(DequeNode* givenNode, const std::string& data ){ //adding a node to the given location in the deque
    DequeNode* newNode =new DequeNode; //create a new node 
    newNode->data=data; //link data to new node 
    newNode->next=givenNode; //link the new node to the given node 
    newNode->prev=givenNode->prev; //set new nodes previous to the given nodes previous 
    givenNode->prev->next= newNode; //given nodes last values next value is set to new node 
    givenNode->prev = newNode; //given nodes previous is set to new node 

}

void DLinkedList::addFront(const std::String& data) { //add a node to the front 

}