#pragma once

#ifndef _HANDGUNGOBLIN_
#define _HANDGUNGOBLIN_

#include "cocos2d.h"
#include "Enemy.h"

USING_NS_CC;

class HandGunGoblin
	: public Enemy
{

public:

	Vector<Sprite*> _bullets;

	static HandGunGoblin* create(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		HandGunGoblin* handGunGoblin = new(std::nothrow)HandGunGoblin;
		if (handGunGoblin->init(combatScene, enemyName, actorcamp))
		{
			return handGunGoblin;
		}
		CC_SAFE_DELETE(handGunGoblin);
		return nullptr;
	}

	virtual bool init(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		if (!Enemy::init(combatScene, enemyName, actorcamp))
		{
			return false;
		}
		_enemyType = EType::HANDGUNGOBLIN;
		changeMaxHealth(HEALTH + 10);
		_minAttackInterval = 1;
		_currentSpeed = 10;
		return true;
	}

	void Attack(Hero* hero)
	{
		auto nowTime = GetCurrentTime() / 1000.f;
		if (nowTime - _lastAttackTime < _minAttackInterval)
		{
			return;
		}
		_lastAttackTime = nowTime;
		Sprite* Bullet = Sprite::create("Bullet.png");
		_bullets.pushBack(Bullet);
		Bullet->setPosition(/*getPosition() + */Vec2(30, 30));
		this->addChild(Bullet);
		srand(time(0) + rand());
		Point point;
		point.x = CCRANDOM_0_1() * 2 - 1;
		point.y = CCRANDOM_0_1() * 2 - 1;
		Bullet->runAction(MoveTo::create(1, point * 500 + Bullet->getPosition()));
		for (auto i = 0; i < _bullets.size(); i++)
		{
			auto bullet = _bullets.at(i);
			if (hero->getPosition().distance(getPosition()) == bullet->getPosition().distance(Vec2(0, 0)))
			{
				hero->Damage(3);
				bullet->removeFromParent();
				_bullets.erase(_bullets.begin() + i);
				CC_SAFE_DELETE(bullet);
			}
		}
	}
};

#endif // _HandGunGoblin_
