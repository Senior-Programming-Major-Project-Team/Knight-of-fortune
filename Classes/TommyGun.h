#pragma once
#ifndef TOOMYGUN_H
#define TOMMYGUN_H
#include"cocos2d.h"
#include"longRangeWeapon.h"
#include"Hero.h"

class TommyGun :public longRangeWeapon
{
	CC_SYNTHESIZE(INT32, _magicPoint, MagicPoint);

	CC_SYNTHESIZE(INT32, _attackPoint, AttackPoint);

	CC_SYNTHESIZE(float, _critRate, CritRate);

	CC_SYNTHESIZE(Hero*,_hero,hero_);

	CC_SYNTHESIZE(Vector<Enemy*>, _enemies, Enemies);
public:
	virtual bool init(HelloWorld* combatScene, std::string weaponName,Hero* hero, Vector<Enemy*> enemies);
	//CREATE_FUNC(tommyGun);
	static TommyGun* create(HelloWorld* combatScene, std::string weaponName, Hero* hero, Vector<Enemy*> enemies);
	
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	
	virtual void onTouchMoved(Touch* touch, Event* unused_event);
	
	virtual void onTouchEnded(Touch* touch, Event* unused_event);

	virtual void openFire(HelloWorld* combatScene);
	//void touchupdate(float time);
	virtual void consumeMagic(HelloWorld* combatScene);

	virtual void changeCoordinate(float &x, float &y);

	virtual void update(float t);

	

	
	int targetX, targetY;
	
	Vector<Sprite*>allBullet;
};

#endif // !TOOMYGUN_H

