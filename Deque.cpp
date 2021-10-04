//hpp for the deque 

#include "Deque.hpp"

Deque::Deque() { //constructor 
    size = 0; //initialize size 
}


int Deque::size() const{
    return size;
} 


std::string Deque::top(){

} 
std::string Deque::end(){

}  

const Elem& Deque::getFront() const throw (DequeEmpty){

    return list.front();
}

const Elem& Deque::getBack() const throw (DequeEmpty){
    return list.back();
}

void Deque::insertFront(const Elem& e){
    list.addFront(e);
    size++;
}

void Deque::insertBack(const Elem& e){
    list.addBack(e);
    size++;
}

void Deque::removeFront() throw (DequeEmpty){
    if (empty()){
        throw DequeEmpty("This is an empty deque.");
    }
    list.removeFront();
    size--;
}

void Deque::removeBack() throw (DequeEmpty){
    if (empty()){
        throw DequeEmpty("This is an empty deque.");
    }
    list.removeBack();
    size--;
}  

