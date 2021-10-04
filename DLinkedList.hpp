//hpp for DLinkedList

#ifndef DLINKEDLIST_HPP
#define DLINKEDLIST_HPP

#include <string>

class DequeNode
{ //DeequeNode class

public:
    DequeNode();  //default constructor
    ~DequeNode(); //default deconstructor

private:
    std::string data;         //data that will be help
    DequeNode *prev;          //pointer to the previous node
    DequeNode *next;          //pointer to the next node;
    
friend class DLinkedList; //allow DequeLsit to access
};

class DLinkedList
{
public:
    DLinkedList();                                               //constructor
    ~DLinkedList();                                              //Deconstructor
    const std::string front(); //returns the element at the front of the list
    const std::string back(); //returns the elemetn at the end of the list
    void addEmpty(DequeNode* newNode);                           //add a new element to an emtpy list
    bool empty();                                                //checks if empty
    void addNode(DequeNode *givenNode, const std::string &data); //adds a node before a given Node
    void addFront(const std::string &data);                      //adds a node to the front
    void addBack(const std::string &data);                       //adds a node to the back
    void removeNode(DequeNode *givenNode);                       //removes the given Node
    void removeFront();                                          //removes a node from the front
    void removeBack();                                           //removes a node from the back

private:
    int size;           //the size of the that list
    DequeNode *header;  //pointer to the start of the list
    DequeNode *trailer; //pointer to the end of the list
};

#endif