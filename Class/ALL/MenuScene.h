#ifndef __MenuScene__
#define __MenuScene__

#include <iostream>
#include "cocos2d.h"
#include"HeroChosen.h"
#include "AudioControl.h"

// 1. GameMenu�����������ʾһ���˵����������û�ѡ�񡰿�ʼ��Ϸ�����ǡ���Ϸ���á���
class GameMenu : public cocos2d::Layer
{
public:
    /**
     * ��̬����������Scene����
     */
    static cocos2d::Scene* createScene();
    /**
     * init��������ɳ�ʼ��������
     */
    virtual bool init() ;
    CREATE_FUNC(GameMenu);
    bool initPause();
    bool removePause();
};

#endif /* defined(__MenuScene__) */