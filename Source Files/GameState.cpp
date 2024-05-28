#include "../Headers/GameState.h"

void GameState::initGame()
{

}

int GameState::incTrigger(int id)
{
	return ++rooms_.at(id);
}

int GameState::getCurrTrigger(int id) const
{
	return rooms_.at(id);
}

void GameState::setCurrRoom(int newId)
{
	currRoomId_ = newId;
}

int GameState::getCurrRoom()
{
	return currRoomId_;
}
