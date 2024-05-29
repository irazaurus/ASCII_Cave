#pragma once
#include <iostream>
#include <vector>

// REGISTRY 

template<typename T>
class Registry
{
public:
	T* getDef(int id);
	void loadFromStream(std::istream& stream);

private:
	std::vector<T> items_;
};

template<typename T>
inline T* Registry<T>::getDef(int id)
{
	if (id >= 0 && id < items_.size()) return &items_[id];
	return nullptr;
}

template<typename T>
inline void Registry<T>::loadFromStream(std::istream& stream)
{
	items_.clear();

	int N = 0;
	stream >> N;

	std::string input;

	for (size_t i = 0; i < N; i++)
	{
		T itemDef{};
		if (!::loadFromStream(stream, itemDef)) { i--; continue; }
		items_.push_back(std::move(itemDef));
	}
}

// TRIGGER

enum TriggerType { TRAP, WIN, FIGHT, LOOT, SHOP };

class Trigger
{
public:
	virtual TriggerType type() = 0;
	virtual ~Trigger() {}
	virtual bool execute() = 0;
};

Trigger* sToTrigger(std::string s);

class WinTrigger : public Trigger {
public:
	TriggerType type() { return WIN; };
	bool execute();
};

class LootTrigger : public Trigger {
public:
	TriggerType type() { return LOOT; }
	bool execute();
};