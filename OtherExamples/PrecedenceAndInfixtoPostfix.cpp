#include <iostream>
#include <cmath>
#include <stack>
#include <deque>
#include <string>
#include "tokenize.hpp"

int precedence (const calc::Token &op)
{
    if (op.text == "sin"||op.text == "cos"|| op.text == "tan")
        return 4;
    if(op.text == "^")
        return 3;
    if(op.text == "*"||op.text == "/")
        return 2;
    if(op.text == "+"|| op.text == "-")
        return 1;
    return 0;
}
std::deque<calc::Token> infixToPostfix(const std::vector<calc::Token> &infix)
{
    std::stack<calc::Token> ops;
    std::deque<calc::Token> result;
    
    for(const auto &t : infix)
    {
        //numeric and text from tokenize
        if(t.numeric)
        {
            result.push_back(t);
        }
        else if (t.text == "(")
        {
            ops.push(t);
        }
        else if(t.text == ")")
        {
            while(ops.top().text != "(")
            {
                result.push_back(ops.top());
                ops.pop();
            }
            ops.pop();
        }
        
        //if operator is scanned
        else
        {
        while(!ops.empty() && precedence(t) <= precedence(ops.top()))
        {
            result.push_back(ops.top());
            ops.pop();
        }
        ops.push(t);
    }
}
    //pop remaining from stack
    while(!ops.empty())
    {
        result.push_back(ops.top());
        ops.pop();
    }
    return result;
}

int main()
{
    std::string line = "3 * sin(45) + 2 ^ (1+1)";
    std::cout<<"initial statement is "<<line<<std::endl;
    std::vector<calc::Token> infix = calc::tokenize(line);
    
    std::deque<calc::Token> postfix =infixToPostfix(infix);
    std::cout<<"Postfix of statement is ";
    for(const auto &t : postfix)
    {
        std::cout<< t <<" ";
    }
    std::cout<<std::endl;

    return 0;    
}