#pragma once

#ifndef _HERO_
#define _HERO_

#include "cocos2d.h"
#include "MovingActor.h"
#include "HealthPotion.h"

USING_NS_CC;

class Potion;

class Hero : public MovingActor
{
	CC_SYNTHESIZE(String, _heroName, HeroName);
	CC_SYNTHESIZE(float, _calmTime, CalmTime);
	CC_SYNTHESIZE(float, _lastSkillTime, LastSkillTime);

public:

	virtual void die();

	virtual bool checkSkillStatus();//确认技能是否可以使用

	virtual void castSkill();//释放技能
	
	virtual void heroMove(const Vec2& targetPosition);//移动

	virtual void stopMove();//停止移动

	virtual bool init(HelloWorld* combatScene, std::string heroName, Camp atorcamp);

	static Hero* create(HelloWorld* combatScene, std::string heroName, Camp atorcamp);

	virtual void takepotion(Potion* potion);

protected:

	virtual void initHeroData(HelloWorld* combatScene, std::string heroName, Camp actorcamp);

};

#endif // _HERO_
