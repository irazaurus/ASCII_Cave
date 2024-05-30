#include "../Headers/GameState.h"

void GameState::initGame() {
	// load from files
	load_.loadRooms(roomReg_);
	load_.loadNPC(npcReg_);
	load_.loadTraps(trapReg_);
	load_.loadItems(itemReg_);
	player_.getItems()->push_back(0);
	player_.getItems()->push_back(1);
	player_.getItems()->push_back(2);
}

Registry<RoomDef>* GameState::getRoomReg() {
	return &roomReg_;
}

Registry<TrapDef>* GameState::getTrapReg() {
	return &trapReg_;
}

Registry<NPCDef>* GameState::getNpcReg() {
	return &npcReg_;
}

Registry<ItemDef>* GameState::getItemReg() {
	return &itemReg_;
}

Player* GameState::getPlayer() {
	return &player_;
}

void GameState::setCurrRoom(int newId) {
	currRoomId_ = newId;
}

RoomDef* GameState::getCurrRoom() {
	return (roomReg_.getDef(currRoomId_));
}
