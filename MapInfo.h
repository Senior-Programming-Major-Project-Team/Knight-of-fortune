#ifndef __MAPINFO_H__
#define __MAPINFO_H__

#include"Constant.h"
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

	//Ĭ�ϴ��ڹ��캯��
	MapInfo() = default;
	//��tiledmap��ʼ��
	MapInfo(TMXTiledMap* map);

	//ת������ϵ
	PointINT getGridPoint(const Vec2& position) const;

	//�Ƴ��ϰ���
	void removeTowerCollision(const Vec2& towerPosition);

	Vec2 getPrecisePosition(const PointINT& girdPoint) const;

	//collison���Ƿ���Ե�ס
	bool checkCollision(const Vec2& position) const;

	//���������������Ƿ���������
	bool checkBoxes(const Vec2& position) const;

};
	
#endif 