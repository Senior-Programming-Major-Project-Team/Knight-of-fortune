#pragma once
#ifndef MAGMA_H
#define MAGMA_H

#include"cocos2d.h"

#include"Buff.h"

USING_NS_CC;

class Magma :public Buff
{
public:
	virtual bool init(HelloWorld* combatScene, std::string buffName, Hero* hero);

	static Magma* create(HelloWorld* combatScene, std::string buffName, Hero* hero);


};
#endif // !MAGMA_H
