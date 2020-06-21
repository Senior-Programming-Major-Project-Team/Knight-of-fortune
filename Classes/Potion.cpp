#include"Potion.h"

#include"cocos2d.h"

#include"HelloWorldScene.h"

USING_NS_CC;

Potion* Potion::create(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	Potion* potion = new(std::nothrow)Potion;
	if (potion->init(combatScene, potionName, hero))
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

bool Potion::init(HelloWorld* combatScene, std::string potionName, Hero* hero)
{
	if (!Sprite::init())

	{
		return false;
	}
	/*//setTexture("healthpotion_1.bmp");
	//setPosition(110, 110);
	//_HP = 1;
	_attack += 5;
	_hero = hero;
	_potionName = potionName;
	_combatscene = combatScene;*/
	return true;
}

void Potion::update(float t)
{
	setPosition(110, 110);
}