/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** FlipFlop
*/

#include "FlipFlop.hpp"

FlipFlop::FlipFlop(const std::string &name, std::size_t nbPin) : BaseComp(name, nbPin)
{
    _inPins = std::vector<int> {3, 4, 5, 6};
    _outPins = std::vector<int> {1, 2};
    _isUpdated = false;
}

FlipFlop::~FlipFlop()
{
}

bool FlipFlop::isNegligeable(std::size_t pin)
{
    if (_pins[pin] == nts::UNDEFINED || _pins[pin] == nts::FALSE)
        return true;
    return false;
}

void FlipFlop::simulate(std::size_t tick)
{
    (void)tick;
    _pins[4] = compute(4); // reset
    _pins[5] = compute(5); // data
    _pins[6] = compute(6); // set

    if (_pins[4] == nts::FALSE && _pins[6] == nts::FALSE) {
        if (_links[3].component->compute(_links[3].pin) == nts::TRUE && isNegligeable(3)) {
            _pins[1] = nts::FALSE;
            _pins[2] = nts::TRUE;
        }
        if (_links[3].component->compute(_links[3].pin) == nts::TRUE && isNegligeable(3) && _pins[5] == nts::TRUE) {
            _pins[1] = nts::TRUE;
            _pins[2] = nts::FALSE;
        }
        compute(3);
    } else {
        if (_pins[4] == nts::TRUE && isNegligeable(6)) {
            _pins[1] = nts::FALSE;
            _pins[2] = nts::TRUE;
        } else if (_pins[6] == nts::TRUE && isNegligeable(4)) {
            _pins[1] = nts::TRUE;
            _pins[2] = nts::FALSE;
        } else if (_pins[4] == nts::TRUE && _pins[6] == nts::TRUE) {
            _pins[1] = nts::TRUE;
            _pins[2] = nts::TRUE;
        } else {
            _pins[1] = nts::UNDEFINED;
            _pins[2] = nts::UNDEFINED;
        }
    }
}

nts::Tristate FlipFlop::compute(std::size_t pin)
{
    if (std::find(_inPins.begin(), _inPins.end(), pin) != _inPins.end()) {
        if (_links[pin].component != nullptr) {
            _pins[pin] = _links[pin].component->compute(_links[pin].pin);
            return _pins[pin];
        }
    } else if (std::find(_outPins.begin(), _outPins.end(), pin) != _outPins.end()) {
        this->simulate(0);
        return _pins[pin];
    } else {
        throw BaseComp::Error("FlipFlop: Pin not found");
    }
    return nts::UNDEFINED;
}
