#pragma once
#include "statepatten.h"
class damagestate : public statepatten
{
private:
	int count ,index;
	int _character, present;
	bool _present;
	RECT _rc;
public:
	statepatten* handleInput(player* _player);
	void update(player* _player);
	void enter(player* _player, int character);
};

