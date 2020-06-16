#include "HeroChosen.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include"PreLoad.h"
#include<string>

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
        auto HeroKnight = Button::create("Knight.png", "KnigntSelected.png");
        if (background && HeroKnight)
        {
            HeroKnight->setScaleX(visibleSize.width / background->getTextureRect().getMaxX() * 3);
            HeroKnight->setScaleY(visibleSize.height / background->getTextureRect().getMaxY() * 3);
            HeroKnight->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
        }
            HeroKnight->addTouchEventListener([](Ref* pSender, Widget::TouchEventType type) {
            if (type == Widget::TouchEventType::ENDED) {
                // 切换到PreLoad场景
                SWhatHasYouChooseToBeYourHero = "Knight";
                auto transition = TransitionShrinkGrow::create(0.5, PreLoad::createScene());
                Director::getInstance()->replaceScene(transition);
            }
        });
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
        auto HP = Sprite::create("blood.png");
            if (background && HP)
            {
                HP->setScaleX(visibleSize.width / background->getTextureRect().getMaxX());
                HP->setScaleY(visibleSize.height / background->getTextureRect().getMaxY());
                HP->setPosition(Vec2(visibleSize.width/3, visibleSize.height * 3 / 4));
            }
       this->addChild(HP);
    }


