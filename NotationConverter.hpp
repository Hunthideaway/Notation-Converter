/*
Authors: Randall Hunt, Raed Seraj 
Parts: Driver: Randall %50 , Navigator: Raed %50 

*/
#include "NotationConverterInterface.hpp"
#include "Deque.hpp"

class NotationConverter : public NotationConverterInterface
{

private:
    Deque dequeNotation; //converter for notations
    int size;            //keeps the size

public:
    void clear();                                   //helper function to clear the entire deque
    std::string postfixToInfix(std::string inStr);  //post fix to infix
    std::string postfixToPrefix(std::string inStr); //post fix to prefix
    std::string infixToPrefix(std::string inStr);   //infix to prefix
    std::string infixToPostfix(std::string inStr);  //infix to postfix
    std::string prefixToInfix(std::string inStr);   //prefix tp infix
    std::string prefixToPostfix(std::string inStr); //prefix to postfix

    bool operation(char x);        // used to check if operation
    bool variable(char x);         //used to check if variable
    int orderOperation(string op); //used to determine the order of operation
};
