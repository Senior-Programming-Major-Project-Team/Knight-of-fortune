#pragma once

#ifndef _KNIGHT_
#define _KNIGHT_

#include "Hero.h"

USING_NS_CC;

class Knight : public Hero
{
	CC_SYNTHESIZE(float, _maxskillTime, MaxSkillTime);//技能使用时间
	CC_SYNTHESIZE(float, _currentskillTime, CurrentSkillTime);//当前使用时间
	CC_SYNTHESIZE(float, _startTime, StartTime);//开启技能时间
	CC_SYNTHESIZE(bool, _isSkillOn, IsSkillOn);//判断技能是否开启

public:

	Knight* create(HelloWorld* combatScene, std::string heroName, Camp actorcamp)
	{
		Knight* knight = new(std::nothrow)Knight;
		if (knight && knight->init(combatScene, heroName, actorcamp))
		{
			knight->autorelease();
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
		_maxskillTime = 20;
		_currentskillTime = 0;
		_isSkillOn = false;
		return true;
	}

	virtual void castSkill()//释放技能
	{
		if (checkSkillStatus() && checkSkillTime())
		{
		    if (!_isSkillOn)
		    {
				_startTime = GetCurrentTime() / 1000.f;
				_actorState->setMinAttackInterval(_actorState->getMinAttackInterval() / 2);
		        _actorState->setCurrentSpeed(_actorState->getCurrentSpeed * 2);
			}
			
			_isSkillOn = true;
			Attack();
			castSkill();
		}
		stopSkill();
	}

	bool checkSkillTime()//判断技能使用时间
	{
		_currentskillTime = GetCurrentTime() / 1000.f - _startTime;
		if (_currentskillTime <= _maxskillTime)
			return true;
		else
			return false;
	}

	void stopSkill()//终止技能
	{
		_lastSkillTime = GetCurrentTime() / 1000.f;
		_currentskillTime = 0;
		_actorState->setMinAttackInterval(_actorState->getMinAttackInterval() * 2);
		_actorState->setCurrentSpeed(_actorState->getCurrentSpeed / 2);
		_isSkillOn = false;
	}
};

#endif//_KNIGHT_
