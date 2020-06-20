#include"longRangeWeapon.h"

#include"cocos2d.h"

USING_NS_CC;







longRangeWeapon* longRangeWeapon::create(HelloWorld* combatScene, std::string weaponName, Hero* hero, Vector<Enemy*> enemies)

{

	longRangeWeapon* longRangeweapon = new(std::nothrow)longRangeWeapon;

	longRangeweapon->init(combatScene, weaponName, hero,enemies);

	if (longRangeweapon->init(combatScene, weaponName, hero,enemies))

	{

		longRangeweapon->autorelease();

		return longRangeweapon;

	}

	else

	{

		CC_SAFE_DELETE(longRangeweapon);

		return nullptr;

	}

}



bool longRangeWeapon::init(HelloWorld* combatScene, std::string weaponName, Hero* hero, Vector<Enemy*> enemies)

{

	if (!Sprite::init())



	{



		return false;



	}

	_magicPoint = 0;

	_attackPoint = 0;

	_critRate = 0;

	_combatScene = combatScene;

	_weaponName = weaponName;

	_hero = hero;

	return true;



}



void longRangeWeapon::openFire(HelloWorld* combatScene) {}

void longRangeWeapon::update(float t)
{
	setPosition(_hero->getPositionX(), _hero->getPositionY());

}