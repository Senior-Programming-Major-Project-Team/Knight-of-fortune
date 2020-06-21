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

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "knight.h"
#include "Pig.h"
#include "LanceGoblin.h"
#include "Flower.h"
#include "HandGunGoblin.h"
#include "TommyGun.h"
#include "GameScene.h"


class Hero;
class Enemy;
class Weapon;
class GameScene;

class HelloWorld : public cocos2d::Scene
{

	CC_SYNTHESIZE(Direction, _pressdirection, PressDirection);
	CC_SYNTHESIZE(bool, _isCanMove, IsCanMove);
	CC_SYNTHESIZE(MapInfo, _mapInformation, MapInformation);
	CC_SYNTHESIZE(Hero*, _myHero, MyHero);
	CC_SYNTHESIZE(GameScene*, _mylayer, Mylayer);
	CC_SYNTHESIZE(ShowState*, _showState, ShowState);
	CC_SYNTHESIZE(Weapon*, _myWeapon, MyWeapon);
	CC_SYNTHESIZE(bool, _isFighting, IsFighting);

public:

	Vector<Enemy*> _enemies;

    static cocos2d::Scene* createScene();

    virtual bool init();

	void initstatedate();//初始化按键信息

	void initmap();

	void inithero();//初始化人物信息

	void initweapon();

	void initenemy();//初始化敌人信息

	void initpig();

	void initlancegoblin();

	void initflower();

	void inithandgungoblin();

	void Heromove();//人物移动
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	virtual bool onPressKey(EventKeyboard::KeyCode keyCode, Event* envet);

	virtual bool onReleaseKey(EventKeyboard::KeyCode keyCode, Event* envet);

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;//储存按键信息

	bool isKeyPressed(EventKeyboard::KeyCode keyCode);//判断按键是否一直被按住

	void update(float delta);

	void updateHero(float delta);

	void updateWeapon(float t);

	void updateEnemy(float delta);

	bool updateState(EventKeyboard::KeyCode keyCode, int type);//更新按键信息

	bool PressDirection();

	Vec2 RandomGeneration();

	void Stopfight();

	EventListenerKeyboard* listenerKeyBoard;//键盘监听

	bool _wState, _aState, _sState, _dState;
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
