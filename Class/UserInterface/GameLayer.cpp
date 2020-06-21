// ������ͣ��ť
#pragma execution_character_set("utf-8")//ʹ��������������ʾ
#include"GameLayer.h"
#include "ui/CocosGUI.h"
#include"MenuScene.h"
#include "SimpleAudioEngine.h"
using namespace ui;

void GameLayer::TouchPaushButton()
{
    // ���浱ǰ����ͼ
    auto _visibleSize = Director::getInstance()->getVisibleSize();
    renderTexture = CCRenderTexture::create(_visibleSize.width, _visibleSize.height);
  //����ʵ����ͨ��CCRenderTexture���浱ǰ���棨�൱�ڽ�������Ȼ�󴫵ݸ���ͣ���棬���ɱ�������  
 // ������ͣ�Ի���
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    Director::sharedDirector()->pushScene(createScene());
}

Scene* GameLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = GameLayer::create();
    scene->addChild(layer);
    return scene;
}
bool GameLayer:: init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto Back_button = Button::create("Home.png");
    if (Back_button)
    {
        Back_button->setScaleX(1);
        Back_button->setScaleY(1);
        Back_button->setAnchorPoint(Vec2(0.5, 0.5));
        Back_button->setPosition(Vec2(visibleSize.width * 0.9 / 2, visibleSize.height / 2));
    }
    Back_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            // �л���PreLoad����
              // �л���AudioControl����
            auto transition = TransitionShrinkGrow::create(0.5, GameMenu::createScene());
            Director::getInstance()->replaceScene(transition);
        }
    });
    this->addChild(Back_button, 9);
    auto Continue_button = Button::create("HeroChose_start.png");
    if (Continue_button)
    {
        Continue_button->setScaleX(0.75);
        Continue_button->setScaleY(0.75);
        Continue_button->setAnchorPoint(Vec2(0.5, 0.5));
        Continue_button->setPosition(Vec2(visibleSize.width * 1.1 / 2, visibleSize.height / 2));
    }
    Continue_button->addTouchEventListener([this](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
            Director::sharedDirector()->popScene();
        }
    });
    this->addChild(Continue_button, 9);
    auto AR_Text = Text::create("��ͣ", "Arial", 98);
    AR_Text->setPosition(Vec2(visibleSize.width * 1 / 2, visibleSize.height * 1.2 / 2));
    this->addChild(AR_Text, 9);
    return true;
}
