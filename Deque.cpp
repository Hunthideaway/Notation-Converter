//hpp for the deque

#include "Deque.hpp"

Deque::Deque()
{          //constructor
    s = 0; //initialize size
}
Deque::~Deque()
{ //deconstructor
}

int Deque::size() const
{             //return the size of the list
    return s; //size
}

bool Deque::empty() const
{                  //check is empty
    return s == 0; //empty if size = 0
}
const std::string &Deque::front() const throw()
{                        // get thefirst element
    return list.front(); //return the top of the deque
}

const std::string &Deque::back() const throw()
{                       // get the last element
    return list.back(); //return the list end
}

void Deque::insertFront(const std::string &e)
{                     //inserting at the front
    list.addFront(e); //uses list to insert new element
    s++;              //increment the size
}

void Deque::insertBack(const std::string &e)
{                    //insert at the end
    list.addBack(e); //uses list to insert a new element
    s++;             //increments the size
}

void Deque::removeFront() throw()
{                       //remove an element from the front
    list.removeFront(); //using list to remove element
    s--;                //decrement size
}

void Deque::removeBack() throw()
{                      //remove an element from the end
    list.removeBack(); //using list to remove element
    s--;               //decrement
}
