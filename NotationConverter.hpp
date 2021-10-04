
#include "NotationConverterInterface.hpp"
#include "Deque.hpp" 
#include "DequeList.hpp"

class NoationConverter : public NotationConverterInterface { 

private: 
    Deque notation; 

public: 
    std::string postfixToInfix(std::string inStr); //post fix to infix 
    std::string postfixToPrefix(std::string inStr); //post fix to prefix 
    std::string infixToPrefix(std::string inStr); //infix to prefix 
    std::string infixToPostfix(std::string inStr); //infix to postfix 
    std::string prefixToInfix(std::string inStr); //prefix tp infix 
    std::string prefixToPostfix(std::string inStr); //prefix to postfix 

    bool operation(const char& x); // used to check if operation 
    bool variable(const char& x); //used to check if variable 
    
};