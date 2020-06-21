#include"longRangeWeapon.h"

#include"cocos2d.h"

USING_NS_CC;







longRangeWeapon* longRangeWeapon::create(HelloWorld* combatScene, std::string weaponName, Hero* hero)

{

	longRangeWeapon* longRangeweapon = new(std::nothrow)longRangeWeapon;

	longRangeweapon->init(combatScene, weaponName, hero);

	if (longRangeweapon->init(combatScene, weaponName, hero))

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



bool longRangeWeapon::init(HelloWorld* combatScene, std::string weaponName, Hero* hero)

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

void longRangeWeapon::update(Vector<Enemy*> _enemies)
{
	setPosition(_hero->getPositionX(), _hero->getPositionY());

}