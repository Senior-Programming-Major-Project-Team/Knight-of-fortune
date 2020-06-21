#pragma once

#ifndef _KNIGHT_
#define _KNIGHT_

#include "Hero.h"
#include "cocos2d.h"

USING_NS_CC;

class Knight : public Hero
{
	CC_SYNTHESIZE(bool, _isSkillOn, IsSkillOn);//判断技能是否开启
	CC_SYNTHESIZE(ParticleSystemQuad*, _burn, Burn);//判断技能是否开启

public:

	static Knight* create(HelloWorld* combatScene, std::string heroName, Camp actorcamp)
	{
		Knight* knight = new(std::nothrow)Knight;
		if (knight->init(combatScene, heroName, actorcamp))
		{
			return knight;
		}
		CC_SAFE_DELETE(knight);
		return nullptr;
	}

	virtual bool init(HelloWorld* combatScene, std::string heroName, Camp actorcamp)
	{
		if (!Hero::init(combatScene, heroName, actorcamp))
		{
			return false;
		}
		_isSkillOn = false;
		return true;
	}

	void Skill(float dt)//释放技能
	{
		if (checkSkillStatus())
		{
		    if (!_isSkillOn)
		    {
				setMinAttackInterval(getMinAttackInterval() / 2);
		        setCurrentSpeed(getCurrentSpeed() * 2);
				_burn = ParticleSystemQuad::create("Burn.plist");
				_burn->setPosition(Vec2(30, 30));
				this->addChild(_burn);
				_isSkillOn = true;
			}
		}
	}

	virtual void castSkill()
	{
		this->scheduleOnce(schedule_selector(Knight::Skill), 0);
		this->scheduleOnce(schedule_selector(Knight::stopSkill), 10.0f);
	}

	void stopSkill(float dt)//终止技能
	{
		if (_isSkillOn)
		{
			_lastSkillTime = GetCurrentTime() / 1000.f;
			setMinAttackInterval(MIN_ATTACK_INTERVAL);
			setCurrentSpeed(getCurrentSpeed());
			_burn->removeFromParent();
			_isSkillOn = false;
		}
	}
};

#endif//_KNIGHT_