#pragma once

#ifndef _FLOWER_
#define _FLOWER_

#include "cocos2d.h"
#include "Enemy.h"

USING_NS_CC;

class Flower
	: public Enemy
{

public:

	Vector<Sprite*> _bullets;

	static Flower* create(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		Flower* flower = new(std::nothrow)Flower;
		if (flower->init(combatScene, enemyName, actorcamp))
		{
			return flower;
		}
		CC_SAFE_DELETE(flower);
		return nullptr;
	}

	virtual bool init(HelloWorld* combatScene, std::string enemyName, Camp actorcamp)
	{
		if (!Enemy::init(combatScene, enemyName, actorcamp))
		{
			return false;
		}
		_enemyType = EType::FLOWER;
		changeMaxHealth(HEALTH + 20);
		_minAttackInterval = 4;
		return true;
	}

	virtual void Attack(Hero* hero, Enemy* enemy)
	{
		auto nowTime = GetCurrentTime() / 1000.f;
		if (nowTime - _lastAttackTime < _minAttackInterval)
		{
			return;
		}
		_lastAttackTime = nowTime;
		Sprite* Bullet1 = Sprite::create("Bullet.png");
		Sprite* Bullet2 = Sprite::create("Bullet.png");
		Sprite* Bullet3 = Sprite::create("Bullet.png");
		Sprite* Bullet4 = Sprite::create("Bullet.png");
		Sprite* Bullet5 = Sprite::create("Bullet.png");
		Sprite* Bullet6 = Sprite::create("Bullet.png");
		Sprite* Bullet7 = Sprite::create("Bullet.png");
		Sprite* Bullet8 = Sprite::create("Bullet.png");
		_bullets.pushBack(Bullet1);
		_bullets.pushBack(Bullet2);
		_bullets.pushBack(Bullet3);
		_bullets.pushBack(Bullet4);
		_bullets.pushBack(Bullet5);
		_bullets.pushBack(Bullet6);
		_bullets.pushBack(Bullet7);
		_bullets.pushBack(Bullet8);
		Bullet1->setPosition(/*getPosition() + */Vec2(30, 30));
		Bullet2->setPosition(/*getPosition() + */Vec2(30, 30));
		Bullet3->setPosition(/*getPosition() + */Vec2(30, 30));
		Bullet4->setPosition(/*getPosition() + */Vec2(30, 30));
		Bullet5->setPosition(/*getPosition() + */Vec2(30, 30));
		Bullet6->setPosition(/*getPosition() + */Vec2(30, 30));
		Bullet7->setPosition(/*getPosition() + */Vec2(30, 30));
		Bullet8->setPosition(/*getPosition() + */Vec2(30, 30));
		this->addChild(Bullet1);
		this->addChild(Bullet2);
		this->addChild(Bullet3);
		this->addChild(Bullet4);
		this->addChild(Bullet5);
		this->addChild(Bullet6);
		this->addChild(Bullet7);
		this->addChild(Bullet8);
		Bullet1->runAction(MoveTo::create(100, Vec2(5000,0) + Bullet1->getPosition()));
		Bullet2->runAction(MoveTo::create(100, Vec2(3540,3540) + Bullet2->getPosition()));
		Bullet3->runAction(MoveTo::create(100, Vec2(0,5000) + Bullet3->getPosition()));
		Bullet4->runAction(MoveTo::create(100, Vec2(-3540,3540) + Bullet4->getPosition()));
		Bullet5->runAction(MoveTo::create(100, Vec2(-5000,0) + Bullet5->getPosition()));
		Bullet6->runAction(MoveTo::create(100, Vec2(-3540,-3540) + Bullet6->getPosition()));
		Bullet7->runAction(MoveTo::create(100, Vec2(0,-5000) + Bullet7->getPosition()));
		Bullet8->runAction(MoveTo::create(100, Vec2(3540,-3540) + Bullet8->getPosition()));
		for (auto i = 0; i < _bullets.size(); i++)
		{
			auto bullet = _bullets.at(i);
			if ((bullet->convertToWorldSpace(Point(0, 0)).distance(hero->getPosition())) < 50)
			{
				hero->Damage(3);
				bullet->removeFromParent();
				_bullets.erase(_bullets.begin() + i);
			}
		}
	}
};

#endif // _FLOWER_