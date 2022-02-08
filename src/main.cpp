/*
** EPITECH PROJECT, 2022
** B-OOP-400-LYN-4-1-tekspice-florian.gibault
** File description:
** main
*/

#include <string>
#include <stdexcept>
#include <iostream>
#include <memory>

#include "Builder.hpp"

void printUsage(void)
{
    std::cout << "Usage: ./nts [filepath.nts]" << std::endl
    << "filepath:\t Path to your config file. Must be written in the .nts format." << std::endl;
}

int main(int ac, char **av)
{
    // if (ac != 2) {
    //     std::cout << "Invalid number of argument." << std::endl;
    //     return 84;
    // }
    // if (ac == 2 && !std::string(av[1]).compare("-h")) {
    //     printUsage();
    //     return 0;
    // }

    Builder builder;
    uComp temp1 = builder.createComponent("input", "enter1");
    uComp temp2 = builder.createComponent("output", "end1");
    uComp temp3 = builder.createComponent("clock", "timer1");
    uComp temp4 = builder.createComponent("4081", "and1");

    temp1.get()->dump();
    temp2.get()->dump();
    temp3.get()->dump();
    temp4.get()->dump();

    Input *dyn_temp = dynamic_cast<Input *>(temp3.get());
    dyn_temp->setValue(nts::TRUE);
    temp3.get()->simulate(1);
    temp4.get()->simulate(1);

    temp1.get()->dump();
    temp2.get()->dump();
    temp3.get()->dump();
    temp4.get()->dump();
    return 0;
}
