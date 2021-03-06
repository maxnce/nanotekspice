/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string const &name) : Input(name, 1)
{
    _newPins.clear();
}

Clock::~Clock()
{
}

void Clock::simulate(std::size_t tick)
{
    (void)tick;
    if (_pins[1] != nts::UNDEFINED) {
        _pins[1] = (_pins[1] == nts::TRUE) ? nts::FALSE : nts::TRUE;
    }
    if (_newPins.size() > 0) {
        _pins[1] = _newPins.at(1);
        _newPins.clear();
    }
}
