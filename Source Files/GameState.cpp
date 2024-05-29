#include "../Headers/GameState.h"

void GameState::initGame() {
	// load from files
	load_.loadRooms(roomReg_);
	load_.loadNPC(npcReg_);
	load_.loadTraps(trapReg_);
}

Registry<RoomDef>* GameState::getRoomReg()
{
	return &roomReg_;
}

Registry<TrapDef>* GameState::getTrapReg()
{
	return &trapReg_;
}

Registry<NPCDef>* GameState::getNpcReg()
{
	return &npcReg_;
}

Player* GameState::getPlayer()
{
	return &player_;
}

void GameState::setCurrRoom(int newId) {
	currRoomId_ = newId;
}

RoomDef* GameState::getCurrRoom() {
	return (roomReg_.getDef(currRoomId_));
}
