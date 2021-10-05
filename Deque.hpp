// cpp for deque
/*
Authors: Randall Hunt, Raed Seraj 
Parts: Driver: Randall %50 , Navigator: Raed %50 

*/
#include "DLinkedList.hpp"

class Deque
{
public:
    Deque();                                  //constructor
    ~Deque();                                 //deconstructor
    int size() const;                         //gets the size of the deque
    bool empty() const;                       //returns if the deque is empty
    const std::string &front() const throw(); // gets the first element
    const std::string &back() const throw();  // gets the last element

    void insertFront(const std::string &e); //function to insert at the front
    void insertBack(const std::string &e);  //function to insert at the end
    void removeFront() throw();             //function to remove at the front
    void removeBack() throw();              //function to remove at the end

private:
    int s;            //helps keep track of the size
    DLinkedList list; //list for data
};