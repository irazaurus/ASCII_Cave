#include <iostream>
#include "../Headers/Room.h"
#include "../Headers/NPC.h"
#include "../Headers/ConsoleManager.h"
#include "../Headers/Loader.h"

int main()
{
    Loader load;
    RoomRegistry roomReg;
    NPCRegister npcReg;

    // load rooms & NPC
    load.loadRooms(&roomReg);
    load.loadNPC(&npcReg);

    int currRoomId = 0; // TODO load currRoom from save file

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

    return 0;
}
