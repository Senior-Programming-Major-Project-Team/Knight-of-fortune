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

public:

	virtual void Attack(Hero* hero);

	virtual void enemyMove(const Vec2& targetPosition);//移动

	virtual void stopMove();//停止移动

	virtual void automove();

	virtual void die();

	virtual bool init(HelloWorld* combatScene, std::string enemyName, Camp atorcamp);

	static Enemy* create(HelloWorld* combatScene, std::string enemyName, Camp atorcamp);

protected:

	virtual void initEnemyData(HelloWorld* combatScene, std::string heroName, Camp actorcamp);
};

#endif // _ENEMY_
