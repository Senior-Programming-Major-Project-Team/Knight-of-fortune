#include"HealthPotion.h"

HealthPotion_1* HealthPotion_1::create(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	HealthPotion_1* healthPotion = new(std::nothrow)HealthPotion_1;
	if (healthPotion->init(combatScene, potionName, hero))
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

bool HealthPotion_1::init(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	if (!Potion::init(combatScene, potionName, hero))

	{
		return false;
	}
	setTexture("healthpotion_1.bmp");
	setPosition(110, 110);
	_HP = 1;
	_attack += 5;
	_hero = hero;
	_potionName = potionName;
	_combatscene = combatScene;
	return true;
}

void HealthPotion_1::update(float t)
{
	setPosition(110, 110);
}

HealthPotion_2* HealthPotion_2::create(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	HealthPotion_2* healthPotion = new(std::nothrow)HealthPotion_2;
	if (healthPotion->init(combatScene, potionName, hero))
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

bool HealthPotion_2::init(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	setTexture("healthpotion_2.bmp");
	_HP = 2;
	_attack = _attack+3;
	_hero = hero;
	_potionName = potionName;
	_combatscene = combatScene;
	return true;
}

HealthPotion_3* HealthPotion_3::create(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	HealthPotion_3* healthPotion = new(std::nothrow)HealthPotion_3;
	if (healthPotion->init(combatScene, potionName, hero))
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

bool HealthPotion_3::init(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	setTexture("healthpotion_3.bmp");
	_HP = 2;
	_MP = 15;
	_hero = hero;
	_potionName = potionName;
	_combatscene = combatScene;
	return true;
}

HealthPotion_4* HealthPotion_4::create(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	HealthPotion_4* healthPotion = new(std::nothrow)HealthPotion_4;
	if (healthPotion->init(combatScene, potionName, hero))
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

bool HealthPotion_4::init(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	setTexture("healthpotion_4.bmp");
	_HP = 4;
	_MP = 5;
	_hero = hero;
	_potionName = potionName;
	_combatscene = combatScene;
	return true;
}

