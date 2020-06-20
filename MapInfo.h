#ifndef __MAPINFO_H__
#define __MAPINFO_H__

#include "constnumber.h"
#include "cocos2d.h"
USING_NS_CC;




class MapInfo
{
private:

	CC_SYNTHESIZE(SizeINT, _mapSize, MapSize);
	SizeINT _tileSize;

	DyaDicVector _collisionBoard;

	DyaDicVector _boxesBoard;

public:

	//默认存在构造函数
	MapInfo() = default;
	//用tiledmap初始化
	MapInfo(TMXTiledMap* map);

	//转换坐标系
	PointINT getGridPoint(const Vec2& position) const;

	//移除障碍物
	void removeTowerCollision(const Vec2& towerPosition);

	Vec2 getPrecisePosition(const PointINT& girdPoint) const;

	//collison层是否可以挡住
	bool checkCollision(const Vec2& position) const;

	//箱子类里检查坐标是否是箱子类
	bool checkBoxes(const Vec2& position) const;

};
	
#endif 