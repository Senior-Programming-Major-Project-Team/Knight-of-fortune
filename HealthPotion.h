#pragma once
#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include"cocos2d.h"

#include"Potion.h"



USING_NS_CC;

class HealthPotion_1 :public Potion
{
	CC_SYNTHESIZE(HelloWorld*, _combatscene, Combatscene);
	CC_SYNTHESIZE(std::string, _potionName, PotionNme);
public:
	virtual bool init(HelloWorld* combatScene, std::string potionName);

	static HealthPotion_1* HealthPotion_1::create(HelloWorld* combatScene, std::string potionName);

};

class HealthPotion_2 :public Potion
{
	CC_SYNTHESIZE(HelloWorld*, _combatscene, Combatscene);
	CC_SYNTHESIZE(std::string, _potionName, PotionNme);
public:
	virtual bool init(HelloWorld* combatScene, std::string potionName);

	static HealthPotion_2* HealthPotion_2::create(HelloWorld* combatScene, std::string potionName);
};

class HealthPotion_3 :public Potion
{
	CC_SYNTHESIZE(HelloWorld*, _combatscene, Combatscene);
	CC_SYNTHESIZE(std::string, _potionName, PotionNme);
public:
	virtual bool init(HelloWorld* combatScene, std::string potionName);

	static HealthPotion_3* HealthPotion_3::create(HelloWorld* combatScene, std::string potionName);
};

class HealthPotion_4 :public Potion
{
	CC_SYNTHESIZE(HelloWorld*, _combatscene, Combatscene);
	CC_SYNTHESIZE(std::string, _potionName, PotionNme);

public:
	virtual bool init(HelloWorld* combatScene, std::string potionName);

	static HealthPotion_4* HealthPotion_4::create(HelloWorld* combatScene, std::string potionName);
};


#endif // !HEALTHPOTION_H
