#include "../Headers/Loader.h"
#include <iostream>

std::ifstream* Loader::getStream() {
    return &stream;
}

bool Loader::openFile(std::string name) {
    stream.open(name);
    if (stream.fail())
    {
        std::cout << "Problems with opening " << name << " file.\n";
        return false;
    }
	return true;
}

void Loader::loadRooms(Registry<RoomDef>& roomReg) {
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\rooms.txt");
    roomReg.loadFromStream(stream);
    stream.close();
}

void Loader::loadNPC(Registry<NPCDef>& npcReg) {
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\npc.txt");
    npcReg.loadFromStream(stream);
    stream.close();

    //setlocale(LC_ALL, "");
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\npc_drawings.txt");
    
    std::string input;
    std::getline(stream, input);
    std::getline(stream, input);
    int N = std::stoi(input);

    std::getline(stream, input);
    for (size_t i = 0; i < N; i++) {
        // id
        int id;
        stream >> id;
        loadDrawFromStream(stream, npcReg.getDef(i));
    }
    stream.close();
}

void Loader::loadTraps(Registry<TrapDef>& trapReg) {
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\traps.txt");
    trapReg.loadFromStream(stream);
    stream.close();
}

void Loader::loadItems(Registry<ItemDef>& itemReg) {
    openFile("C:\\Users\\pyuchy\\source\\repos\\ASCII_Cave\\Resources\\items.txt");
    itemReg.loadFromStream(stream);
    stream.close();
}
