#pragma once

#include"cocos2d.h"
#include <iostream>
#include "SimpleAudioEngine.h"
//#include "GameScene.h"

USING_NS_CC;
using namespace CocosDenshion;
class PreLoad : public cocos2d::Layer
{
protected:
    // ����������Ϸ��Ҫ���ص���Դ����
    int _sourceCount;
    // ������
    ProgressTimer* _progress;
    // ���������µĴ���
    float _progressInterval;
public:
    /**
     * ��̬����������Scene����
     * ע�⣺��Cocos2d-x��û��Cocos2d-iPhone�еġ�id��,���鷵����ʵ����ָ��
     */
    static cocos2d::Scene* createScene();
    /**
     * init��������ɳ�ʼ��������
     * ע�⣺init������Cocos2d-x�з���boolֵ�������Ƿ���Cocos2d-iPhone�еġ�id��
     */
    virtual bool init();

    virtual void onEnterTransitionDidFinish();

    // ���ر�������
    void loadMusic(std::vector<std::string> musicFiles);
    // ������Ϸ��Ч
    void loadEffect(std::vector<std::string> EffectFiles);
    // ���ؾ����
    /*void loadSpriteSheets(ValueVector spriteSheets);
    // ������Ϸ������*/
    void progressUpdate();

    /**
     * ʹ��CREATE_FUNC�괴����ǰ��Ķ��󣬷��صĶ��󽫻����Զ��ͷųع����ڴ���ͷ�
     */
    CREATE_FUNC(PreLoad);
};

