#pragma once

#ifndef _PIG_
#define _PIG_

#include "cocos2d.h"
#include "Enemy.h"

USING_NS_CC;

class Pig
	: public Enemy
{
	CC_SYNTHESIZE(INT32, _attack, Attack);

public:

	static Pig* create(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		Pig* pig = new(std::nothrow)Pig;
		if (pig->init(combatScene, enemyName, actorcamp))
		{
			return pig;
		}
		CC_SAFE_DELETE(pig);
		return nullptr;
	}

	virtual bool init(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		if (!Enemy::init(combatScene, enemyName, actorcamp))
		{
			return false;
		}
		_enemyType = EType::PIG;
		changeMaxHealth(HEALTH + 6);
		setCurrentSpeed(50);
		_attack = 3;
		_attackRadius = 60;
		_minAttackInterval = 2;
		return true;
	}

	void Attack(Hero* hero)
	{
		auto nowTime = GetCurrentTime() / 1000.f;
		if (nowTime - _lastAttackTime < _minAttackInterval)
		{
			return;
		}
		if (hero->getPosition().distance(getPosition()) <= _attackRadius)
		{
			_angle = ccpToAngle(hero->getPosition() - getPosition());
			updateDirection();
			switch (_actordirection)
			{
			case Direction::LEFT:
				setTexture("PigLeft.png");
				break;
			case Direction::RIGHT:
				setTexture("PigRight.png");
				break;
			}
			hero->Damage(_attack);
		}
		_lastAttackTime = nowTime;
	}
};

#endif // _PIG_
