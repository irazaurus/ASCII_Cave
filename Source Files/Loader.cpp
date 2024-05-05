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
        std::cout << "Problems with opening " << name << " file.";
        return false;
    }
	return true;
}

void Loader::loadRooms(RoomRegistry* roomReg)
{
    openFile("C:\\Users\\Artem_Step\\source\\repos\\ASCII_Cave\\Resources\\rooms.txt");
    roomReg->loadFromStream(stream);
    stream.close();
}

void Loader::loadNPC(NPCRegister* npcReg)
{
    openFile("C:\\Users\\Artem_Step\\source\\repos\\ASCII_Cave\\Resources\\npc.txt");
    npcReg->loadFromStream(stream);
    stream.close();

    openFile("C:\\Users\\Artem_Step\\source\\repos\\ASCII_Cave\\Resources\\npc_drawings.txt");
    npcReg->loadDrawFromStream(stream);
    stream.close();
}
