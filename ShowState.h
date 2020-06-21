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
	/*��õ�ǰ��ɫ��HPֵ*/
	float _MPMax;
	/*��õ�ǰ��ɫ��MPֵ*/
	float _ArmorMax;
	float getArmor;
	Vec2 Position;
	ui::LoadingBar* _HP;
	ui::LoadingBar* _MP;
	ui::LoadingBar* _AR;
	ui::Text* _HPT;
	ui::Text* _MPT;
	ui::Text* _ART;
public:
public:
public:
	/*����״̬����ʾ����*/
	static ShowState* createLayer();
	/*���������ʾ����ĳ�ʼ��*/
	virtual bool init();
	CREATE_FUNC(ShowState);
	void update(float delta);
};

