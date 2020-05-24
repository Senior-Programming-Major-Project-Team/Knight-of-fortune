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

//  AudioControl���������ñ������ֺ�������Ч
class AudioControl : public cocos2d::Layer
{
public:
    /**
     * ��̬����������Scene����
     */
    static cocos2d::Scene* createScene();
    /**
     * init��������ɳ�ʼ��������
     */
    virtual bool init();
    CREATE_FUNC(AudioControl);
};


#endif /* defined(_AudioControl_) */
