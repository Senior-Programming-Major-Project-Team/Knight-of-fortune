#ifndef _GameScene_
#define _GameScene_

#include "C:\Users\Administrator\codes\MyCppGame\cocos2d\cocos\2d\CCLayer.h"
#include "cocos2d.h"
#include "Hero.h"
#include"MapInfo.h"
#include"ShowState.h"
#include"LanceGoblin.h"
#include"HandGunGoblin.h"
#include"Flower.h"
#include"constnumber.h"
#include"Pig.h"

extern Hero* HWhatHasYouChooseToBeYourHero;
class GameScene :
	public cocos2d::Scene
{
private:
   
	Hero* MyHero;
	Point BornPosition;
    /*�ú������ڹ������ͷ���*/
    void AddTransferMatriax();
	//��ʼ��
	bool initMapLayer();
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
	Vec2 RandomGeneration();
	static int RoundNumber()
	{
		int Number = 0;
		return ++Number;
	}
	std::vector<int> EnemyNumberGeneration();
	bool InitEnemy();
	Vec2 getPositionInMap(const Vec2& mousePosition);
public:
   /*��������*/
    CC_SYNTHESIZE(Size, _visibleSize, VisibleSize);
    CC_SYNTHESIZE(Vec2, _origin, Origin);

    CC_SYNTHESIZE(TMXTiledMap*, _map, Map);
    CC_SYNTHESIZE(MapInfo, _mapInformation, MapInformation);
    /**
    * ��̬����������Scene����
    */
    static cocos2d::Scene* createScene();
    /**
     * init��������ɳ�ʼ��������
     */
    virtual bool init();
    CREATE_FUNC(GameScene);
    /*�ú����ж��Ƿ���Բ�����������*/
    //bool IsCouldTransfer();
};
#endif

