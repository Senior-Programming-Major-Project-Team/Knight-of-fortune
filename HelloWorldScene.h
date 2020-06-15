#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "knight.h"

class Hero;

class HelloWorld : public cocos2d::Scene
{

	CC_SYNTHESIZE(Direction, _pressdirection, PressDirection);
	CC_SYNTHESIZE(bool, _isCanMove, IsCanMove);

public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void initstatedate();//初始化按键信息

	void inithero();//初始化人物信息

	void Heromove(Hero* hero);//人物移动
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	virtual bool onPressKey(EventKeyboard::KeyCode keyCode, Event* envet, Hero*hero);

	virtual bool onReleaseKey(EventKeyboard::KeyCode keyCode, Event* envet, Hero*hero);

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//储存按键信息

	bool isKeyPressed(EventKeyboard::KeyCode keyCode);//判断按键是否一直被按住

	void update(float delta);

	bool updateState(EventKeyboard::KeyCode keyCode, int type);//更新按键信息

	bool PressDirection();

	EventListenerKeyboard* listenerKeyBoard;//键盘监听

	bool _wState, _aState, _sState, _dState;
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

protected:
	Knight* knight = Knight::create(this, "knight", Camp::ME);
};

#endif // __HELLOWORLD_SCENE_H__
