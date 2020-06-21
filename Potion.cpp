#include"Potion.h"

#include"cocos2d.h"

#include"HelloWorldScene.h"

USING_NS_CC;

Potion* Potion::create(HelloWorld* combatScene, std::string potionName)
{
	Potion* potion = new(std::nothrow)Potion;
	if (potion->init(combatScene, potionName))
	{
		potion->autorelease();
		return potion;
	}
	else
	{
		CC_SAFE_DELETE(potion);
		return nullptr;
	}
}

bool Potion::init(HelloWorld* combatScene, std::string potionName)
{
	if (!Sprite::init())

	{
		return false;
	}
	_maxHP = 0;
	_maxAR = 0;
	_HP = 0;
	_MP = 0;
	return true;
}