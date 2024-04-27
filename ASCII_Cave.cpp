#include <fstream>
#include <iostream>
#include "Room.h"
#include "NPC.h"
#include "ConsoleManager.h"

int main()
{
    // TODO перенести загрузку в другой класс. Возможно?

    // load rooms
    std::ifstream input;
    input.open("rooms.txt");
    if (input.fail())
    {
        std::cout << "Problems with opening rooms file.";
        return 1;
    }
    RoomRegistry roomReg;
    roomReg.loadFromStream(input);
    input.close();
    int currRoomId = 0; // TODO load currRoom from save file

    // load NPC
    input.open("npc.txt");
    if (input.fail())
    {
        std::cout << "Problems with opening NPC file.";
        return 1;
    }
    NPCRegister npcReg;
    npcReg.loadFromStream(input);
    input.close();

    // load NPC drawings
    input.open("npc_drawings.txt");
    if (input.fail())
    {
        std::cout << "Problems with opening NPC drawings file.";
        return 1;
    }
    npcReg.loadDrawFromStream(input);
    input.close();

    OutputManager outManager;
    InputManager inManager;
    outManager.gameStart();

    // game loop
    while (true)
    {
        const RoomDef* currRoom = roomReg.getRoomDef(currRoomId);
        std::vector<std::string> choices;
        for (size_t i = 0; i < currRoom->k.size(); i++)
        {
            const RoomDef* r = roomReg.getRoomDef(currRoom->k[i]);
            choices.push_back("Room No " + std::to_string(r->id));
        }

        currRoomId = std::stoi(inManager.getChoice("Where to go?", &choices));
    }
}
