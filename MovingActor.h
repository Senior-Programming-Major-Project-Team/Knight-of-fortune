#pragma once

#ifndef  _MovingActor_
#define  _MovingActor_

#include<iostream>
#include "cocos2d.h"
#include "State.h"
#include "constnumber.h"
#include "HelloWorldScene.h"
#include "Weapon.h"

USING_NS_CC;
using namespace cocos2d;

class State;

class MovingActor : 
	public cocos2d::Sprite
{
	CC_SYNTHESIZE(HelloWorld*, _combatScene, CombatScene);
	CC_SYNTHESIZE(State*, _actorState, ActorState);
	CC_SYNTHESIZE(Camp, _actorcamp, ActorCamp);
	CC_SYNTHESIZE(Direction, _actordirection, ActorDirection);
	CC_SYNTHESIZE(float, _angle, Angle);
	CC_SYNTHESIZE(Weapon*, _actorWeapon1, ActorWeapon1);
	CC_SYNTHESIZE(Weapon*, _actorWeapon2, ActorWeapon2);
	CC_SYNTHESIZE(float, _lastAttackTime, LastAttackTime);

protected:

	void MovingActor::initstate(HelloWorld* combatScene, Camp actorcamp);//初始化数据

	virtual void updateDirection();//判断人物朝向

	virtual void startAnimation();//动画

	virtual void moveTo(const Vec2& targetPosition);//更新人物坐标

public:
	static MovingActor* create(HelloWorld* combatScene, const std::string& filename, Camp actorcamp);

	virtual void die();

	virtual bool init(HelloWorld* combatScene, const std::string& filename, Camp actorcamp);

	virtual void Damage(INT32 _damage);//人物受伤判定

	virtual void Recover();//每帧自动回复护甲和蓝量

	virtual void MagicRecover(float dt);

	virtual void ArmorRecover(float dt);

	virtual void Attack();//攻击判定

	virtual void Buff();//buff效果
};
#endif // _MovingActor_
