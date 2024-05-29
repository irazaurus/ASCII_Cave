#pragma once
#include <vector>
#include "../Headers/Room.h"
//#include "../Headers/Trap.h"
//#include "../Headers/NPC.h"
#include "../Headers/Loader.h"
#include "../Headers/Engine.h"
#include "../Headers/Player.h"

class GameState
{
private:
	Loader load_;
	Player player_;
	Registry<RoomDef> roomReg_;
	Registry<TrapDef> trapReg_;
	Registry<NPCDef> npcReg_;
	int currRoomId_ = 0;

public:
	bool isExit = false;

	Registry<RoomDef>* getRoomReg();
	Registry<TrapDef>* getTrapReg();
	Registry<NPCDef>* getNpcReg();

	Player* getPlayer();

	void initGame();
	void setCurrRoom(int newId);
	RoomDef* getCurrRoom();
};