#pragma once

#ifndef  _MovingActor_
#define  _MovingActor_

#include<iostream>
#include "cocos2d.h"
#include "constnumber.h"

USING_NS_CC;
using namespace cocos2d;

class State;
class HelloWorld;

class MovingActor : 
	public cocos2d::Sprite
{
	CC_SYNTHESIZE(HelloWorld*, _combatScene, CombatScene);
	CC_SYNTHESIZE(Camp, _actorcamp, ActorCamp);
	CC_SYNTHESIZE(Direction, _actordirection, ActorDirection);
	CC_SYNTHESIZE(float, _angle, Angle);
	CC_SYNTHESIZE(float, _lastAttackTime, LastAttackTime);
	CC_SYNTHESIZE(float, _maxArmor, MaxArmor);
	CC_SYNTHESIZE(float, _maxMagic, MaxMagic);
	CC_SYNTHESIZE(float, _maxHealth, MaxHealth);
	CC_SYNTHESIZE(float, _currentArmor, CurrentArmor);
	CC_SYNTHESIZE(float, _currentMagic, CurrentMagic);
	CC_SYNTHESIZE(float, _currentHealth, CurrentHealth);
	CC_SYNTHESIZE(float, _currentSpeed, CurrentSpeed);
	CC_SYNTHESIZE(bool, _alreadyDead, AlreadyDead);
	CC_SYNTHESIZE(float, _minAttackInterval, MinAttackInterval);
	CC_SYNTHESIZE(float, _attackRadius, AttackRadius);

protected:

	void MovingActor::initstate(HelloWorld* combatScene, Camp actorcamp);//��ʼ������

	virtual void updateDirection();//�ж����ﳯ��

	void changeMaxHealth(float newMaxHealth);

	void changeMaxAromr(float newMaxArmor);

	void changeCurrentHealth(float newCurrentHealth);

	void changeCurrentArmor(float newCurrentArmor);

	void changeCurrentMagic(float newCurrentMagic);

public:
	static MovingActor* create(HelloWorld* combatScene, const std::string& filename, Camp actorcamp);

	virtual void die();

	virtual bool init(HelloWorld* combatScene, const std::string& filename, Camp actorcamp);

	virtual void Damage(float _damage);//���������ж�

	virtual void Recover();//ÿ֡�Զ��ظ�����

	virtual void ArmorRecover(float dt);

};
#endif // _MovingActor_

