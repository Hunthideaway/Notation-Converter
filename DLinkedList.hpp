//cpp for doubly linked list 

#ifndef DLINKEDLIST_HPP 
#define DLINKEDLIST_HPP

#include <string> 

class DequeNode { //DeequeNode class 
    public: 
        DequeNode(); //constructor 
        ~DequeNode(); //deconstructor 

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
        std::string front() const; //returns the element at the front of the list 
        std::string back() const; //returns the elemetn at the end of the list 
        void addEmpty(DequeNode* newNode); //add a new element to an emtpy list 
        bool empty();
        
        void addFront(const std::string& data);
        void addBack(const std::string& data);
        void removeFront();  
        void removeBack(); 

    private: 
        int size; //the size of the that list 
        DequeNode* header; //pointer to the start of the list 
        DequeNode* trailer; //pointer to the end of the list 
};















#endif