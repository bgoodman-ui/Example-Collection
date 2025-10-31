#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace calc
{
    /**
     * Representation of a single token.
     */
    struct Token
    {
        /**
         * @brief True if this is a numeric token.
         *
         */
        bool numeric;

        /**
         * @brief The text of the token.
         *
         */
        std::string text;

        /**
         * @brief The numeric value (0 for non-numeric)
         *
         */
        double value;
    };

    /**
     * @brief Break the string up into tokens.
     *
     * @param s
     * @return std::vector<Token>
     */
    std::vector<Token> tokenize(const std::string &s);

    /**
     * @brief Print the token.
     * 
     * @param os 
     * @param t 
     * @return std::ostream& 
     */
    std::ostream &operator<<(std::ostream &os, const Token &t);
}; // namespace calc