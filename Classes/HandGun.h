#pragma once
#ifndef HANDGUN_H
#define HANDGUN_H
#include"cocos2d.h"
#include"longRangeWeapon.h"



USING_NS_CC;


class HandGun :public longRangeWeapon
{
	CC_SYNTHESIZE(INT32, _magicPoint, MagicPoint);
	CC_SYNTHESIZE(INT32, _attackPoint, AttackPoint);
	CC_SYNTHESIZE(float, _critRate, CritRate);
public:
	virtual bool init(HelloWorld* combatScene, std::string weaponName, Hero* hero);
	//CREATE_FUNC(tommyGun);
	static HandGun* create(HelloWorld* combatScene, std::string weaponName, Hero* hero);

	virtual bool onTouchBegan(Touch* touch, Event* unused_event);

	virtual void onTouchMoved(Touch* touch, Event* unused_event);

	virtual void onTouchEnded(Touch* touch, Event* unused_event);

	virtual void openFire(HelloWorld* combatScene);
	//void touchupdate(float time);
	virtual void consumeMagic(HelloWorld* combatScene);


	int targetX, targetY;

	Vector<Sprite*>allBullet;
};

#endif // !HANDGUN_H
