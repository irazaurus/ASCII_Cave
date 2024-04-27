#include "Trap.h"

TrapDef* TrapRegistry::getTrapDef(int id)
{
    if (id >= 0 && id < traps_.size()) return &traps_[id];
    return nullptr; // TODO где-то это обработать
}
