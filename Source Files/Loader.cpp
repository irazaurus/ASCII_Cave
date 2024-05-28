#include "../Headers/Loader.h"
#include <iostream>

std::ifstream* Loader::getStream()
{
    return &stream;
}

bool Loader::openFile(std::string name)
{
    stream.open(name);
    if (stream.fail())
    {
        std::cout << "Problems with opening " << name << " file.\n";
        return false;
    }
	return true;
}

void Loader::loadRooms(Registry<RoomDef>& roomReg)
{
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\rooms.txt");
    roomReg.loadFromStream(stream);
    stream.close();
}

void Loader::loadNPC(Registry<NPCDef>& npcReg)
{
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\npc.txt");
    npcReg.loadFromStream(stream);
    stream.close();

    //openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\npc_drawings.txt");
    //npcReg->loadDrawFromStream(stream);
    //stream.close();
}

void Loader::loadTraps(Registry<TrapDef>& trapReg)
{
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\traps.txt");
    trapReg.loadFromStream(stream);
    stream.close();
}
