#pragma execution_character_set("utf-8")//使编码中文正常显示
#include "HeroChosen.h"
#include"constnumber.h"
USING_NS_CC;
using namespace ui;
std::string SWhatHasYouChooseToBeYourHero;

Scene* HeroChosen::createScene()
{
    auto scene = Scene::create();
    auto layer = HeroChosen::create();
    scene->addChild(layer);
    return scene;
}
bool HeroChosen::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto background = Sprite::create("HeroChosenBackground.png");
    if (background)
    {
        background->setScaleX(visibleSize.width / background->getTextureRect().getMaxX());
        background->setScaleY(visibleSize.height / background->getTextureRect().getMaxY());
        background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    }
    this->addChild(background);
        auto HeroKnight = Button::create("Knight.png");
        if (background && HeroKnight)
        {
            HeroKnight->setScaleX(visibleSize.width / background->getTextureRect().getMaxX() * 3);
            HeroKnight->setScaleY(visibleSize.height / background->getTextureRect().getMaxY() * 3);
            HeroKnight->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        }
        this->addChild(HeroKnight); 
        auto start_button = Button::create("HeroChose_start.png");
        if (background && start_button)
        {
            start_button->setScaleX(visibleSize.width / background->getTextureRect().getMaxX() * 1);
            start_button->setScaleY(visibleSize.height / background->getTextureRect().getMaxY() * 1);
            start_button->setPosition(Vec2(visibleSize.width*4 / 5, visibleSize.height*1 / 7));
        }
        start_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
        if (type == Widget::TouchEventType::ENDED) {
            // 切换到PreLoad场景
              // 切换到AudioControl场景
            SWhatHasYouChooseToBeYourHero = "Knight";
            auto transition = TransitionShrinkGrow::create(0.5, PreLoad::createScene());
            Director::getInstance()->replaceScene(transition);
        }
        });
        this->addChild(start_button);
        auto KinHP = Sprite::create("planeHP.png");
            if (background && KinHP)
            {
                KinHP->setScaleX(visibleSize.width / background->getTextureRect().getMaxX()/30*6);
                KinHP->setScaleY(visibleSize.height / background->getTextureRect().getMaxY()/3);
                KinHP->setAnchorPoint(Vec2(0, 0)); 
                KinHP->setPosition(Vec2(visibleSize.width/19, visibleSize.height * 45.4/80));
            }
            auto KinHPText = Text::create("6", "Arial", 25);
            KinHPText->setAnchorPoint(Vec2(0.5, 0));
            KinHPText->setPosition(Vec2(visibleSize.width *35/ 184, visibleSize.height * 45.4 / 80));
            this->addChild(KinHPText, KNIGHT);
       this->addChild(KinHP,KNIGHT);
       auto KinAR = Sprite::create("planeAR.png");
       if (background && KinAR)
       {
           KinAR->setScaleX(visibleSize.width / background->getTextureRect().getMaxX() / 30 * 5);
           KinAR->setScaleY(visibleSize.height / background->getTextureRect().getMaxY() / 3);
           KinAR->setAnchorPoint(Vec2(0, 0));
           KinAR->setPosition(Vec2(visibleSize.width / 19, visibleSize.height * 41.1 / 80));
       }
       this->addChild(KinAR, KNIGHT);
       auto KinARText = Text::create("5", "Arial", 25);
       KinARText->setAnchorPoint(Vec2(0.5, 0));
       KinARText->setPosition(Vec2(visibleSize.width * 35 / 184, visibleSize.height * 41.1 / 80));
       this->addChild(KinARText, KNIGHT);
       auto KinMP = Sprite::create("planeMP.png");
      
       this->addChild(KinHP, KNIGHT);
       if (background && KinMP)
       {
           KinMP->setScaleX(visibleSize.width / background->getTextureRect().getMaxX() / 30 * 4);
           KinMP->setScaleY(visibleSize.height / background->getTextureRect().getMaxY() / 3);
           KinMP->setAnchorPoint(Vec2(0, 0));
           KinMP->setPosition(Vec2(visibleSize.width / 19, visibleSize.height * 36.6 / 80));
       }
       this->addChild(KinMP, KNIGHT);
       auto KinMPText = Text::create("200", "Arial", 25);
       KinMPText->setAnchorPoint(Vec2(0.5, 0));
       KinMPText->setPosition(Vec2(visibleSize.width * 35 / 184, visibleSize.height * 36.6 / 80));
       this->addChild(KinMPText, KNIGHT);
       auto KinAttack = Sprite::create("planeAttack.png");
       if (background && KinAttack)
       {
           KinAttack->setScaleX(visibleSize.width / background->getTextureRect().getMaxX() / 30 * 5);
           KinAttack->setScaleY(visibleSize.height / background->getTextureRect().getMaxY() / 3);
           KinAttack->setAnchorPoint(Vec2(0, 0));
           KinAttack->setPosition(Vec2(visibleSize.width / 19, visibleSize.height * 32.4 / 80));
       }
       this->addChild(KinAttack, KNIGHT);
       auto KinATText = Text::create("5", "Arial", 25);
       KinATText->setAnchorPoint(Vec2(0.5, 0));
       KinATText->setPosition(Vec2(visibleSize.width * 35 / 184, visibleSize.height * 32.4 / 80));
       this->addChild(KinATText, KNIGHT);
       auto KinNameText = Text::create("骑士", "Arial", 165);
       KinNameText->setPosition(Vec2(visibleSize.width /2, visibleSize.height * 6/7));
       this->addChild(KinNameText, KNIGHT);
       auto KinSkillText = Text::create("短时间内\n使攻速增倍", "Arial", 35);
       KinSkillText->setPosition(Vec2(visibleSize.width*6 / 7, visibleSize.height* 0.7/2));
       this->addChild(KinSkillText, KNIGHT);
       auto KinSkillNameText = Text::create("火力全开", "Arial", 40);
       KinSkillNameText->setPosition(Vec2(visibleSize.width * 6.1 / 7, visibleSize.height * 1.3 / 2));
       this->addChild(KinSkillNameText, KNIGHT);
       auto SKILL = Sprite::create("OpenFire.png");
       SKILL->setScale(3);
       SKILL->setPosition(Vec2(visibleSize.width * 6.1 / 7, visibleSize.height * 1 / 2));
       this->addChild(SKILL);
       auto Back_button = Button::create("HeroChosenBack.png");
       if (background && Back_button)
       {
           Back_button->setScaleX(visibleSize.width / background->getTextureRect().getMaxX() * 1);
           Back_button->setScaleY(visibleSize.height / background->getTextureRect().getMaxY() * 1);
           Back_button->setPosition(Vec2(visibleSize.width * 1 / 5, visibleSize.height * 1 / 7));
       }
       Back_button->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
           if (type == Widget::TouchEventType::ENDED) {
               // 切换到PreLoad场景
                 // 切换到AudioControl场景
               auto transition = TransitionShrinkGrow::create(0.5, GameMenu::createScene());
               Director::getInstance()->replaceScene(transition);
           }
       });
       this->addChild(Back_button);
    }


