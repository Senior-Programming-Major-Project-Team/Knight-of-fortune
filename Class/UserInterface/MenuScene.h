#ifndef __MenuScene__
#define __MenuScene__

#include <iostream>
#include "cocos2d.h"
//#include "PreLoadScene.h"
#include "AudioControl.h"

// 1. GameMenu类的作用是显示一个菜单场景，让用户选择“开始游戏”或是“游戏设置”。
class GameMenu : public cocos2d::Layer
{
public:
    /**
     * 静态函数，创建Scene场景
     */
    static cocos2d::Scene* createScene();
    /**
     * init函数，完成初始化操作。
     */
    virtual bool init() ;
    CREATE_FUNC(GameMenu);
};

#endif /* defined(__MenuScene__) */
