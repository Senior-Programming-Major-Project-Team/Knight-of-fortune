#pragma once
#ifndef LONG_RANGE_WEAPON
#define LONG_RANGE_WEAPON
#include"cocos2d.h"
#include"Weapon.h"
USING_NS_CC;

class longRangeWeapon :public Weapon
{
	CC_SYNTHESIZE(INT32, _magicPoint, MagicPoint);
	CC_SYNTHESIZE(INT32, _attackPoint, AttackPoint);
	CC_SYNTHESIZE(float, _critRate, CritRate);
	CC_SYNTHESIZE(String, _weaponName, WeaponName);
public:
	virtual bool init(HelloWorld* combatScene, std::string weaponName, Hero* hero);
	//CREATE_FUNC(longRangeWeapon);
	static longRangeWeapon* create(HelloWorld* combatScene, std::string weaponName, Hero* hero);
	//static Scene* createScene();
	


};


#endif // !LONG_RANGE_WEAPON



