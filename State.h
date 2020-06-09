#pragma once

#ifndef _STATE_
#define _STATE_

#include "cocos2d.h"

USING_NS_CC;

class State
{
	CC_SYNTHESIZE(INT32, _maxArmor, MaxArmor);
	CC_SYNTHESIZE(INT32, _maxMagic, MaxMagic);
	CC_SYNTHESIZE(INT32, _maxHealth, MaxHealth);
	CC_SYNTHESIZE(INT32, _currentArmor, CurrentArmor);
	CC_SYNTHESIZE(INT32, _currentMagic, CurrentMagic);
	CC_SYNTHESIZE(INT32, _currentHealth, CurrentHealth);
	CC_SYNTHESIZE(float, _currentSpeed, CurrentSpeed);
	CC_SYNTHESIZE(bool, _alreadyDead, AlreadyDead);

public:

	void changeMaxHealth(INT32 newMaxHealth);

	void changeCurrentHealth(INT32 newCurrentHealth);

	INT32 changeCurrentArmor(INT32 newCurrentArmor);

	void changeCurrentMagic(INT32 newCurrentMagic);

	virtual bool init();

	static State* create();
};

#endif // _STATE_
