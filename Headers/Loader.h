#pragma once

#include "../Headers/Room.h"
#include "../Headers/NPC.h"
#include "../Headers/Engine.h"
#include <string>
#include <fstream>

class Loader
{
public:
	std::ifstream* getStream();
	bool openFile(std::string name);
	void loadRooms(Registry<RoomDef>& roomReg);
	void loadNPC(Registry<NPCDef>& npcReg);
	void loadTraps(Registry<TrapDef>& trapReg);
	void loadPlayer();

private:
	std::ifstream stream;
};
