#include "../Headers/Engine.h"
#include "../Headers/Trap.h"
#include "../Headers/Fight.h"

bool WinTrigger::execute()
{
    std::cout << "Wow you won congrats!\n"; //TODO some win dialog shit
    return true;
}

bool LootTrigger::execute()
{
    return false;
}

Trigger* sToTrigger(std::string s)
{
    if (s == "trap")
        return new TrapTrigger();
    if (s == "fight")
        return new FightTrigger();
    if (s == "win")
        return new WinTrigger();

    return nullptr;
}
