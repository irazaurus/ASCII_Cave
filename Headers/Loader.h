#pragma once

#include "../Headers/Room.h"
#include "../Headers/NPC.h"
#include <string>
#include <fstream>

class Loader
{
public:
	std::ifstream* getStream();
	bool openFile(std::string name);
	void loadRooms(RoomRegistry* roomReg);
	void loadNPC(NPCRegister* npcReg);
	void loadPlayer();

private:
	std::ifstream stream;
};
