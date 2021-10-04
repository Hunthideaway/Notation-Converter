//cpp for notation converter 

#include "NotationConverter.hpp"

bool variable(char& x) {
    bool lowerCase = (x >= 'a' && x <= 'z');
    bool upperCase = (x >= 'A' && x <= 'Z');
    bool letter = (lowerCase || upperCase); 

    return letter; 
}

bool operation(char& x) { 
    switch(x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true; 
        default:
             return false; 
    }
}

std::string NotationConverter::postfixToInfix(std::string inStr){

}

std::string NotationConverter::postfixToPrefix(std::string inStr){

}  

std::string NotationConverter::infixToPrefix(std::string inStr){

}

std::string NotationConverter::infixToPostfix(std::string inStr){

}

std::string NotationConverter::prefixToInfix(std::string inStr){

}

std::string NotationConverter::prefixToPostfix(std::string inStr){

}

// used to check if operation 
bool NotationConverter::operation(const char& x){

} 

//used to check if variable 
bool NotationConverter::variable(const char& y){

}

