// cpp for deque 
#include "DLinkedList.hpp" 
#include "DLinkedList.cpp"
typedef std::string Elem;

class Deque { 
    public: 
        Deque(); //constructor
        int size() const; //gets the size of the deque 
        bool empty() {return list.empty();}; //returns if the deque is empty 


        //Question: Do we need top() and end() if we have front() and back()

        std::string top(); //retruns the first value  
        std::string end(); //returns the end value  

        const Elem& getFront() const throw (DequeEmpty);        //return the front value/element
        const Elem& getBack() const throw (DequeEmpty);         //return the end value/element

        void insertFront(const Elem& e); 
        void insertBack(const Elem& e);
        void removeFront() throw (DequeEmpty);
        void removeBack() throw (DequeEmpty);  

    private: 
        int size; 
        DLinkedList list; 
        friend class DequeList; //Question: Do we need to friend any other class? and what is the DequeList class?
};