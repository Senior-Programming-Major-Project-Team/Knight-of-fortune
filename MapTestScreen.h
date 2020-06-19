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
	//公开容器
	

private:

	
	//初始化
	void initMapLayer();
	/*void initListener();*/
	//帧更新
	void updateMap();
	Vec2 getPositionInMap(const Vec2& mousePosition);

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(MapTest);
	void removeBoxes(const Vec2& aPosition);

};

#endif 
