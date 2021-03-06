/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <unordered_map>
#include <exception>
#include <memory>
#include <exception>
#include <algorithm>
#include <bitset>
#include <list>

namespace nts
{
    static bool simulationIsRunning;
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
        public :
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
    };
    struct Link {
        std::size_t pin;
        nts::IComponent *component;
    };
}

using uComp = std::unique_ptr<nts::IComponent>;

#endif /* !ICOMPONENT_HPP_ */
