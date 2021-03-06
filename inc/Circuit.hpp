/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "Factory.hpp"

class Circuit : public BaseComp {
    public:
        Circuit();
        ~Circuit();

        nts::IComponent *operator[](const std::string &name);
        void AddComponent(const std::string &type, const std::string &name);
        void confirmSimulation(void);

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::size_t pin1, const std::string &comp1, std::size_t pin2, const std::string &comp2);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
        void display();

        static class Error : public std::exception {
            public:
                Error(const std::string &message) {this->message = std::string(message);};
                ~Error() {};
                const char *what() const noexcept override;
            private:
                std::string message;
        } err;
        bool isExiting = false;
    private:
        std::map<std::string, uComp> _components;
        std::vector<std::string> _inpComponents;
        std::vector<std::string> _outComponents;
        std::vector<std::string> _midComponents;
        int _tickCount = 0;
        Factory factory;
};

#endif /* !CIRCUIT_HPP_ */
