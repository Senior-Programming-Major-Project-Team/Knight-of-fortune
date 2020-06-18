#pragma once
#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H
#include"cocos2d.h"
#include"Buff.h"

USING_NS_CC;

class HealthPotion_1 :public Buff
{
public:
	virtual bool init();

	static HealthPotion_1* HealthPotion_1::create();
};

class HealthPotion_2 :public Buff
{
public:
	virtual bool init();

	static HealthPotion_2* HealthPotion_2::create();
};

class HealthPotion_3 :public Buff
{
public:
	virtual bool init();

	static HealthPotion_3* HealthPotion_3::create();
};

class HealthPotion_4 :public Buff
{
public:
	virtual bool init();

	static HealthPotion_4* HealthPotion_4::create();
};


#endif // !HEALTHPOTION_H
