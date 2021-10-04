//cpp for DLinkedList 

#include "DLinkedList.hpp" 

DLinkedList::DLinkedList() { //constructor 

    header = new DequeNode; //allocated memory for header 
    trailer = new DequeNode; //allocate memory for trailer 
    header->next=trailer; //link the header to the trailer
    trailer->prev=header; //link the trailer to the header 
    size = 0; //initialize the size to 0 

}

DLinkedList::~DLinkedList() { //deconstructor 
    while(!empty()) { //if not empty 
        removeFront(); //remove the front value until the list is empty 
    }
    delete trailer; //finally remove the trailer  
    delete header; //remov the header 
}
const std::string DLinkedList::front() 
    {return header->next->data;}

const std::string DLinkedList::back()
    {return trailer->prev->data;};

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

void DLinkedList::addFront(const std::string& data) { //add a node to the front 
    DequeNode* newNode = new DequeNode; //allocate memory for the node 
    if(empty()) //if empty 
        addEmpty(newNode); //run node through addEmpty 
    else
   addNode(header->next, data); //else run the data through addNode
}

void DLinkedList:: addBack(const std::string& data){
        DequeNode* newNode = new DequeNode; //allocate memory for the node 
    if(empty()) //if empty 
        addEmpty(newNode); //run node through addEmpty 
    else
        addNode(trailer, data); //else run the data through addNode
}
void DLinkedList::removeNode(DequeNode* givenNode){
    DequeNode* prevNode = givenNode->prev;
    DequeNode* afterNode = givenNode->next;

    prevNode->next=afterNode;
    afterNode->prev=prevNode;

    delete givenNode;
    size--;
}

void DLinkedList:: removeFront(){
    if(empty())
        throw("Empty List."); 
    else
    removeNode(header->next);
}

void DLinkedList:: removeBack(){
    if(empty())
        throw("Empty List."); 
    else
    removeNode(trailer->prev);
}