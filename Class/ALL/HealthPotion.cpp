#include"HealthPotion.h"

HealthPotion_1* HealthPotion_1::create(HelloWorld* combatScene, std::string potionName)
{
	HealthPotion_1* healthPotion = new(std::nothrow)HealthPotion_1;
	if (healthPotion->init(combatScene, potionName))
	{
		healthPotion->autorelease();
		return healthPotion;
	}
	else
	{
		CC_SAFE_DELETE(healthPotion);
		return nullptr;
	}
}

bool HealthPotion_1::init(HelloWorld* combatScene, std::string potionName)
{
	if (!Potion::init(combatScene, potionName))

	{
		return false;
	}
	_MP = 5;
	return true;
}

HealthPotion_2* HealthPotion_2::create(HelloWorld* combatScene, std::string potionName)
{
	HealthPotion_2* healthPotion = new(std::nothrow)HealthPotion_2;
	if (healthPotion->init(combatScene, potionName))
	{
		healthPotion->autorelease();
		return healthPotion;
	}
	else
	{
		CC_SAFE_DELETE(healthPotion);
		return nullptr;
	}
}

bool HealthPotion_2::init(HelloWorld* combatScene, std::string potionName)
{
	if (!Potion::init(combatScene, potionName))

	{
		return false;
	}
	_HP = 2;
	return true;
}

HealthPotion_3* HealthPotion_3::create(HelloWorld* combatScene, std::string potionName)
{
	HealthPotion_3* healthPotion = new(std::nothrow)HealthPotion_3;
	if (healthPotion->init(combatScene, potionName))
	{
		healthPotion->autorelease();
		return healthPotion;
	}
	else
	{
		CC_SAFE_DELETE(healthPotion);
		return nullptr;
	}
}

bool HealthPotion_3::init(HelloWorld* combatScene, std::string potionName)
{
	if (!Potion::init(combatScene, potionName))

	{
		return false;
	}
	_MP = 80;
	return true;
}

HealthPotion_4* HealthPotion_4::create(HelloWorld* combatScene, std::string potionName)
{
	HealthPotion_4* healthPotion = new(std::nothrow)HealthPotion_4;
	if (healthPotion->init(combatScene, potionName))
	{
		healthPotion->autorelease();
		return healthPotion;
	}
	else
	{
		CC_SAFE_DELETE(healthPotion);
		return nullptr;
	}
}

bool HealthPotion_4::init(HelloWorld* combatScene, std::string potionName)
{
	if (!Potion::init(combatScene, potionName))

	{
		return false;
	}
	_maxHP = 5;
	_maxAR = 5;
	return true;
}
