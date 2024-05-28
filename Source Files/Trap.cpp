#include "../Headers/Trap.h"
#include <string>
#include <iostream>

bool loadFromStream(std::istream& stream, TrapDef& itemDef)
{
    std::string input;
    int inp;

    // id
    std::getline(stream, input);
    if (input.empty()) { return false; }
    itemDef.id = std::stoi(input);

    // type
    stream >> input;
    itemDef.type = sToTrap(input);

    // damage
    stream >> inp;
    itemDef.damage = inp;

    return true;
}

TRAP_TYPE sToTrap(std::string str)
{
    if (str == "SPIKE") return SPIKE;
    if (str == "TRAP") return TRAP;
    return TRAP;
}

void TrapTrigger::setMod(int mod)
{
    modification_ = mod;
}

bool TrapTrigger::execute()
{
    int result = rand() % 100 + modification_;
    if (result >= 50) return true;
    return false;
}
