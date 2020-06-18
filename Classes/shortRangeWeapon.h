#pragma once
#ifndef SHORTRANGEWEAPON_H
#define SHORTRANGEWEAPON_H
#include"cocos2d.h"
#include"Weapon.h"


USING_NS_CC;

class ShortRangeWeapon :public Weapon
{
	CC_SYNTHESIZE(INT32, _magicPoint, MagicPoint);
	CC_SYNTHESIZE(INT32, _attackPoint, AttackPoint);
	CC_SYNTHESIZE(float, _critRate, CritRate);
	CC_SYNTHESIZE(String, _weaponName, WeaponName);
public:
	virtual bool init(HelloWorld* combatScene, std::string weaponName, Hero* hero);

	static ShortRangeWeapon* create(HelloWorld* combatScene, std::string weaponName, Hero* hero);

};



#endif // !SHORTRANGEWEAPON_H
