#include"Weapon.h"
#include"cocos2d.h"
#include"HelloWorldScene.h"

USING_NS_CC;

Weapon* Weapon::create(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	Weapon* weapon = new(std::nothrow)Weapon;
	if (weapon->init(combatScene, weaponName, hero))
	{
		weapon->autorelease();
		return weapon;
	}
	else
	{
		CC_SAFE_DELETE(weapon);
		return nullptr;
	}
}

bool Weapon::init(HelloWorld* combatScene, std::string weaponName, Hero* hero)
{
	_magicPoint = 0;
	_attackPoint = 0;
	_critRate = 0;
	return true;
}

void Weapon::openFire(HelloWorld* combatScene) {}

/*void Weapon::pickWeapon(HelloWorld* combatScene, std::string weaponName)
{
	if (!Weapon::isWeapon(combatScene, weaponName))
	{
		return;
	}
	
}*/