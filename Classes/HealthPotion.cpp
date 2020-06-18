#include"HealthPotion.h"

HealthPotion_1* HealthPotion_1::create()
{
	HealthPotion_1* healthPotion = new(std::nothrow)HealthPotion_1;
	if (healthPotion->init())
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

bool HealthPotion_1::init()
{
	_HP = 1;
	_attack += 5;
}

HealthPotion_2* HealthPotion_2::create()
{
	HealthPotion_2* healthPotion = new(std::nothrow)HealthPotion_2;
	if (healthPotion->init())
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

bool HealthPotion_2::init()
{
	_HP = 2;
	_attack = _attack+3;
}

HealthPotion_3* HealthPotion_3::create()
{
	HealthPotion_3* healthPotion = new(std::nothrow)HealthPotion_3;
	if (healthPotion->init())
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

bool HealthPotion_3::init()
{
	_HP = 2;
	_MP = 15;
}

HealthPotion_4* HealthPotion_4::create()
{
	HealthPotion_4* healthPotion = new(std::nothrow)HealthPotion_4;
	if (healthPotion->init())
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

bool HealthPotion_4::init()
{
	_HP = 4;
}

