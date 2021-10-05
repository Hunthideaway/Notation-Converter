//cpp for notation converter
//operand is w and y if  w + y
//operation is +
#include "NotationConverter.hpp"

bool NotationConverter::variable(char x) //checks to ensure a valid character is entered.
{
    bool lowerCase = (x >= 'a' && x <= 'z'); //parameters for lower case
    bool upperCase = (x >= 'A' && x <= 'Z'); //parameters for upper case
    bool letter = (lowerCase || upperCase);  //check for lower or upper case

    return letter; //return if lower or upper or neither
}

bool NotationConverter::operation(char x) //checks for operation
{
    switch (x) //take in operation
    {
    case '+':         //addition
    case '-':         //subtraction
    case '/':         //division
    case '*':         //multiplication
        return true;  //returns true if any of the above
    default:          //default
        return false; //returns false all other cases
    }
}

int NotationConverter::orderOperation(string op) //sets the order or operation to follow
{
    if (op == "/" || op == "*")      //if the operation is division or multiplication
        return 2;                    //returns 2
    else if (op == "-" || op == "+") //if the operation is addition or subraction
        return 1;                    //return 1
    else                             //default
        return 0;                    //return 0
}
std::string NotationConverter::prefixToInfix(std::string inStr) //this function converts from prefix to infix, starting from the end.
{

    for (int i = inStr.size() - 1; i >= 0; i--) //for loop to loop through or elements
    {
        if (string(1, inStr[i]) == " ") //if white space, ignore
        {
            continue; //continue
        }

        else if (variable(inStr[i])) //if variable
        {
            dequeNotation.insertFront(string(1, inStr[i])); //insert the data to the deque
        }
        else if (operation(inStr[i])) //if operation
        {
            string temp1 = dequeNotation.front();                           //pull the operand and store it
            dequeNotation.removeFront();                                    //remove the operand
            string temp2 = dequeNotation.front();                           //pull the operand and store it
            dequeNotation.removeFront();                                    //remove the operand
            string temp = "(" + temp1 + " " + inStr[i] + " " + temp2 + ")"; //format infix operands
            dequeNotation.insertFront(temp);                                //store the operation in the deque
        }
        else //default
        {
            throw("Invalid Input!!"); //does not meet any of the cases and outputs invalid input
        }
    }
    return dequeNotation.front() + " "; //return the correct expression
}

std::string NotationConverter::prefixToPostfix(std::string inStr) //function to convert from prefix to postfix
{                                                                 //rather than adding another entire set of functions to convert this, do the following
    string temp = prefixToInfix(inStr);                           //store the output from prefix to infix
    return infixToPostfix(temp);                                  //run temp in infix to postfix
}

std::string NotationConverter::infixToPostfix(std::string inStr)
{                          //this converts from infix to postfix
    string temp = "XXXXX"; //initialize temp list
    dequeNotation.insertFront("");
    for (int i = 0; i < inStr.size(); i++) //for loop to cycle through all variables
    {
        if (string(1, inStr[i]) == " ") //if there is white space ignore it
        {
            continue; //continue
        }
        else if (variable(inStr[i])) //if variable
        {
            temp += inStr[i]; //add variable to temp list
        }
        else if (operation(inStr[i])) //if operation
        {
            while (dequeNotation.front() != "" && orderOperation(string(1, inStr[i])) <= orderOperation(dequeNotation.front())) //check order of operation
            {
                string d = dequeNotation.front(); //set operation to d, temp variable
                dequeNotation.removeFront();      //remove the front
                temp += d;                        //add variable to temp list
            }
            dequeNotation.insertFront(string(1, inStr[i])); //insert at the front
            temp += " ";                                    //create a space
        }
        else if (inStr[i] == '(') //if the variable is (
        {
            dequeNotation.insertFront("("); //insert at the front
        }
        else if (inStr[i] == ')') //if the variable is )
        {
            while (dequeNotation.front() != "" && dequeNotation.front() != "(") //used to place )
            {
                temp += " ";                      //create a white space
                string d = dequeNotation.front(); //store to temp variable
                dequeNotation.removeFront();      //delete from orginal list
                temp += d;                        //add to temp list
            }
            if (dequeNotation.front() == "(") //stores (
            {
                string d = dequeNotation.front() + " "; //set temp variable to ( and white space
                dequeNotation.removeFront();            //remove from front
            }
        }
        else //default
        {
            throw("Invalid Input!!"); //throw invalid input if user input invalid operation
        }
    }
    while (dequeNotation.front() != "") //use to print list
    {
        string d = dequeNotation.front(); //store the front value in temp variable
        dequeNotation.removeFront();      //remove front variable
        temp += d;                        //add variable to list
    }
    return temp; //return list
}

std::string NotationConverter::infixToPrefix(std::string inStr) //function to convert from infix to prefix
{                                                               //use the other functions to convert the data rather than typing another set of functions
    string temp = infixToPostfix(inStr);                        //store the output of data through infix to postfix
    return postfixToPrefix(temp);                               //return the data after going through postfix to prefix
}

std::string NotationConverter::postfixToInfix(std::string inStr) //convert from postfix to infix
{
    for (int i = 0; i < inStr.size(); i++) //traverse through all the varaibles
    {
        if (string(1, inStr[i]) == " ") //check for white spaces and ignore
        {
            continue; //continue
        }
        else if (variable(inStr[i])) //if variable
        {
            string temp(1, inStr[i]);        //store the character in temp
            dequeNotation.insertFront(temp); //insert at front
        }
        else if (operation(inStr[i])) //if operation
        {
            string temp1 = dequeNotation.front();                                        //store the first operand in temp1
            dequeNotation.removeFront();                                                 //remove the operand  from the list
            string temp2 = dequeNotation.front();                                        //store the second operand in temp2
            dequeNotation.removeFront();                                                 //remove the operand from the list
            dequeNotation.insertFront("(" + temp2 + " " + inStr[i] + " " + temp1 + ")"); //format the operands and operation  and insert into deque
        }
        else //default
        {
            throw("Invalid Input!!!"); //invalid user input
        }
    }
    return dequeNotation.front(); //return front
}

std::string NotationConverter::postfixToPrefix(std::string inStr) //function to convert from postfix to prefix
{
    for (int i = 0; i < inStr[i]; i++) //loop to travers all variables
    {
        if (string(1, inStr[i]) == " ")
        { //used to ignore white spaces
            continue;
        } //continue

        else if (variable(inStr[i])) //if variable
        {
            string temp(1, inStr[i]);        //initialize variable to store the character
            dequeNotation.insertFront(temp); //insert into deque
        }
        else if (operation(inStr[i])) //if operation
        {
            string temp1 = " " + dequeNotation.front(); //set first operand to temp1
            dequeNotation.removeFront();                //remove from list
            string temp2 = " " + dequeNotation.front(); //set second operand to temp2
            dequeNotation.removeFront();                //remove from list

            string temp = inStr[i] + temp2 + temp1; //format the operants and operations
            dequeNotation.insertFront(temp);        //insert into deque
        }
        else //default
        {
            throw("Invalid Input!!"); //invalud user input
        }
    }
    return dequeNotation.front() + " "; //return the expression
}
