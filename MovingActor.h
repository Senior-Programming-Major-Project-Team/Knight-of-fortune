#pragma once

#ifndef  _MovingActor_
#define  _MovingActor_

#include<iostream>
#include "cocos2d.h"
#include "State.h"
#include "constnumber.h"

USING_NS_CC;

class State;

class MovingActor : 
	public cocos2d::Sprite
{
	CC_SYNTHESIZE(State*, _actorState, ActorState);
	CC_SYNTHESIZE(Camp, _actorcamp, ActorCamp);

public:
	static MovingActor* create(const std::string& filename, Camp actorcamp);

	virtual void die();

	virtual bool init(const std::string& filename, Camp actorcamp);

	virtual void damage(INT32 _damage);

	virtual void recover();

	virtual void MagicRecover(float dt);

	virtual void ArmorRecover(float dt);

	virtual void Attack();//未实现

	virtual void Buff();//未实现

	virtual void GetWeapon();//未实现
};
#endif // _MovingActor_
