#pragma once
#ifndef MARSH_H
#define MARSH_H

#include"cocos2d.h"

#include"Buff.h"

USING_NS_CC;

class Marsh :public Buff
{
public:
	virtual bool init(HelloWorld* combatScene, std::string buffName, Hero* hero);

	static Marsh* create(HelloWorld* combatScene, std::string buffName, Hero* hero);


};

#endif // !MARSH_H
