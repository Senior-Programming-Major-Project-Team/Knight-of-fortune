#pragma once
#include "C:\Users\Administrator\codes\MyCppGame\cocos2d\cocos\2d\CCLayer.h"
#include "cocos2d.h"
#include "Hero.h"
#include"MapInfo.h"
#include"ShowState.h"
extern Hero* HWhatHasYouChooseToBeYourHero;
class GameScene :
	public cocos2d::Layer
{
private:
	Hero* MyHero;
	Point BornPosition;
    /*该函数用于构建传送法阵*/
    void AddTransferMatriax();
	//初始化
	bool initMapLayer();
	/*void initListener();*/
	//帧更新
	void updateMap();
	//netWork
	//监听
	//监听器
	//EventListenerTouchOneByOne* listenerTouch;
	//EventListenerKeyboard* listenerKeyBoard;
	////鼠标点击事件
	//virtual bool onTouchBegan(Touch* touch, Event* event);
	////按键事件
	//virtual bool onPressKey(EventKeyboard::KeyCode keyCode, Event* event);
	//virtual bool onReleaseKey(EventKeyboard::KeyCode keyCode, Event* event);
	////判断是否一直被按住
	//std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	//bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	////鼠标监听器
	//bool _isMouseSprite;
	//Sprite* _mouseSprite;
	//EventListenerMouse* listenerMouse;
	//virtual bool onMouseMove(Event* event);
	//void updateSkillPanel();
	//bool gameEnd();
	//void changeScene(float delta);
	//void synchronize();

	Vec2 getPositionInMap(const Vec2& mousePosition);
public:
   /*公开容器*/
    CC_SYNTHESIZE(Size, _visibleSize, VisibleSize);
    CC_SYNTHESIZE(Vec2, _origin, Origin);

    CC_SYNTHESIZE(TMXTiledMap*, _map, Map);
    CC_SYNTHESIZE(MapInfo, _mapInformation, MapInformation);
    /**
    * 静态函数，创建Scene场景
    */
    static cocos2d::Scene* createScene();
    /**
     * init函数，完成初始化操作。
     */
    virtual bool init();
    CREATE_FUNC(GameScene);
    /*该函数判断是否可以产生传送阵了*/
    //bool IsCouldTransfer();
};


