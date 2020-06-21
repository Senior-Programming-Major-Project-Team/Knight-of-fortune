#pragma once
#ifndef POTION_H
#define POTION_H

#include"cocos2d.h"


USING_NS_CC;

class HelloWorld;

class Potion :public Sprite
{
	CC_SYNTHESIZE(float, _maxHP, MaxHP);
	CC_SYNTHESIZE(float, _maxAR, MaxAR);
	CC_SYNTHESIZE(float, _HP, HP);
	CC_SYNTHESIZE(float, _MP, MP);
	CC_SYNTHESIZE(HelloWorld*, _combatscene, Combatscene);
	CC_SYNTHESIZE(String, _potionName, PotionName);
public:
	virtual bool init(HelloWorld* combatScene, std::string potionName);

	static Potion* Potion::create(HelloWorld* combatScene, std::string potionName);


};


#endif // !POTION_H
