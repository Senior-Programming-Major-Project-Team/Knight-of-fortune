#pragma once

#ifndef _LANCEGOBLIN_
#define _LANCEGOBLIN_

#include "cocos2d.h"
#include "Enemy.h"

USING_NS_CC;

class LanceGoblin
	: public Enemy
{
	CC_SYNTHESIZE(INT32, _attack, Attack);

public:

	static LanceGoblin* create(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		LanceGoblin* lanceGoblin = new(std::nothrow)LanceGoblin;
		if (lanceGoblin->init(combatScene, enemyName, actorcamp))
		{
			return lanceGoblin;
		}
		CC_SAFE_DELETE(lanceGoblin);
		return nullptr;
	}

	virtual bool init(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		if (!Enemy::init(combatScene, enemyName, actorcamp))
		{
			return false;
		}
		_enemyType = EType::LANCEGOBLIN;
		changeMaxHealth(HEALTH + 14);
		setCurrentSpeed(30);
		_attack = 5;
		_attackRadius = 80;
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
				setTexture("LanceGoblinLeft.png");
				break;
			case Direction::RIGHT:
				setTexture("LanceGoblinRight.png");
				break;
			}
			hero->Damage(_attack);
		}
		_lastAttackTime = nowTime;
	}
};

#endif // _LANCEGOBLIN_
