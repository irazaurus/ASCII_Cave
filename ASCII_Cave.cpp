#include <fstream>
#include <iostream>
#include "Room.h"
#include "ConsoleManager.h"

int main()
{
    // opening the rooms file
    std::ifstream inputRooms;
    inputRooms.open("rooms.txt");
    if (inputRooms.fail())
    {
        std::cout << "Problems with opening rooms file.";
        return 1;
    }

    RoomRegistry roomReg;
    roomReg.loadFromStream(inputRooms);
    int currRoomId = 0; // later load currRoom from save file

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
