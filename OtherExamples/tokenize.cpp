#include <sstream>
#include <cctype>
#include "tokenize.hpp"

namespace calc 
{
    // extract the next number from the stream
    static Token nextNumber(std::istream &is)
    {
        Token t;

        t.numeric = true;
        is >> t.value;
        t.text = std::to_string(t.value);

        return t;
    }

    // extract the next function from the stream
    static Token nextFunction(std::istream &is) 
    {
        Token t;

        t.numeric = false;
        t.value = 0;
        while(is && std::isalpha(is.peek())) {
            t.text += (char) is.get();
        }

        return t;
    }

    // extract the next operator from the stream
    static Token nextOperator(std::istream &is)
    {
        Token t;

        t.numeric = false;
        t.value = 0;
        if(is) {
            t.text = (char) is.get();
        }

        return t;
    }

    // Process the next token in the stream
    static Token nextToken(std::istream &is)
    {
        // skip all whitespace
        while(is && isspace(is.peek())) { is.ignore(); }

        // if there are no tokens, return a blank token
        if(!is) return Token(); 

        char c = is.peek();

        // handle numbers
        if(std::isdigit(c)) {
            return nextNumber(is);
        }

        // handle functions
        if(std::isalpha(c)) {
            return nextFunction(is);
        }

        // must be an operator
        return nextOperator(is);
    }

    // Break the string up into tokens.
    std::vector<Token> tokenize(const std::string &s)
    {
        std::istringstream is(s);
        std::vector<Token> v;

        while(is) {
            Token t = nextToken(is);
            if(t.text.length()) {
                v.push_back(t);
            }
        }

        return v;
    }


    // Print the token.
    std::ostream &operator<<(std::ostream &os, const Token &t)
    {
        if(t.numeric) {
            os << t.value;
        } else {
            os << t.text;
        }
        return os;
    }
}