#pragma once
#ifndef _AfterDieScene
//#include "C:\Users\Administrator\codes\Knight\cocos2d\cocos\2d\CCLayer.h"
#include"cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
using namespace cocos2d;
class AfterDie :
	public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(AfterDie);
};
#endif // !_AfterDieScene

