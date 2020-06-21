#pragma once
#ifndef POTION_H
#define POTION_H

#include"cocos2d.h"

#include"Hero.h"

USING_NS_CC;

class HelloWorld;

class Potion :public Sprite
{
	CC_SYNTHESIZE(float, _armor, Armor);
	CC_SYNTHESIZE(float, _HP, HP);
	CC_SYNTHESIZE(float, _MP, MP);
	CC_SYNTHESIZE(float, _attack, Attack);
	CC_SYNTHESIZE(HelloWorld*, _combatscene, Combatscene);
	CC_SYNTHESIZE(std::string, _potionName, PotionNme);
	CC_SYNTHESIZE(Hero*, _hero, myhero);
public:
	virtual bool init(HelloWorld* combatScene, std::string potionName, Hero* hero);

	static Potion* Potion::create(HelloWorld* combatScene, std::string potionName, Hero* hero);

	virtual void update(float t);


};


#endif // !POTION_H
