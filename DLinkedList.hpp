//cpp for doubly linked list 

#ifndef DLINKEDLIST_HPP 
#define DLINKEDLIST_HPP

#include <string> 

class DequeNode { //DequeNode class 

    //Question: Do we need constructors and destructors for nodes?

    // public: 
    //     DequeNode(); //constructor 
    //     ~DequeNode(); //deconstructor 

    private: 
        std::string data; //data that will be help 
        DequeNode* prev; //pointer to the previous node 
        DequeNode* next; //pointer to the next node; 
        friend class DLinkedList; //allow DequeLsit to access
};

class DLinkedList { 
    public: 
        DLinkedList(); //constructor
        ~DLinkedList(); //Deconstructor

        bool empty();  //checks if linked list is empty

        std::string front() const; //returns the element at the front of the list 

        std::string back() const; //returns the elemetn at the end of the list 

        void addEmpty(DequeNode* newNode); //add a new element to an emtpy list 
       
        
        void addFront(const std::string& data); //adds an element to the front

        void addBack(const std::string& data);      //adds an element to the back

        void removeFront();     //removes the front element

        void removeBack();  //removes the last element

    private: 
        int size; //the size of the that list 
        DequeNode* header; //pointer to the start of the list 
        DequeNode* trailer; //pointer to the end of the list 
};















#endif