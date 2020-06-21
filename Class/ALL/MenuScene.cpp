#pragma once
#pragma execution_character_set("utf-8")//ʹ��������������ʾ
#include "MenuScene.h"
#include "ui/CocosGUI.h"
#include"AfterDie.h"
USING_NS_CC;
using namespace ui;

Scene* GameMenu::createScene()
{
    // ����һ����������
    auto scene = Scene::create();
    // ���������
    auto layer = GameMenu::create();
    // ��GameMenu����Ϊ�ӽڵ���ӵ�����
    scene->addChild(layer);
    // ���س�������
    return scene;
}
bool GameMenu::init ()  {
    // ���ø����init����
    if (!Layer::init()) {
        return false;
    }
  
    // ����豸�ɼ���ͼ��С
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //���ñ���ͼƬ
    
    auto background = Sprite::create("background.png");
    if (background)
    {
        background->setScaleX(visibleSize.width/background->getTextureRect().getMaxX());
        background->setScaleY(visibleSize.height/ background->getTextureRect().getMaxY());
        background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height/2));
    }
    this->addChild(background);
    // ����ʼ��Ϸ����ť
    auto start_button = Button::create("start_button.png");
    float ButtonPicX = 218*4;
    float ButtonPicY = 80*6;
    start_button->setScaleX(visibleSize.width /ButtonPicX );
    start_button->setScaleY(visibleSize.height / ButtonPicY);
    start_button->setPosition(Vec2(visibleSize.width / 3.5, visibleSize.height * 0.25));
    start_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            // �л���ѡ�˳���
            auto transition = TransitionSlideInL::create(0.5, HeroChosen::createScene());
            Director::getInstance()->replaceScene(transition);
        }
    });
    this->addChild(start_button);

    // ����Ϸ���á���ť
    auto set_button = Button::create("set_button.png");
    float ButtonPic0 = 45 * 9;
    float fSize = visibleSize.width > visibleSize.height ? visibleSize.width : visibleSize.height;
    set_button->setScaleX(fSize / ButtonPic0);
    set_button->setScaleY(fSize / ButtonPic0);
    set_button->setPosition(Vec2(visibleSize.width / 10, visibleSize.height * 0.9));
    set_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            // �л���AudioControl����
            auto transition = TransitionShrinkGrow::create(0.5, AudioControl::createScene());
            Director::getInstance()->pushScene(transition);
        }
    });
    this->addChild(set_button);

    // ���˳���Ϸ����ť
    auto close_button = Button::create("Exit_button.png");
    close_button->setScaleX(visibleSize.width / ButtonPicX);
    close_button->setScaleY(visibleSize.height / ButtonPicY);
    close_button->setPosition(Vec2(visibleSize.width*(1-1 / 3.5), visibleSize.height * 0.25));
    close_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            Director::getInstance()->end();
            exit(0);
        }
    });
    this->addChild(close_button);
    // ���˳���Ϸ����ť
    return true;
}











