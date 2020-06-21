#pragma once
#ifndef HeroChosenScene
#define HeroChosenScene

//#include "C:\Users\Administrator\codes\MyCppGame\cocos2d\cocos\2d\CCLayer.h"
#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include"PreLoad.h"
#include<string>
#include<AudioControl.h>
#include<MenuScene.h>
//#include "Hero.h"
class HeroChosen : public cocos2d::Layer
{
public:
    /**
     * 静态函数，创建Scene场景
     */
    static cocos2d::Scene* createScene();
    /**
     * init函数，完成初始化操作。
     */
    virtual bool init();
    CREATE_FUNC(HeroChosen);
};

#endif // !HeroChosenScene


