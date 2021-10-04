//hpp for the deque 

#include "Deque.hpp"

Deque::Deque() { //constructor 
    size = 0; //initialize size 
}

int Deque::size() const{
    return size;
} 

const Elem& front() const throw(){ // first element 
    if(empty()) //if empty 
        throw("Empty Deque."); //return the deque is empty 
    return list.top(); //return the top of the deque 
} 

const Elem& back() const throw(){ // last element
    if(empty()) //if the list is empty 
        throw ("Empty Deque."); //return the list is empty 
    return list.end(); //return the list end 
}  

void Deque::insertFront(const Elem& e){ //inserting at the front 
    list.addFront(e); //uses list to insert new element 
    size++; //increment the size 
}

void Deque::insertBack(const Elem& e){ //insert at the end 
    list.addBack(e); //uses list to insert a new element 
    size++; //increments the size 
}

void Deque::removeFront() throw (){ //remove an element from the front 
    if (empty()){ //in the list is empty 
        throw("This is an empty deque."); //throw empty deque 
    }
    list.removeFront();
    size--;
}

void Deque::removeBack() throw (){
    if (empty()){
        throw("This is an empty deque.");
    }
    list.removeBack();
    size--;
}  