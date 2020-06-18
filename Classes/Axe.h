#pragma once
#ifndef AXE_H
#define AXE_H
#include"shortRangeWeapon.h"
#include"cocos2d.h"

USING_NS_CC;

class Axe :public ShortRangeWeapon
{
	CC_SYNTHESIZE(INT32, _magicPoint, MagicPoint);
	CC_SYNTHESIZE(INT32, _attackPoint, AttackPoint);
	CC_SYNTHESIZE(float, _critRate, CritRate);
	CC_SYNTHESIZE(float, _attackRadius, AttackRadius);
public:
	virtual bool init(HelloWorld* combatScene, std::string weaponName, Hero* hero);
	//CREATE_FUNC(tommyGun);
	static Axe* create(HelloWorld* combatScene, std::string weaponName, Hero* hero);

	virtual bool onTouchBegan(Touch* touch, Event* unused_event);

	virtual void onTouchMoved(Touch* touch, Event* unused_event);

	virtual void onTouchEnded(Touch* touch, Event* unused_event);

	virtual void attack(HelloWorld* combatScene);
	//void touchupdate(float time);



	int targetX, targetY;



};



#endif // !AXE_H


