#pragma once

#ifndef BUFF_H

#define BUFF_H

#include"cocos2d.h"


#include"Hero.h"

class HelloWorld;

USING_NS_CC;

class Buff :public Sprite
{
	CC_SYNTHESIZE(float, _armor, Armor);
	CC_SYNTHESIZE(float, _HP, HP);
	CC_SYNTHESIZE(float, _MP, MP);
	CC_SYNTHESIZE(float, _attack, Attack);
	CC_SYNTHESIZE(float, _beginTime, BeginTime);
	CC_SYNTHESIZE(float, _endTime, EndTime);
	CC_SYNTHESIZE(float, _duration, Duration);
	CC_SYNTHESIZE(HelloWorld*, _combatscene, Combatscene);
	CC_SYNTHESIZE(std::string, _buffName, BuffNme);
	CC_SYNTHESIZE(Hero*, _hero,myhero);
	CC_SYNTHESIZE(float, _speed, Speed);

public:
	virtual bool init(HelloWorld* combatScene, std::string buffName, Hero* hero,float armor, float hp, float mp, float attack, float beginTime, float endTime, float duration);

	static Buff* create(HelloWorld* combatScene, std::string buffName, Hero* hero, float armor, float hp, float mp, float attack, float beginTime, float endTime, float duration);
};


#endif // !BUFF_H
