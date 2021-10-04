// cpp for deque 
#include "DLinkedList.hpp" 
#include "DLinkedList.cpp"
typedef std::string Elem;

class Deque { 
    public: 
        Deque(); //constructor
        int size() const; //gets the size of the deque 
        bool empty() {return list.empty();}; //returns if the deque is empty  
        const Elem& front() const throw(); // first element
        const Elem& back() const throw(); // last element
 

        void insertFront(const Elem& e); 
        void insertBack(const Elem& e);
        void removeFront();
        void removeBack();  

    private: 
        int size; 
        DLinkedList list; 
    friend class DequeList;
};