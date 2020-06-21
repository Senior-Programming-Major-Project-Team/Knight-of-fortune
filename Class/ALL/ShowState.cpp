#include "ShowState.h"
#include "SimpleAudioEngine.h"
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace ui;

ShowState* ShowState::createLayer()
{
	return ShowState::create();
}

std::string FtoS(float Number)
{
	char C[20];
	sprintf(C, "%f", Number);
	std::string S(C);
	return S;
}
bool ShowState::init()
{
	_HPMax = 6;
	_MPMax = 200;
	_ArmorMax = 5;
	Position = Vec2(0, 0);
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	/*auto background = Sprite::create("ShowStatebackground.png");
	if (background)
	{
		background->setScaleX(visibleSize.width / background->getTextureRect().getMaxX()/8*1.2);
		background->setScaleY(visibleSize.height / background->getTextureRect().getMaxY()/8*1.2);
		background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	}
	this->addChild(background,0);*/
	auto Size = Director::getInstance()->getVisibleSize();
	auto HP_Text = Text::create("HP", "Arial", 16);
	HP_Text->setPosition(Vec2(Position.x + Size.width / 11, Position.y + 7.9 * Size.height / 8));
	this->addChild(HP_Text, 0);
	auto loadingBarHP = LoadingBar::create("planeHP.png");
	loadingBarHP->setScale(0.5f);
	// 设置进度条百分比
	loadingBarHP->setPercent(100);
	// 设置进度条方向
	loadingBarHP->setDirection(LoadingBar::Direction::LEFT);
	// 设置进度条位置
	loadingBarHP->setPosition(Vec2(Position.x + Size.width / 4, Position.y + 7.9*Size.height / 8));
	auto MP_Text = Text::create("MP", "Arial", 16);
	MP_Text->setPosition(Vec2(Position.x + Size.width / 11, Position.y + 7.7 * Size.height / 8));
	this->addChild(MP_Text, 0);
	this->addChild(loadingBarHP, 1);//1,为血条，2为蓝条，3为护甲，4为金币
	auto loadingBarMP = LoadingBar::create("planeMP.png");
	loadingBarMP->setScale(0.5f);
	// 设置进度条百分比
	loadingBarMP->setPercent(100);
	// 设置进度条方向
	loadingBarMP->setDirection(LoadingBar::Direction::LEFT);
	// 设置进度条位置
	loadingBarMP->setPosition(Vec2(Position.x + Size.width / 4, Position.y + 7.7*Size.height / 8));
	this->addChild(loadingBarMP, 2);//1,为血条，2为蓝条，3为护甲，4为金币
	auto AR_Text = Text::create("ARMOR", "Arial", 16);
	AR_Text->setPosition(Vec2(Position.x + Size.width / 11, Position.y + 7.5 * Size.height / 8));
	this->addChild(AR_Text, 0);
	auto loadingBarAR = LoadingBar::create("planeAR.png");
	loadingBarAR->setScale(0.5f);
	// 设置进度条百分比
	loadingBarAR->setPercent(100);
	// 设置进度条方向
	loadingBarAR->setDirection(LoadingBar::Direction::LEFT);
	// 设置进度条位置
	loadingBarAR->setPosition(Vec2(Position.x + Size.width / 4, Position.y + 7.5 * Size.height / 8));
	this->addChild(loadingBarAR, 2);//1,为血条，2为蓝条，3为护甲，4为金币
	//auto Money_Text = Text::create("Money: 0", "Arial", 16);
	//Money_Text->setPosition(Vec2(Position.x + Size.width / 10, Position.y + 0.5 * Size.height / 8));
   // this->addChild(Money_Text, 4);
	//this->scheduleUpdate();
}

void ShowState::update(Hero* hero)
{
	float _HPInterval = 0;
	float _MPInterval = 0;
	float _ArInterval = 0;
	//调用接口找到当前的Hp，Mp，Ar，Money;
	_HPInterval = 1;
	_MPInterval = 1;
	_ArInterval = 1;
	LoadingBar* LoadingBarSet;
	LoadingBarSet = static_cast<LoadingBar*>(this->getChildByTag(1));
	//LoadingBarSet->setPercent(1.0);
	//LoadingBarSet = static_cast<LoadingBar*>(this->getChildByTag(2));
	//LoadingBarSet->setPercent(1.0);
	//LoadingBarSet = static_cast<LoadingBar*>(this->getChildByTag(3));
	//LoadingBarSet->setPercent(1.0);
}







