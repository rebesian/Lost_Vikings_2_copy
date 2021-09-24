#pragma once
#include "statepatten.h"
class jumpstate : public statepatten
{
private:
	float jumpPower , gravity ;
	int jumpcount;
	int count;
	int _character, present;
	bool _present;
	RECT _rc;
public:
	statepatten* handleInput(player* _player);
	void update(player* _player);
	void enter(player* _player, int character);

};

