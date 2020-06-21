#pragma execution_character_set("utf-8")//使编码中文正常显示
#include "AfterDie.h"
#include"PreLoad.h"
#include"MenuScene.h"
#include"HeroChosen.h"
#include"SimpleAudioEngine.h"
using namespace ui;
Scene* AfterDie::createScene()
{
	auto scene = Scene::create();
	auto layer = AfterDie::create();
	scene->addChild(layer);
	return scene;
}

bool AfterDie::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
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
			// 切换到PreLoad场景
			  // 切换到AudioControl场景
			auto transition = TransitionShrinkGrow::create(0.5, GameMenu::createScene());
			Director::getInstance()->replaceScene(transition);
		}
	});
	this->addChild(Back_button);
	auto Continue_button = Button::create("ReTry.png");
	if (Continue_button)
	{
		Continue_button->setScaleX(0.75);
		Continue_button->setScaleY(0.75);
		Continue_button->setAnchorPoint(Vec2(0.5, 0.5));
		Continue_button->setPosition(Vec2(visibleSize.width * 1.1 / 2, visibleSize.height / 2));
	}
	Continue_button->addTouchEventListener([this](Ref* pSender, Widget::TouchEventType type) {
		if (type == Widget::TouchEventType::ENDED) {
			auto transition = TransitionShrinkGrow::create(0.5,HeroChosen::createScene());
			Director::getInstance()->replaceScene(transition);
		}
	});
	this->addChild(Continue_button, 9);
	auto AR_Text = Text::create("你已阵亡", "Arial", 90);
	AR_Text->setPosition(Vec2(visibleSize.width * 1 / 2, visibleSize.height * 1.2 / 2));
	this->addChild(AR_Text, 9);
	return true;
}
