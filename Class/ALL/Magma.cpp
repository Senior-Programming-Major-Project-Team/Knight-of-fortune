#include"Magma.h"

Magma* Magma::create(HelloWorld* combatScene, std::string buffName, Hero* hero)

{

	Magma* magma = new(std::nothrow)Magma;

	if (magma->init(combatScene, buffName, hero))

	{

		magma->autorelease();

		return magma;

	}

	else

	{

		CC_SAFE_DELETE(magma);

		return nullptr;

	}

}



bool Magma::init(HelloWorld* combatScene, std::string buffName, Hero* hero)

{

	if (!Sprite::init())



	{

		return false;

	}

	setTexture("zhaoze.png");

	Vec2 position_1(800, 172.5);


	setPosition(position_1);

	_HP = 3;

	

	_duration = 10;

	_buffName = buffName;

	_combatscene = combatScene;

	return true;

}