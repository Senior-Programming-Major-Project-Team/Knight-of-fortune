/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

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
	initstatedate();
	initmap();
	inithero();
	initweapon();
	initenemy();
	this->scheduleUpdate();
    this->schedule(schedule_selector(HelloWorld::updateEnemy), 0.1f);

    return true;
}

void HelloWorld::update(float delta) 
{
	updateHero(0);
	updateWeapon(0);
}

void HelloWorld::initmap()
{
	_mylayer = GameScene::create();
	this->addChild(_mylayer);
	_mapInformation = _mylayer->getMapInformation();
}

void HelloWorld::inithero()
{
	_myHero = Knight::create(this, "knight", Camp::ME);
	addChild(_myHero);
	_myHero->setPosition(Vec2(100, 100));
	_myHero->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	listenerKeyBoard = EventListenerKeyboard::create();
	//�������̼���
	listenerKeyBoard->onKeyPressed = CC_CALLBACK_2(HelloWorld::onPressKey, this,);
	listenerKeyBoard->onKeyReleased = CC_CALLBACK_2(HelloWorld::onReleaseKey, this);
	//�󶨼��̼���
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyBoard, this);
	//��������
}

void HelloWorld::initweapon()
{
	_myWeapon = TommyGun::create(this, "tommygun.png", _myHero);

	_myWeapon->setTexture("tommygun.png");

	this->addChild(_myWeapon);

	_myWeapon->openFire(this);

	_myWeapon->setPosition(110, 110);
}

void HelloWorld::initenemy()
{
	for (int i = 0; i < 12; i++)
	{
		srand(time(0) + rand());
		int enemynumber = CCRANDOM_0_1() * 4;
		switch (enemynumber)
		{
		case 0:initpig(); break;
		case 1:initlancegoblin(); break;
		case 3:initflower(); break;
		case 2:inithandgungoblin(); break;
		}
	}
}

void HelloWorld::initpig()
{
	Pig* pig = Pig::create(this, "Pig", Camp::ENEMY);
	_enemies.pushBack(pig);
	addChild(pig);
	Vec2 position = HelloWorld::RandomGeneration();
	pig->setPosition(position);
	pig->setAnchorPoint(Vec2::ANCHOR_MIDDLE);	
}

void HelloWorld::initlancegoblin()
{
	LanceGoblin* lanceGoblin = LanceGoblin::create(this, "LanceGoblin", Camp::ENEMY);
	_enemies.pushBack(lanceGoblin);
	addChild(lanceGoblin);
	Vec2 position = HelloWorld::RandomGeneration();
	lanceGoblin->setPosition(position);
	lanceGoblin->setAnchorPoint(Vec2::ANCHOR_MIDDLE);	
}

void HelloWorld::initflower()
{
	Flower* flower = Flower::create(this, "Flower", Camp::ENEMY);
	_enemies.pushBack(flower);
	addChild(flower);
	Vec2 position = HelloWorld::RandomGeneration();
	flower->setPosition(position);
	flower->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
}

void HelloWorld::inithandgungoblin()
{
	HandGunGoblin* handGunGoblin = HandGunGoblin::create(this, "HandGunGoblin", Camp::ENEMY);
	_enemies.pushBack(handGunGoblin);	
	addChild(handGunGoblin);
	Vec2 position = HelloWorld::RandomGeneration();
	handGunGoblin->setPosition(position);
	handGunGoblin->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
}

Vec2 HelloWorld::RandomGeneration()
{
	srand(time(0) + rand());
	Point point;
	point.x = CCRANDOM_0_1() * 850;
	point.y = CCRANDOM_0_1() * 850;
	return point;
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

void HelloWorld::updateHero(float delta)//����������Ϣ��wasd��
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
	Heromove();
	_myHero->Recover();
}

void HelloWorld::updateWeapon(float t)
{
	_myWeapon->update(_enemies);
}

void HelloWorld::updateEnemy(float delta)//���¹�����Ϣ
{
	int deadenemies = 0;
	for (auto& i : _enemies)
	{
		if (i->getAlreadyDead() == false)
		{
			switch (i->getEnemyType())
		    {
			case EType::PIG:
		    {
				i->automove();
			    i->Attack(_myHero, i);
			break;
		    }
		    case EType::LANCEGOBLIN:
		    {
				i->automove();
			    i->Attack(_myHero, i);
			break;
		    }
		    case EType::FLOWER:
		    {
				i->Attack(_myHero, i);
			    break;
		    }
		    case EType::HANDGUNGOBLIN:
		    {
				i->automove();
			    i->Attack(_myHero, i);
			break;
		    }
		    }
		}
		
		if (i->getAlreadyDead() == true)
		{
			i->removeFromParent();
			deadenemies++;
		}
	}
	if (deadenemies == 12)
	{
		_isFighting = false;
		Stopfight();
	}
}

void HelloWorld::Heromove()
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
	_myHero->heroMove(point);
}

void HelloWorld::Stopfight()
{
	_enemies.clear();
	if (_enemies.empty() == true)
	{
		_myHero->die();
	}
	//Size visibleSize = Director::getInstance()->getVisibleSize();
	//Point origin = Director::getInstance()->getVisibleOrigin();
	//auto TransferMatrix = ParticleSystemQuad::create("TransferMatrix.plist");
	//TransferMatrix->setPosition(visibleSize / 2);
	//TransferMatrix->setScale(0.5);
	//addChild(TransferMatrix);
}

bool HelloWorld::onPressKey(EventKeyboard::KeyCode keyCode, Event* envet)
{
	updateState(keyCode, PRESS);
	return true;
}

bool HelloWorld::onReleaseKey(EventKeyboard::KeyCode keyCode, Event * envet)
{
	updateState(keyCode, RELEASE);
	if (!_isCanMove)
	{
		return true;
	}
	if (_pressdirection == Direction::NO)
	{
		stopAllActions();
		_myHero->runAction(MoveTo::create(0.08, _myHero->getPosition()));
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
	case EventKeyboard::KeyCode::KEY_E://��������
	{
		if (type == PRESS)
		{
			_myHero->castSkill();
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