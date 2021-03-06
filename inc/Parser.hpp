/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <iostream>

#include "Circuit.hpp"

namespace parse
{
    enum State
    {
        null,
        chipsets,
        links
    };

    class Parser
    {
    public:
        Parser();
        ~Parser();

        /**
         * @brief Opens file ans sets it as parser stream
         * @param filepath File path
         */
        void openFile(const std::string &filepath);

        /**
         * @brief Get the Next Line object and stores it in parser class.
         *
         */
        void getNextLine();

        /**
         * @brief Parse the next line from input.
         *
         * In case of error, throws an exception
         * @return Next parsable element as an std::string
         */
        std::string parseLine();

        /**
         * @brief Indicates if next line is the beggining of a new
         * section.
         *
         * @return true if new section, false otherwise
         */
        bool isNewSection();

        /**
         * @brief Gets the state of parse
         * 
         */
        parse::State getParseState() const {return this->_parseState;};

        /**
         * @brief Adds the components and the links to the circuit in parameter
         * @param circuit Circuit to add teh components in
         * 
         */
        void buildCircuit(Circuit &circuit);

        static class Error : public std::exception
        {
        public:
            Error(const std::string &message) { this->message = std::string(message);};
            ~Error() {};
            const char *what() const noexcept override;

        private:
            std::string message;
        } err;

    protected:
    private:
        std::ifstream _stream;
        std::stringstream _line;
        int _argNumber = 0;
        parse::State _parseState = null;
    };
}

#endif /* !PARSER_HPP_ */
