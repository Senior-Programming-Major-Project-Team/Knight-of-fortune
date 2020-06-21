#pragma once

#include"cocos2d.h"
#include "SimpleAudioEngine.h"
#include<iostream>
#include "ui/CocosGUI.h"
#include "Hero.h"

using namespace cocos2d;
class ShowState:public Layer
{
private:
	float _HPMax;
	/*获得当前角色的HP值*/
	float _MPMax;
	/*获得当前角色的MP值*/
	float _ArmorMax;
	float getArmor;
	Vec2 Position;
public:
	/*创造状态的显示界面*/
	static ShowState* createLayer();
	/*用于完成显示界面的初始化*/
	virtual bool init();
	CREATE_FUNC(ShowState);
	void update(Hero* hero);
};

