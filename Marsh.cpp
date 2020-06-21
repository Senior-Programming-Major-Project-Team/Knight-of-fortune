#include"Marsh.h"

Marsh* Marsh::create(HelloWorld* combatScene, std::string buffName, Hero* hero)

{

	Marsh* marsh = new(std::nothrow)Marsh;

	if (marsh->init(combatScene, buffName, hero))

	{

		marsh->autorelease();

		return marsh;

	}

	else

	{

		CC_SAFE_DELETE(marsh);

		return nullptr;

	}

}



bool Marsh::init(HelloWorld* combatScene, std::string buffName, Hero* hero)

{

	if (!Sprite::init())



	{

		return false;

	}

	setTexture("zhaoze.png");

	Vec2 position_1(750, 172.5);


	setPosition(position_1);

	_HP = 1;

	_speed = 5;

	_duration = 10;

	_buffName = buffName;

	_combatscene = combatScene;

	return true;

}