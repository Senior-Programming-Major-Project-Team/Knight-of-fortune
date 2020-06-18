#pragma once
#ifndef WEAPON_H
#define WEAPON_H
#include"cocos2d.h"
#include<iostream>
#include<vector>
#include"Hero.h"

class HelloWorld;

USING_NS_CC;

class Weapon :public Sprite
{
	CC_SYNTHESIZE(INT32, _magicPoint, MagicPoint);
	CC_SYNTHESIZE(INT32, _attackPoint, AttackPoint);
	CC_SYNTHESIZE(float, _critRate, CritRate);
	CC_SYNTHESIZE(String, _weaponName, WeaponName);
	CC_SYNTHESIZE(HelloWorld*, _combatScene, CombatScene);
	CC_SYNTHESIZE(Vector<Sprite*>, _weaponBag, WeaponBag);
public:
	virtual bool init(HelloWorld* combatScene, std::string weaponName, Hero* hero);

	static Weapon* create(HelloWorld* combatScene, std::string weaponName, Hero* hero);

	virtual void openFire(HelloWorld* combatScene);

	//virtual void changeWeapon(HelloWorld* combatScene, std::string weaponName);

	//virtual void pickWeapon(HelloWorld* combatScene, std::string weaponName);

	//virtual bool isWeapon(HelloWorld* combatScene, std::string weaponName);


};



#endif // !WEAPON_H
