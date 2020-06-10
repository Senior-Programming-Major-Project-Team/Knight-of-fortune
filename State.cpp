#include "State.h"
#include "constnumber.h"

USING_NS_CC;

bool State::init()
{
	setMaxArmor(ARMOR);
	setCurrentArmor(ARMOR);
	setMaxMagic(MAGIC);
	setCurrentMagic(MAGIC);
	setMaxHealth(HEALTH);
	setCurrentHealth(HEALTH);
	setCurrentSpeed(100);
	setMinAttackInterval(2);
	setAlreadyDead(false);
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
	setCurrentHealth(newCurrentHealth);
}

void State::changeCurrentMagic(INT32 newCurrentMagic)
{
	if (newCurrentMagic <= 0)
		setCurrentMagic(0);
	if (newCurrentMagic >= _maxMagic)
		setCurrentMagic(_maxMagic);
	setCurrentMagic(newCurrentMagic);
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
	}
	setCurrentArmor(newCurrentArmor);
	return 1;
}

void State::changeCurrentSpeed(INT32 newCurrentSpeed)
{
	setCurrentSpeed(newCurrentSpeed);
}

void State::changeMinAttackInterval(INT32 newMinAttackInterval)
{
	setMinAttackInterval(newMinAttackInterval);
}
