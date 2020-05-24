#pragma once
//
//  AudioControl.h
#pragma once
#ifndef _AudioControl_
#define  _AudioControl_

#include <iostream>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "extensions/GUI/CCControlExtension/CCControlSlider.h"
#include "MenuScene.h"
using namespace CocosDenshion;
using namespace cocos2d::extension;

//  AudioControl类用来设置背景音乐和声音特效
class AudioControl : public cocos2d::Layer
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
    CREATE_FUNC(AudioControl);
};


#endif /* defined(_AudioControl_) */
