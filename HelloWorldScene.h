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

class Hero;

class HelloWorld : public cocos2d::Scene
{

	CC_SYNTHESIZE(Direction, _pressdirection, PressDirection);
	CC_SYNTHESIZE(bool, _isCanMove, IsCanMove);

public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	void initdate();

	void inithero();

	void Heromove(Hero* hero);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	virtual bool onPressKey(EventKeyboard::KeyCode keyCode, Event* envet, Hero*hero);

	virtual bool onReleaseKey(EventKeyboard::KeyCode keyCode, Event* envet, Hero*hero);

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	bool isKeyPressed(EventKeyboard::KeyCode keyCode);

	void update(float delta);

	bool updateState(EventKeyboard::KeyCode keyCode, int type);

	bool PressDirection();

	EventListenerKeyboard* listenerKeyBoard;//键盘监听

	bool _wState, _aState, _sState, _dState;
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

protected:
	Knight* knight = Knight::create(this, "knight", Camp::ME);
};

#endif // __HELLOWORLD_SCENE_H__
