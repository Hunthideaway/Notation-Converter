//cpp for DLinkedList

#include "DLinkedList.hpp"

DLinkedList::DLinkedList()
{ //constructor

    header = new DequeNode;  //allocated memory for header
    trailer = new DequeNode; //allocate memory for trailer
    header->next = trailer;  //link the header to the trailer
    trailer->prev = header;  //link the trailer to the header
}

DLinkedList::~DLinkedList()
{ //deconstructor
    while (!empty())
    {                  //if not empty
        removeFront(); //remove the front value until the list is empty
    }
    delete trailer; //finally remove the trailer
    delete header;  //remov the header
}
const std::string &DLinkedList::front() const //get the element at the front
{
    return header->next->data;
} //pointer to the front element

const std::string &DLinkedList::back() const //get the element at the back
{
    return trailer->prev->data;
} //pointer to the end element

bool DLinkedList::empty() const
{                                     //check if the list is empty
    return (header->next == trailer); //checking if the header points to the trailer
}

void DLinkedList::addNode(DequeNode *givenNode, const std::string &data)
{                                       //adding a node to the given location in the deque
    DequeNode *newNode = new DequeNode; //create a new node
    newNode->data = data;               //link data to new node
    newNode->next = givenNode;          //link the new node to the given node
    newNode->prev = givenNode->prev;    //set new nodes previous to the given nodes previous
    givenNode->prev->next = newNode;    //given nodes last values next value is set to new node
    givenNode->prev = newNode;          //given nodes previous is set to new node
}

void DLinkedList::addFront(const std::string &data)
{                                //add a node to the front
    addNode(header->next, data); // run the data through addNode
}

void DLinkedList::addBack(const std::string &data)
{                           //adding an element to the back
    addNode(trailer, data); // run the data through addNode
}
void DLinkedList::removeNode(DequeNode *givenNode)
{ //removing a node
    if (!empty())
    {                                           //check if empty first
        DequeNode *prevNode = givenNode->prev;  //set previous node to the next of the node we are removing
        DequeNode *afterNode = givenNode->next; //set the last notes next to the previous of the node we are removing

        prevNode->next = afterNode; //link the previous node to the next node after the one we are removing
        afterNode->prev = prevNode; //link the node after the one we are removing's previous to the previous node

        delete givenNode; //delete the desired node
    }
}

void DLinkedList::removeFront()
{                             //remove the front
    removeNode(header->next); //pointer the the element after head
}

void DLinkedList::removeBack()
{                              //remove the back
    removeNode(trailer->prev); //pointer to the previous value
}