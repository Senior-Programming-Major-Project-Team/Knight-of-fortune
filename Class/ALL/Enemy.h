#pragma once

#ifndef _ENEMY_
#define _ENEMY_

#include "cocos2d.h"
#include "MovingActor.h"
#include "Hero.h"

USING_NS_CC;

class Enemy :
	public MovingActor
{
	CC_SYNTHESIZE(String, _enemyName, EnemyName);
	CC_SYNTHESIZE(EType, _enemyType, EnemyType);
	CC_SYNTHESIZE(float, _lastTimeDead, LastTimeDead);

public:

	virtual void Attack(Hero* hero, Enemy* enemy);

	virtual void enemyMove(const Vec2& targetPosition);//ÒÆ¶¯

	virtual void stopMove();//Í£Ö¹ÒÆ¶¯

	virtual void automove();

	virtual void die();

	virtual bool init(HelloWorld* combatScene, std::string enemyName, Camp atorcamp);

	static Enemy* create(HelloWorld* combatScene, std::string enemyName, Camp atorcamp);

protected:

	virtual void initEnemyData(HelloWorld* combatScene, std::string heroName, Camp actorcamp);
};

#endif // _ENEMY_

