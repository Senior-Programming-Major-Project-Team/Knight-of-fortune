#include "State.h"
#include "constnumber.h"
#include "cocos2d.h"

USING_NS_CC;

State* State::create()
{
	State* AState = new (std::nothrow) State;
	if (AState && AState->init())
	{
		AState->autorelease();
		return AState;
	}
	CC_SAFE_DELETE(AState);
	return nullptr;
}


bool State::init()
{
	_maxArmor = ARMOR;
	_currentArmor = ARMOR;
	_maxMagic = ARMOR;
	_currentMagic = MAGIC;
	_maxHealth = HEALTH;
	_currentHealth = HEALTH;
	_currentSpeed = 1;
	_alreadyDead = false;
	return true;
}

void State::changeMaxHealth(INT32 newMaxHealth)
{
	auto oldMaxHealth = _maxHealth;
	setMaxHealth(newMaxHealth);
	setCurrentHealth(_currentHealth + newMaxHealth - oldMaxHealth);
}

void State::changeCurrentHealth(INT32 newCurrentHealth)
{
	if (newCurrentHealth <= 0)
		setCurrentHealth(0);
	if (newCurrentHealth >= _maxHealth)
	    setCurrentHealth(_maxHealth);
}

void State::changeCurrentMagic(INT32 newCurrentMagic)
{
	if (newCurrentMagic <= 0)
		setCurrentMagic(0);
	if (newCurrentMagic >= _maxMagic)
		setCurrentMagic(_maxMagic);
}

INT32 State::changeCurrentArmor(INT32 newCurrentArmor)
{
	if (newCurrentArmor <= 0)
	{
		setCurrentArmor(0);
		return newCurrentArmor;
	}	
	if (newCurrentArmor >= _maxArmor)
	{
		setCurrentArmor(_maxArmor);
		return 1;
	}
}
