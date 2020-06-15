#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "constnumber.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
	initdate();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Soul Knight", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    /*auto sprite = Sprite::create("soulknight.png");
    if (sprite == nullptr)
    {
        problemLoading("'soulknight.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }*/
	inithero();
	scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta) //更新按键信息（wasd）
{
	Node::update(delta);
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW;
	auto rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	auto upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW;
	auto downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
	if (isKeyPressed(upArrow))
	{
		_wState = true;
		_sState = false;
	}
	else if (isKeyPressed(leftArrow)) 
	{
		_aState = true;
		_dState = false;
	}
	else if (isKeyPressed(downArrow))
	{
		_sState = true;
		_wState = false;
	}
	else if (isKeyPressed(rightArrow))
	{
		_dState = true;
		_aState = false;
	}
	Heromove(knight);
}

void HelloWorld::inithero()
{
	knight->setPosition(Vec2(100, 100));
	knight->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(knight);
	listenerKeyBoard = EventListenerKeyboard::create();
	//创建键盘监听
	listenerKeyBoard->onKeyPressed = CC_CALLBACK_2(HelloWorld::onPressKey, this, knight);
	listenerKeyBoard->onKeyReleased = CC_CALLBACK_2(HelloWorld::onReleaseKey, this, knight);
	//绑定键盘监听
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyBoard, this);
	//开启监听
}

void HelloWorld::initstatedate()
{
	_pressdirection = Direction::NO;
	_isCanMove = false;
	_wState = false;
	_aState = false;
	_sState = false;
	_dState = false;
}

void HelloWorld::Heromove(Hero* hero)
{
	PressDirection();
	stopAllActions();
	_isCanMove = true;
	Point point;

	if (_pressdirection == Direction::NO)
	{
		_isCanMove = false;
	}

	switch (_pressdirection)
	{
	case Direction::DOWN:
	{
		point = Vec2(0, -1);
		break;
	}
	case Direction::DOWNLEFT:
	{
		point = Vec2(-1, -1);
		break;
	}
	case Direction::DOWNRIGHT:
	{
		point = Vec2(1, -1);
		break;
	}
	case Direction::UP:
	{
		point = Vec2(0, 1);
		break;
	}
	case Direction::UPLEFT:
	{
		point = Vec2(-1, 1);
		break;
	}
	case Direction::UPRIGHT:
	{
		point = Vec2(1, 1);
		break;
	}
	case Direction::LEFT:
	{
		point = Vec2(-1, 0);
		break;
	}
	case Direction::RIGHT:
	{
		point = Vec2(1, 0);
		break;
	}
	}
	hero->heroMove(point);
}

bool HelloWorld::onPressKey(EventKeyboard::KeyCode keyCode, Event* envet, Hero* hero)
{
	updateState(keyCode, PRESS);
	return true;
}

bool HelloWorld::onReleaseKey(EventKeyboard::KeyCode keyCode, Event * envet, Hero*hero)
{
	updateState(keyCode, RELEASE);
	if (!_isCanMove)
	{
		return true;
	}
	if (_pressdirection == Direction::NO)
	{
		stopAllActions();
		hero->runAction(MoveTo::create(0.08, hero->getPosition()));
		_isCanMove = false;
	}
	return true;
}

bool HelloWorld::isKeyPressed(EventKeyboard::KeyCode keyCode) 
{
	if (keys[keyCode]) 
		return true;
	else
		return false;
}

bool HelloWorld::updateState(EventKeyboard::KeyCode keyCode, int type)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
	{
		if (type == PRESS)
		{
			keys[keyCode] = true;
			_wState = true;
			_sState = false;
		}
		else if (type == RELEASE)
		{
			keys[keyCode] = false;
			_wState = false;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_A:
	{
		
		if (type == PRESS)
		{
			keys[keyCode] = true;
			_aState = true;
			_dState = false;
		}
		else if (type == RELEASE)
		{
			keys[keyCode] = false;
			_aState = false;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_S:
	{
		if (type == PRESS)
		{
			keys[keyCode] = true;
			_sState = true;
			_wState = false;
		}
		else if (type == RELEASE)
		{
			keys[keyCode] = false;
			_sState = false;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_D:
	{
		if (type == PRESS)
		{
			keys[keyCode] = true;
			_dState = true;
			_aState = false;
		}
		else if (type == RELEASE)
		{
			keys[keyCode] = false;
			_dState = false;
		}
		break;
	}
	case EventKeyboard::KeyCode::KEY_E://开启技能
	{
		if (type == PRESS)
		{
			knight->castSkill();
		}
		break;
	}
	default:
		break;
	}
	PressDirection();
	return true;
}

bool HelloWorld::PressDirection()
{
	if (_wState)
	{
		if (_aState)
		{
			_pressdirection = Direction::UPLEFT;
		}
		else if (_dState)
		{
			_pressdirection = Direction::UPRIGHT;
		}
		else
		{
			_pressdirection = Direction::UP;
		}
	}
	else if (_sState)
	{
		if (_aState)
		{
			_pressdirection = Direction::DOWNLEFT;
		}
		else if (_dState)
		{
			_pressdirection = Direction::DOWNRIGHT;
		}
		else
		{
			_pressdirection = Direction::DOWN;
		}
	}
	else
	{
		if (_aState)
		{
			_pressdirection = Direction::LEFT;
		}
		else if (_dState)
		{
			_pressdirection = Direction::RIGHT;
		}
		else
		{
			_pressdirection = Direction::NO;
		}
	}
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
