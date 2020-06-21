#pragma once
#include "C:\Users\Administrator\codes\MyCppGame\cocos2d\cocos\2d\CCLayer.h"
#include"cocos2d.h"
#include"constnumber.h"

extern std::string SWhatHasYouChooseToBeYourHero;

class MoveControler :
	public cocos2d::Layer
{
private:
	cocos2d::CCSprite* player;
	cocos2d::Vec2 Speed;//实现速度控制，其中第一项表示横向速度，第二项表示纵向速度
	bool isMove;
	cocos2d::CCSprite* Rocker;//中间的小圆圈
	float radius;
	cocos2d::Point Center;
	cocos2d::CCPoint ctrlPoint;
	cocos2d::CCAction* actionUp;
	cocos2d::CCAction* actionLeft;
	cocos2d::CCAction* actionRight;
	cocos2d::CCAction* actionDown;
	//控制虚拟按键
	virtual bool TouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void TouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void TouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	//控制键盘的控制
	virtual bool PressingKey(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* envet);
	virtual bool LooseKey(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* envet);
	virtual bool updateState(cocos2d::EventKeyboard::KeyCode keyCode, int type);
	virtual bool updateDirection();
public:
	/**
   * 静态函数，创建Scene场景
   */
	static cocos2d::Layer* createScene();
	/**
	 * init函数，完成初始化操作。
	 */
	virtual bool init();
	CREATE_FUNC(MoveControler);
};

