/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit() : BaseComp("Global Circuit", 0)
{
}

Circuit::Circuit(const std::string &name, const std::size_t nbPin) : BaseComp(name, nbPin)
{
}

Circuit::~Circuit()
{
}

nts::IComponent *Circuit::operator[](const std::string &name)
{
    if (_components.find(name) == _components.end()) {
        throw Circuit::Error("Component not found");
    }
    return _components[name].get();
}

void Circuit::AddComponent(const std::string &type, const std::string &name)
{
    if (_components.find(name) != _components.end()) {
        throw Circuit::Error("This component already exists in this circuit");
    }
    uComp newComp = builder.createComponent(type, name);
    _components.emplace(name, std::move(newComp));
    if (type == "input" || type == "clock") {
        _inpComponents.insert(_inpComponents.begin(), name);
    } else if (type == "output" || type == "logger") {
        _outComponents.insert(_outComponents.begin(), name);
    }
}


void Circuit::simulate(std::size_t tick)
{
    (void)tick;
    for (auto it = _inpComponents.begin(); it != _inpComponents.end(); it++) {
        if (_components.find(*it) != _components.end()) {
            _components[*it]->simulate(tick);
        } else {
            throw Circuit::Error("Component not found");
        }
    }
    for (auto it = _outComponents.begin(); it != _outComponents.end(); it++) {
        if (_components.find(*it) != _components.end()) {
            _components[*it]->simulate(tick);
        } else {
            throw Circuit::Error("Component not found");
        }
    }
    _tickCount++;
    std::sort(_inpComponents.begin(), _inpComponents.end());
    std::sort(_outComponents.begin(), _outComponents.end());
    return;
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void Circuit::setLink(std::size_t pin1, const std::string &comp1, std::size_t pin2, const std::string &comp2)
{
    if (_components.find(comp1) == _components.end()) {
        throw Circuit::Error("This component isn't in the circuit \"" + comp1 + "\"");
    }
    if (_components.find(comp2) == _components.end()) {
        throw Circuit::Error("This component isn't in the circuit \"" + comp2 + "\"");
    }
    _components[comp1]->setLink(pin1, *_components[comp2], pin2);
    _components[comp2]->setLink(pin2, *_components[comp1], pin1);
    return;
}

void Circuit::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    (void)pin;
    (void)other;
    (void)otherPin;
    return;
}

void Circuit::dump() const
{
    std::cout << "Dump of the circuit " << _name << std::endl;
    for (auto &comp : _components) {
        comp.second->dump();
    }
    return;
}

void Circuit::display()
{
    std::sort(_inpComponents.begin(), _inpComponents.end());
    std::sort(_outComponents.begin(), _outComponents.end());

    std::cout << "tick: " << _tickCount << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it = _inpComponents.begin(); it != _inpComponents.end(); it++) {
        if (_components.find(*it) != _components.end()) {
            std::cout << std::setw(3) << *it << ": " << _components[*it]->compute(1) << std::endl;
        } else {
            throw Circuit::Error("Component not found");
        }
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = _outComponents.begin(); it != _outComponents.end(); it++) {
        if (_components.find(*it) != _components.end()) {
            std::cout << std::setw(3) << *it << ": " << _components[*it]->compute(1) << std::endl;
        } else {
            throw Circuit::Error("Component not found");
        }
    }
}

const char *Circuit::Error::what() const noexcept
{
    return this->message->c_str();
}
