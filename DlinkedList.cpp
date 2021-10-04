//cpp for doubly linked list 

#include "DLinkedList.hpp" 

DLinkedList::DLinkedList() { //constructor 

    header = new DequeNode; //allocated memory for header 
    trailer = new DequeNode; //allocate memory for trailer 
    header->next=trailer; //link the header to the trailer
    trailer->prev=header; //link the trailer to the header 
    size = 0; //initialize the size to 0 

}

DLinkedList::~DLinkedList() { //deconstructor 
    while(!empty()) { 
        removeFront(); //remove the front value until the list is empty 
    }
    delete trailer; //finally remove the trailer  
    delete header; //remov the header 
}

//returns the element at the front of the list
 const std::string DLinkedList:: front() const {
    
        return header->next->data; 
 }  

const std::string DLinkedList:: back() const {    //returns the element at the end of the list 
    
    return trailer->prev->data; 
}

void DLinkedList::addEmpty(DequeNode* newNode) { //function to add a node to an empty list.

    header->next=newNode; //pointer from head to newNode 
    newNode->next=trailer; //pointer from newNode to trailer
    newNode->prev=header;  //pointer from newNode to head 
    trailer->prev=newNode; //pointer from trailer to newNode  
} 

bool DLinkedList::empty(){
    return (header->next==trailer);

}

//the function below add a newNode before the givenNode
void DLinkedList::addNode(DequeNode* givenNode, std:: const string& data ){

    DequeNode* newNode =new DequeNode;

    //Question: possible problem in statement below, the word 'data' is not highlighted in blue, was wondering if it is accessible or not
    newNode->data=data;

    newNode->next=givenNode;

    newNode->prev=givenNode->prev;

    givenNode->prev->next= newNode;

    givenNode->prev = newNode;

}


void DLinkedList:: addFront(const std::string& data){
    addNode(header->next, data);
}

void DLinkedList:: addBack(const std::string& data){
    addNode(trailer, data);
}


//the function below removes the givenNode

void removeNode(DequeNode* givenNode){
    DequeNode* prevNode = givenNode->prev;
    DequeNode* afterNode = givenNode->next;

    prevNode->next=afterNode;
    afterNode->prev=prevNode;

    delete givenNode;
}

void DLinkedList:: removeFront(){
    removeNode(header->next);
}

void DLinkedList:: removeBack(){
    removeNode(trailer->prev);
}