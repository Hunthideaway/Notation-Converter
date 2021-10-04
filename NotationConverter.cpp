//cpp for notation converter 

#include "NotationConvert.hpp"

bool variable(char& x) {
    bool lowerCase = (x >= 'a' && x <= 'z');
    bool upperCase = (x >= 'A' && x <= 'Z');
    bool letter = (lowerCase || upperCase); 

    return letter; 
}

bool operation(char& x) { 
    bool add = (x == '+'); 
    bool subract = (x == '-'); 
    bool times = (x == '*'); 
    bool divide = (x == '/'); 
    bool operation = (add || subract || times || divide); 
     
    return operation; 
}