#include "ShowState.h"
#include "SimpleAudioEngine.h"
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<knight.h>
using namespace ui;
extern Hero* HWhatHasYouChooseToBeYourHero;
ShowState* ShowState::createLayer()
{
	return ShowState::create();
}

std::string FtoS(INT32 Number)
{
	char C[20];
	sprintf(C, "%d", Number);
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
	_HP = loadingBarHP;
	_HPT= Text::create("6/6", "Arial", 12);
	_HPT->setPosition(Vec2(Position.x + Size.width*1.7 / 4, Position.y + 7.9 * Size.height / 8));
	this->addChild(_HPT);
	this->addChild(loadingBarHP, 1);//1,为血条，2为蓝条，3为护甲，4为金币
	auto MP_Text = Text::create("MP", "Arial", 16);
	MP_Text->setPosition(Vec2(Position.x + Size.width / 11, Position.y + 7.7 * Size.height / 8));
	this->addChild(MP_Text, 0);
	
	auto loadingBarMP = LoadingBar::create("planeMP.png");
	loadingBarMP->setScale(0.5f);
	// 设置进度条百分比
	loadingBarMP->setPercent(100);
	// 设置进度条方向
	loadingBarMP->setDirection(LoadingBar::Direction::LEFT);
	// 设置进度条位置
	loadingBarMP->setPosition(Vec2(Position.x + Size.width / 4, Position.y + 7.7*Size.height / 8));
	_MP = loadingBarMP;
	loadingBarMP->setName("MP");
	_MPT = Text::create("200/200", "Arial", 12);
	_MPT->setPosition(Vec2(Position.x + Size.width*1.7 / 4, Position.y + 7.7 * Size.height / 8));
	this->addChild(_MPT);
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
	_AR = loadingBarAR;
	
	this->addChild(loadingBarAR, 3);//1,为血条，2为蓝条，3为护甲，4为金币
	auto _ARTE = Text::create("5/5", "Arial", 16);
	_ARTE->setPosition(Vec2(Position.x + Size.width *1.7/ 4, Position.y + 7.5 * Size.height / 8));
	this->addChild(_ARTE);
	_ART = _ARTE;
	//auto Money_Text = Text::create("Money: 0", "Arial", 16);
	//Money_Text->setPosition(Vec2(Position.x + Size.width / 10, Position.y + 0.5 * Size.height / 8));
   // this->addChild(Money_Text, 4);
	//this->scheduleUpdate();
	return true;
}

void ShowState::update(float delta)
{
	Layer::update(delta);
	float _HPInterval = 1;
	float _MPInterval = 1;
	float _ArInterval = 1;
	float _HPNow = 6,_MPNow=200,_ARNow=5;
    _HPNow = HWhatHasYouChooseToBeYourHero->getCurrentHealth();
    _MPNow = HWhatHasYouChooseToBeYourHero->getCurrentMagic();
    _ARNow = HWhatHasYouChooseToBeYourHero->getCurrentArmor();
	_HPInterval = _HPNow/ _HPMax;
	_MPInterval = _MPNow / _MPMax;
	_ArInterval = _ARNow / _ArmorMax;
	//调用接口找到当前的Hp，Mp，Ar，Money;
	_HP->setPercent(_HPInterval*100);
    _AR->setPercent(_ArInterval*100);
	_MP->setPercent(_MPInterval*100);
	_HPT->setString(FtoS(_HPNow) + "/6");
	_MPT->setString(FtoS(_MPNow) + "/200");
	_ART->setString(FtoS(_ARNow) + "/5");
}







