#ifndef _MAP_TESTSCREEN_H_
#define _MAP_TESTSCREEN_H_

#include "cocos2d.h"
#include <map>
#include"MapInfo.h"


USING_NS_CC;


class MapTest : public cocos2d::Scene
{
	

	CC_SYNTHESIZE(Size, _visibleSize, VisibleSize);
	CC_SYNTHESIZE(Vec2, _origin, Origin);

	CC_SYNTHESIZE(TMXTiledMap*, _map, Map);
	CC_SYNTHESIZE(MapInfo, _mapInformation, MapInformation);
	public:
	//��������
	

private:

	
	//��ʼ��
	void initMapLayer();
	/*void initListener();*/
	//֡����
	void updateMap();
	//netWork
	//����
	//������
	//EventListenerTouchOneByOne* listenerTouch;
	//EventListenerKeyboard* listenerKeyBoard;
	////������¼�
	//virtual bool onTouchBegan(Touch* touch, Event* event);
	////�����¼�
	//virtual bool onPressKey(EventKeyboard::KeyCode keyCode, Event* event);
	//virtual bool onReleaseKey(EventKeyboard::KeyCode keyCode, Event* event);
	////�ж��Ƿ�һֱ����ס
	//std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	//bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	////��������
	//bool _isMouseSprite;
	//Sprite* _mouseSprite;
	//EventListenerMouse* listenerMouse;
	//virtual bool onMouseMove(Event* event);
	//void updateSkillPanel();
	//bool gameEnd();
	//void changeScene(float delta);
	//void synchronize();

	Vec2 getPositionInMap(const Vec2& mousePosition);

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(MapTest);
};

#endif 