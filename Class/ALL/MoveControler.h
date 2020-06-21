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
	cocos2d::Vec2 Speed;//ʵ���ٶȿ��ƣ����е�һ���ʾ�����ٶȣ��ڶ����ʾ�����ٶ�
	bool isMove;
	cocos2d::CCSprite* Rocker;//�м��СԲȦ
	float radius;
	cocos2d::Point Center;
	cocos2d::CCPoint ctrlPoint;
	cocos2d::CCAction* actionUp;
	cocos2d::CCAction* actionLeft;
	cocos2d::CCAction* actionRight;
	cocos2d::CCAction* actionDown;
	//�������ⰴ��
	virtual bool TouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void TouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void TouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	//���Ƽ��̵Ŀ���
	virtual bool PressingKey(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* envet);
	virtual bool LooseKey(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* envet);
	virtual bool updateState(cocos2d::EventKeyboard::KeyCode keyCode, int type);
	virtual bool updateDirection();
public:
	/**
   * ��̬����������Scene����
   */
	static cocos2d::Layer* createScene();
	/**
	 * init��������ɳ�ʼ��������
	 */
	virtual bool init();
	CREATE_FUNC(MoveControler);
};

