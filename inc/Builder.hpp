/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
#define BUILDER_HPP_

#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Not.hpp"
#include "Nand.hpp"
#include "Nor.hpp"
#include "Xor.hpp"
#include "True.hpp"
#include "False.hpp"
#include "FlipFlop.hpp"
#include "C4081.hpp"
#include "C4071.hpp"
#include "C4069.hpp"
#include "C4011.hpp"
#include "C4001.hpp"
#include "C4030.hpp"
#include "C4040.hpp"
#include "C4512.hpp"
#include "C4013.hpp"
#include "Logger.hpp"

class Builder;
using builderFunc = uComp (Builder::*)(std::string const &value);

class Builder {
    public:
        Builder();
        ~Builder();
        uComp createComponent(const std::string &type, const std::string &name);
        static class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = new std::string(message);};
                ~Error() {delete this->message;};
                const char *what() const noexcept override;
            private:
                std::string *message;
        } err;
    private:
        std::unordered_map<std::string, builderFunc> _builders;
        uComp createLogger(std::string const &name);
        uComp createInput(std::string const &name);
        uComp createOutput(std::string const &name);
        uComp createTrue(std::string const &name);
        uComp createFalse(std::string const &name);
        uComp createClock(std::string const &name);
        uComp createFlipFlop(std::string const &name);
        uComp createAnd(std::string const &name);
        uComp createC4081(std::string const &name);
        uComp createOr(std::string const &name);
        uComp createC4071(std::string const &name);
        uComp createNot(std::string const &name);
        uComp createC4069(std::string const &name);
        uComp createNand(std::string const &name);
        uComp createC4011(std::string const &name);
        uComp createNor(std::string const &name);
        uComp createC4001(std::string const &name);
        uComp createXor(std::string const &name);
        uComp createC4030(std::string const &name);
        uComp createC4040(std::string const &name);
        uComp createC4512(std::string const &name);
        uComp createC4013(std::string const &name);
};

#endif /* !BUILDER_HPP_ */
